#include<bits/stdc++.h>
#define ll long long
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc(x%10+'0',0);
}
void wts(int x,char op)
{
	if(x<0)x=-x,pc('-',0);
	wt(x),pc(op,0);
}
const int xx=3e5+5;
//01 
int n,m,ty[xx],op[xx],ans[xx],u[xx][2],val[xx],ct[xx];
struct nod{int t,id;bool operator<(const nod&w)const{return t==w.t?id<w.id:t<w.t;};};
multiset<nod>s[xx];
int vis[xx];
void dfs(int x)
{
	if(vis[x])return;
	vis[x]=1;
	for(auto it:s[x])
	{
		int cr=u[it.id][1]==x;
		if(!vis[u[it.id][!cr]])
			dfs(u[it.id][!cr]),ans[it.id]=cr;
	}
}
signed main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read(),c=read();
		ct[a]+=c,ct[b]+=c;
		s[a].insert({c,i}),s[b].insert({c,i});
		u[i][0]=a,u[i][1]=b;
	}
	int res=0;
	for(int i=1;i<=n;i++)res+=(ct[i]&1);
	int tt=m; 
	// 
	for(int i=1;i<=n;i++)
	{
		while(s[i].size()>=2&&s[i].begin()->t==(++s[i].begin())->t)
		{
			int idl=s[i].begin()->id,idr=(++s[i].begin())->id,w=s[i].begin()->t;
			int Ol=u[idl][1]==i,Or=u[idr][1]==i;
			++tt,u[tt][0]=u[idl][!Ol],u[tt][1]=u[idr][!Or];
			//op 
			ty[idl]=ty[idr]=tt,op[idl]=!Ol,op[idr]=Or;
			s[i].erase(s[i].find({w,idl}));
			s[i].erase(s[i].find({w,idr}));
			s[u[idl][!Ol]].erase(s[u[idl][!Ol]].find({w,idl}));
			s[u[idr][!Or]].erase(s[u[idr][!Or]].find({w,idr}));
//		cout<<i<<" "<<s[i].size()<<" "<<idl<<" "<<idr<<" "<<u[idl][!Ol]<<" "<<u[idr][!Or]<<" "<<s[u[idl][!Ol]].size()<<"ASD\n";
			if(u[tt][0]==u[tt][1])
				ans[tt]=0;
			else 
			{
				s[u[idl][!Ol]].insert({w,tt});
				s[u[idr][!Or]].insert({w,tt});
			}
		}
//		cout<<i<<" "<<s[i].size()<<"\n";
		while(s[i].size()>=2&&(--s[i].end())->t==(----s[i].end())->t)
		{
			int idl=(--s[i].end())->id,idr=(----s[i].end())->id,w=(--s[i].end())->t;
			int Ol=u[idl][1]==i,Or=u[idr][1]==i;
			++tt,u[tt][0]=u[idl][!Ol],u[tt][1]=u[idr][!Or];
			//op 
			ty[idl]=ty[idr]=tt,op[idl]=!Ol,op[idr]=Or;
			s[i].erase(s[i].find({w,idl}));
			s[i].erase(s[i].find({w,idr}));
			s[u[idl][!Ol]].erase(s[u[idl][!Ol]].find({w,idl}));
			s[u[idr][!Or]].erase(s[u[idr][!Or]].find({w,idr}));
			if(u[tt][0]==u[tt][1])
				ans[tt]=0;
			else 
			{
				s[u[idl][!Ol]].insert({w,tt});
				s[u[idr][!Or]].insert({w,tt});
			}
		}
	}
//	puts("ASd");
	for(int i=1;i<=n;i++)
	{
		if(!s[i].size())vis[i]=1;
		if(vis[i])continue;
		if(s[i].size()==1)dfs(i);
	}
	for(int i=1;i<=n;i++)
	{
		if(!s[i].size())vis[i]=1;
		if(vis[i])continue;
		if(s[i].size()==2)dfs(i);
	}
	for(int i=tt;i>=1;i--)
		if(ty[i])ans[i]=ans[ty[i]]^op[i];
	cout<<res<<"\n";
	for(int i=1;i<=m;i++)cout<<ans[i]+1;
	pc('1',1);
	return 0;
}