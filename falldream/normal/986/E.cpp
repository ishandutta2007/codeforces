#include<bits/stdc++.h>
#define MD 16
#define MN 100000
#define mod 1000000007
#define MX 10000000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
bool b[MX+5];
vector<pair<int,pair<int,int> > >v[MN+5];
int n,m,last[MX+5],s[MX/5],num,a[MN+5],head[MN+5],cnt;
int fa[MD+1][MN+5],dep[MN+5],f[MX+5],Ans[MN+5];
struct edge{int to,next;}e[MN*2+5];
struct eve{int a,b,c;}q[MN*30+5];
inline int pow(int x,int k)
{
	int res=1;
	for(;k;k>>=1,x=1LL*x*x%mod) if(k&1) res=1LL*res*x%mod;
	return res;
}
inline void ins(int f,int t)
{
	e[++cnt]=(edge){t,head[f]};head[f]=cnt;
	e[++cnt]=(edge){f,head[t]};head[t]=cnt;	
}
void dfs(int x,int f)
{
	fa[0][x]=f;
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=f) dep[e[i].to]=dep[x]+1,dfs(e[i].to,x);
}
inline int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int k=dep[x]-dep[y],j=0;k;k>>=1,++j) if(k&1) x=fa[j][x];
	if(x==y)return x;
	for(int i=MD;~i;--i) if(fa[i][x]!=fa[i][y]) x=fa[i][x],y=fa[i][y];
	return fa[0][x];	
}
void Solve(int x,int fa)
{	
	for(int t=a[x];t>1;)
		for(int p=last[t],y=1;t%p==0;t/=p) ++f[y*=p];
	for(int j=0;j<v[x].size();++j)
		q[v[x][j].first].c+=v[x][j].second.second*f[v[x][j].second.first];
	for(int i=head[x];i;i=e[i].next) if(e[i].to!=fa) Solve(e[i].to,x);	
	for(int t=a[x];t>1;)
		for(int p=last[t],y=1;t%p==0;t/=p) --f[y*=p];
}
int main()
{
	n=read();
	for(int i=1;i<n;++i) ins(read(),read());
	for(int i=1;i<=n;++i) a[i]=read();
	for(int j=2;j<=MX;++j)
	{
		if(!b[j]) s[++num]=j,last[j]=j;
		for(int i=1;s[i]*j<=MX;++i)
		{
			b[s[i]*j]=1;last[s[i]*j]=s[i];
			if(j%s[i]==0) break;
		}
	}
	dfs(1,0);cnt=0;
	for(int i=1;i<=MD;++i)for(int j=1;j<=n;++j)fa[i][j]=fa[i-1][fa[i-1][j]];
	m=read();
	for(int i=1;i<=m;++i)
	{
		int a=read(),b=read(),c=lca(a,b),x=read();Ans[i]=1;
		while(x>1)
		{
			int p=last[x],y=1;q[++cnt]=(eve){i,p,0};
			while(x%p==0)
			{
				x/=p;y*=p;
				v[a].push_back(make_pair(cnt,make_pair(y,1)));
				v[b].push_back(make_pair(cnt,make_pair(y,1)));
				v[c].push_back(make_pair(cnt,make_pair(y,-1)));
				if(c>1) v[fa[0][c]].push_back(make_pair(cnt,make_pair(y,-1)));
			}
		}
	}
	Solve(1,0);
	for(int i=1;i<=cnt;++i) Ans[q[i].a]=1LL*Ans[q[i].a]*pow(q[i].b,q[i].c)%mod;
	for(int i=1;i<=m;++i) printf("%d\n",Ans[i]);
	return 0;
}