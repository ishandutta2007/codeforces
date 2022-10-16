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
const int xx=1e5+5;
int n;
struct nod{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y){cnt++,e[cnt]={h[x],y},h[x]=cnt;}
// 
namespace zxs
{
	struct nd{int l,r,mn,mx;nd(){l=r=0,mn=1e9,mx=-1e9;}}e[xx*64];
	int cst;
	void ins(int &k,int l,int r,int x,int y)
	{
		++cst,e[cst]=e[k],k=cst,e[k].mn=min(e[k].mn,y),e[k].mx=max(e[k].mx,y);
		if(l==r)return;
		int mid=l+r>>1;
		if(x<=mid)ins(e[k].l,l,mid,x,y);
		else ins(e[k].r,mid+1,r,x,y);
	}
	int ask(int k,int l,int r,int x,int y,int op)//0mn1mx
	{
		if(!k||x>y)return op==0?1e9:-1e9;
		if(x<=l&&r<=y)return op==0?e[k].mn:e[k].mx;
		int mid=l+r>>1;
		if(y<=mid)return ask(e[k].l,l,mid,x,y,op);
		if(mid<x)return ask(e[k].r,mid+1,r,x,y,op);
		return op==0?min(ask(e[k].l,l,mid,x,y,op),ask(e[k].r,mid+1,r,x,y,op)):max(ask(e[k].l,l,mid,x,y,op),ask(e[k].r,mid+1,r,x,y,op));
	}
}
int son[xx],siz[xx],dep[xx],f[xx];
void dfs(int x,int y)
{
	f[x]=y,dep[x]=dep[y]+1,siz[x]=1;
	int mx=-1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x),siz[x]+=siz[e[i].to];
		if(siz[e[i].to]>mx)mx=siz[e[i].to],son[x]=e[i].to;
	}
}
int top[xx],dfx[xx],id[xx],Cst;
void dfss(int x,int y)
{
	dfx[x]=++Cst,id[Cst]=x,top[x]=y;
	if(!son[x])return;
	dfss(son[x],y);
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==f[x]||e[i].to==son[x])continue;
		dfss(e[i].to,e[i].to);
	}
}
int ans[xx],rt1[xx],rt2[xx],I1[xx],I2[xx];
struct pr{int x,y;bool operator<(const pr&w)const{return x<w.x;};};
// 
void dp(int x,int y)
{
	for(int i=h[x];i;i=e[i].next)
		if(e[i].to!=y)dp(e[i].to,x);
	vector<int>v;
	for(int i=h[x];i;i=e[i].next)e[i].to!=y?v.push_back(siz[e[i].to]):v.push_back(n-siz[x]);
	sort(v.begin(),v.end());
	if(v.size()==1)ans[x]=*v.begin();
	else 
	{
		if(*--v.end()==*----v.end())
		{
			ans[x]=*--v.end();
			return;
		}
		ans[x]=*--v.end();
		int mn=*v.begin(),mx=*--v.end();
		int D=(mx-mn+1)/2,X=(mx-mn)/2;//D:X: 
//		if(x==1)cout<<D<<" "<<X<<"%^%\n";
		//max 
		int mid=0;
		for(int i=h[x];i;i=e[i].next)
		{
			if(e[i].to!=y)
			{
				if(siz[e[i].to]==mx)mid=e[i].to;
			}
			else 
			{
				if(n-siz[x]==mx)mid=y;
			}
		}
		vector<pr>op;
		if(mid!=y)
			op.push_back({1,dfx[mid]-1}),
			op.push_back({dfx[mid]+siz[mid],n});
		else 
		{
			// 
			// 
			op.push_back({dfx[x]+1,dfx[x]+siz[x]-1});
			int z=x;//ban 
			while(z)
			{
				op.push_back({dfx[top[z]],dfx[z]});
				z=f[top[z]];
			}
		}
		sort(op.begin(),op.end());
		int ls=0;
		siz[n+1]=X;
		int id1=upper_bound(I1+1,I1+n+1,n+1,[&](int a,int b){return siz[a]<siz[b];})-I1-1;
		siz[n+1]=D;
		int id2=upper_bound(I2+1,I2+n+1,n+1,[&](int a,int b){return siz[a]>siz[b];})-I2-1;
		int Mx=-1e9,Mn=1e9;
		for(auto it:op)
		{
			Mx=max(Mx,zxs::ask(rt1[id1],1,n,ls+1,it.x-1,1));
			Mn=min(Mn,zxs::ask(rt2[id2],1,n,ls+1,it.x-1,0));
			ls=it.y;
		}
		Mx=max(Mx,zxs::ask(rt1[id1],1,n,ls+1,n,1));
		Mn=min(Mn,zxs::ask(rt2[id2],1,n,ls+1,n,0));
		if(mid==y)
		{
			siz[n+1]=X+siz[x];
			int id1=upper_bound(I1+1,I1+n+1,n+1,[&](int a,int b){return siz[a]<siz[b];})-I1-1;
			siz[n+1]=D+siz[x];
			int id2=upper_bound(I2+1,I2+n+1,n+1,[&](int a,int b){return siz[a]>siz[b];})-I2-1;
			int z=x;//ban 
			while(z)
			{
				Mx=max(Mx,zxs::ask(rt1[id1],1,n,dfx[top[z]],dfx[z],1)-siz[x]);
				Mn=min(Mn,zxs::ask(rt2[id2],1,n,dfx[top[z]],dfx[z],0)-siz[x]);
				z=f[top[z]];
			}
		}
//		if(x==1)
//		{
//			cout<<Mn<<" "<<Mx<<" "<<id1<<" "<<id2<<"%^%^\n";
//		for(auto it:op)cout<<it.x<<" "<<it.y<<"%^%\n";
//		}
		ans[x]=min(ans[x],max(mx-Mx,mn+Mx));
		ans[x]=min(ans[x],max(mx-Mn,mn+Mn));
		ans[x]=max(ans[x],*----v.end());
	}
}
int rt;
signed main(){
//	cout<<sizeof(E)/1024/1024<<"\n";
	n=read();
	if(n==1)puts("0"),exit(0);
	for(int i=1;i<=n;i++)
	{
		int a=read(),b=read();
		if(!a)rt=b;
		else add(a,b),add(b,a);
	}
	dfs(rt,0),dfss(rt,rt);
	for(int i=1;i<=n;i++)I1[i]=i,I2[i]=i;
	sort(I1+1,I1+n+1,[&](int a,int b){return siz[a]<siz[b];});
	sort(I2+1,I2+n+1,[&](int a,int b){return siz[a]>siz[b];});
	for(int i=1;i<=n;i++)
	{
		rt1[i]=rt1[i-1],rt2[i]=rt2[i-1];
		zxs::ins(rt1[i],1,n,dfx[I1[i]],siz[I1[i]]);
		zxs::ins(rt2[i],1,n,dfx[I2[i]],siz[I2[i]]);
	}
//	puts("ASD");
	dp(rt,0);
	for(int i=1;i<=n;i++)cout<<ans[i]<<"\n";
	pc('1',1);
	return 0;
}
//void merge(set<int>&a,set<int>&b)//ba 
//{
//	if(a.size()<b.size())swap(a,b);
//	for(auto t:)
//}