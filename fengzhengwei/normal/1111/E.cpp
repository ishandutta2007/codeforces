#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,q;
const int xx=1e5+5;
struct node
{
	int next,to;
}e[xx<<1];
int cnt;
int h[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
int f[xx],dep[xx],top[xx],size[xx],son[xx],dfx[xx],cst;
void dfs(int x,int y)
{
	f[x]=y;dep[x]=dep[y]+1,size[x]=1;
	int maxx=-1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
		size[x]+=size[e[i].to];
		if(maxx<size[e[i].to])maxx=size[e[i].to],son[x]=e[i].to;
	}
//	cout<<x<<" "<<son[x]<<"\n";
}
int sum[xx];
int lb(int x){return x&(-x);}
void ad(int x,int y){for(;x<=n;x+=lb(x))sum[x]+=y;}
int ask(int x){int ans=0;for(;x;x-=lb(x))ans+=sum[x];return ans;}
void dfss(int x,int y)
{
//	cout<<x<<"\n";
	dfx[x]=++cst;
	top[x]=y;
	if(!son[x])return;
	dfss(son[x],y);
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==f[x]||e[i].to==son[x])continue;
		dfss(e[i].to,e[i].to);
	}
}
int lca(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=f[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}
const int mod=1e9+7;
vector<int>v;
int F[xx][301],S[xx];
int dis(int x,int y){return ask(dfx[x])+ask(dfx[y])-ask(dfx[lca(x,y)])-ask(dfx[f[lca(x,y)]]);}
bool cmp(int x,int y){return S[x]<S[y];}
signed main(){
	n=read();
	q=read();
	for(int i=1;i<n;i++)
	{
		int a,b;
		a=read();
		b=read();
		add(a,b);
		add(b,a);
	}
	dfs(1,0);
	dfss(1,1);
	while(q--)
	{
		int k,m,r;
		k=read();
		m=read();
		r=read();
		v.clear();
		for(int i=1;i<=k;i++)v.push_back(read());
		for(int i=0;i<k;i++)
		{
			ad(dfx[v[i]],1);
			ad(dfx[v[i]]+size[v[i]],-1);
		}
		for(int i=0;i<k;i++)S[v[i]]=dis(v[i],r)-1;
//		return 0
		sort(v.begin(),v.end(),cmp);
		F[1][1]=1;
		for(int i=2;i<=k;i++)
		{
			int w=dis(v[i-1],r)-1;
			for(int j=1;j<=min(i,m);j++)F[i][j]=0;
			for(int j=1;j<=min(i,m);j++)
			{
				if(j>=w)F[i][j]+=F[i-1][j-1]+1ll*(j-w)*F[i-1][j]%mod;
				F[i][j]%=mod;
//				cout<<i<<" "<<j<<" "<<F[i][j]<<" "<<w<<"\n";
			}
		}
		int ans=0;
		for(int i=1;i<=m;i++)ans+=F[k][i],ans%=mod;
		for(int i=0;i<k;i++)
		{
			ad(dfx[v[i]],-1);
			ad(dfx[v[i]]+size[v[i]],1);
		}
		cout<<ans<<"\n";
	}
	return 0;
}