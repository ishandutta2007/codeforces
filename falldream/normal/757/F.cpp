#include<bits/stdc++.h>
#define MD 18
#define MN 200000 
#define ll long long
#define pa pair<ll,int>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
vector<int> v[MN+5];
priority_queue<pa,vector<pa>,greater<pa> >q;
ll d[MN+5];
int n,m,S,head[MN+5],cnt,Q[MN+5],top,in[MN+5],fa[MD+1][MN+5],dep[MN+5],size[MN+5],ans;
struct edge{int to,next,w;}e[MN*3+5];
inline void ins(int f,int t,int w)
{
	e[++cnt]=(edge){t,head[f],w};head[f]=cnt;
	e[++cnt]=(edge){f,head[t],w};head[t]=cnt;	
}
void Dij()
{
	memset(d,63,sizeof(d));q.push(make_pair(d[S]=0,S));
	while(!q.empty())
	{
		int x=q.top().second;q.pop();
		for(int i=head[x];i;i=e[i].next)
			if(d[x]+e[i].w<d[e[i].to])
				q.push(make_pair(d[e[i].to]=d[x]+e[i].w,e[i].to));
		while(!q.empty()&&d[q.top().second]!=q.top().first) q.pop();
	}
}
inline int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int k=dep[x]-dep[y],j=0;k;k>>=1,++j) if(k&1) x=fa[j][x];
	if(x==y) return x;
	for(int i=MD;~i;--i) if(fa[i][x]!=fa[i][y]) x=fa[i][x],y=fa[i][y];
	return fa[0][x];
}
void dfs(int x)
{
	size[x]=1;
	for(int i=0;i<v[x].size();++i)
		dfs(v[x][i]),size[x]+=size[v[x][i]];
	if(x!=S) ans=max(ans,size[x]);	
}
int main()
{
	n=read();m=read();S=read();
	for(int i=1,j,k;i<=m;++i) j=read(),k=read(),ins(j,k,read());
	Dij();Q[top=1]=S;
	for(int i=1;i<=n;++i) for(int j=head[i];j;j=e[j].next)
		if(d[i]+e[j].w==d[e[j].to]) ++in[e[j].to];
	for(int i=1;i<=top;++i)
	{
		for(int j=head[Q[i]];j;j=e[j].next)
		{
			if(d[Q[i]]+e[j].w==d[e[j].to]&&!--in[e[j].to])
				Q[++top]=e[j].to;
			else if(d[e[j].to]+e[j].w==d[Q[i]])
			{
				if(!fa[0][Q[i]]) fa[0][Q[i]]=e[j].to;
				else fa[0][Q[i]]=lca(fa[0][Q[i]],e[j].to);	
			}
		}
		dep[Q[i]]=dep[fa[0][Q[i]]]+1;v[fa[0][Q[i]]].push_back(Q[i]);
		for(int j=1;j<=MD;++j) fa[j][Q[i]]=fa[j-1][fa[j-1][Q[i]]];
	}
	dfs(S);cout<<ans;
	return 0;
}