#include<bits/stdc++.h>
#define ll long long
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc s
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
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
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
const int xx=2e5+5;
struct nod
{
	int next,to;
}e[xx<<1];
int cnt,h[xx];
void add(int x,int y){cnt++;e[cnt]={h[x],y};h[x]=cnt;}
vector<int>v[xx];
int s,n,m,bel[xx],vis[xx],f[xx],now;
void dfs(int x,int y)
{
	f[x]=y,bel[x]=now;
	vis[x]=1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(vis[e[i].to]||e[i].to==s)continue;
		dfs(e[i].to,x);
	}
}
int main(){
	n=read(),m=read(),s=read();
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		if(b==s)continue;
		add(a,b);
		v[b].push_back(a);
	}
	for(int i=h[s];i;i=e[i].next)
	{
		if(!vis[e[i].to])
			++now,dfs(e[i].to,s);
	}
	// 
	int cr=0,X,Y;
	for(int i=1;i<=n;i++)
	{
		for(auto it:v[i])
		{
//			cerr<<i<<' '<<it<<" "<<bel[it]<<" "<<bel[i]<<"AASD\n";
			if(it==f[i])continue;
			if(it==s&&f[i]!=s)
			{
				cr=1;
				X=i,Y=s;
				break;
			}
			if(!vis[it])continue;
			if(bel[it]!=bel[i])
			{
				cr=1;
				X=i,Y=it;
				break;
			}
		}
		if(cr)break;
	}
	if(!cr)puts("Impossible");
	else 
	{
		puts("Possible");
		vector<int>ans;
		int w=X;
		while(X!=s)
			ans.push_back(X),X=f[X];
		ans.push_back(X);
		reverse(ans.begin(),ans.end());
		cout<<ans.size()<<"\n";
		for(auto it:ans)cout<<it<<" ";
		puts("");
		ans.clear();
		ans.push_back(w);
		while(Y!=s)
			ans.push_back(Y),Y=f[Y];
		ans.push_back(Y);
		reverse(ans.begin(),ans.end());
		cout<<ans.size()<<"\n";
		for(auto it:ans)cout<<it<<" ";
		puts("");
	}
	pc('1',1);
	return 0;
}