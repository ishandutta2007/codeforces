#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector> 
#define MD 17 
#define MN 100000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,head[MN+5],cnt=0,f[MD+1][MN+5],dfn[MN+5],dn=0,dep[MN+5];
int flag,mark[MN+5],s[MN+5],q[MN+5],top,b[MN+5],bn=0,F[MN+5],G[MN+5];
struct edge{int to,next;}e[MN*2+5];
vector<int> v[MN+5];
inline void Ins(int f,int t){v[f].push_back(t);}
inline void ins(int f,int t)
{
	e[++cnt]=(edge){t,head[f]};head[f]=cnt;
	e[++cnt]=(edge){f,head[t]};head[t]=cnt;	
}
void Pre(int x,int fa)
{
	dfn[x]=++dn;f[0][x]=fa;
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=fa) dep[e[i].to]=dep[x]+1,Pre(e[i].to,x);	
}
int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int k=dep[x]-dep[y],j=0;k;k>>=1,++j) if(k&1) x=f[j][x];
	if(x==y) return x;
	for(int i=MD;~i;--i) if(f[i][x]!=f[i][y]) x=f[i][x],y=f[i][y];
	return f[0][x];	
}
bool cmp(int x,int y){return dfn[x]<dfn[y];}
void Build(int n)
{
	sort(s+1,s+n+1,cmp);
	q[top=1]=s[1];	
	for(int i=2;i<=n;++i)
	{
		if(top)
		{
		//	cout<<q[top]<<" "<<s[i]<<" "<<lca(q[top],s[i]);
			int x=lca(q[top],s[i]);
			while(top>1&&dep[x]<=dep[q[top-1]]) Ins(q[top-1],q[top]),--top;
			if(dep[q[top]]>dep[x]) Ins(x,q[top]),q[top]=x;
		}
		q[++top]=s[i];	
	}
	for(;top>1;--top) Ins(q[top-1],q[top]);
}

void Dp(int x)
{
//	cout<<"Dp"<<x<<endl;
	F[x]=G[x]=0;b[++bn]=x;int nx=0;
	for(int i=0;i<v[x].size();++i)
	{
		if(mark[x]&&mark[v[x][i]]&&dep[v[x][i]]==dep[x]+1) flag=0;
		Dp(v[x][i]);nx+=min(F[v[x][i]],G[v[x][i]]);
		F[x]=min(F[x]+min(F[v[x][i]],G[v[x][i]])+1,min(G[x]+F[v[x][i]],F[x]+G[v[x][i]])); 
		G[x]+=min(F[v[x][i]]+1,G[v[x][i]]);
	}
	if(mark[x]) F[x]=G[x],G[x]=1e9;
	else G[x]=min(G[x],nx+1);
//	cout<<x<<" "<<F[x]<<" "<<G[x]<<endl;
}

int main()
{
	n=read();
	for(int i=1;i<n;++i) ins(read(),read());
	m=read();Pre(1,0);
	for(int i=1;i<=MD;++i) for(int j=1;j<=n;++j) f[i][j]=f[i-1][f[i-1][j]];
	for(int i=1;i<=m;++i)
	{
		int k=read();bn=0;flag=1;
		for(int j=1;j<=k;++j) mark[s[j]=read()]=1;
		if(!mark[1]) s[++k]=1;
		Build(k);Dp(1);
		printf("%d\n",flag?min(F[1],G[1]):-1);
		for(int j=1;j<=bn;++j) mark[b[j]]=0,v[b[j]].clear();
	}
	return 0;
}