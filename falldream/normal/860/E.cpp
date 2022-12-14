#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#define MD 19
#define MN 500000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,head[MN+5],dep[MN+5],cnt=0,rt,fa[MD+1][MN+5],dfn[MN+5],dn,size[MN+5],q[MN+5],top,dd=0,b[MN+5];
struct edge{int to,next;}e[MN*2+5];
inline void ins(int f,int t){e[++cnt]=(edge){t,head[f]};head[f]=cnt;}
vector<int> v[MN+5];long long Ans[MN+5];

int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int k=dep[x]-dep[y],j=0;k;k>>=1,++j) if(k&1) x=fa[j][x];
	if(x==y) return x;
	for(int i=MD;~i;--i) if(fa[i][x]!=fa[i][y]) x=fa[i][x],y=fa[i][y];
	return fa[0][x];	
}

void Pre(int x)
{
	v[dep[x]].push_back(x);dfn[x]=++dn;
	for(int i=head[x];i;i=e[i].next)
		dep[e[i].to]=dep[x]+1,Pre(e[i].to); 
}
bool cmp(int x,int y){return dfn[x]<dfn[y];}
void Build(vector<int>&v,int d)
{
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();++i) Ans[v[i]]=Ans[fa[0][v[i]]]+dep[v[i]]-1;
	cnt=dd=0;q[top=1]=rt;head[rt]=size[rt]=0;
	for(int i=0+(v[0]==rt);i<v.size();++i)
	{
		int x=lca(q[top],v[i]);
		if(x!=q[top]) 
		{
			while(top>1&&dep[q[top-1]]>=dep[x]) ins(q[top-1],q[top]),--top;
			if(q[top]!=x) ins(x,q[top]),q[top]=x;
		}
		q[++top]=v[i];	
	}
	for(;top>1;--top) ins(q[top-1],q[top]);
} 

void Dfs(int x)
{
	if(!head[x]) size[x]=1;b[++dd]=x;
	for(int i=head[x];i;i=e[i].next)	
		Dfs(e[i].to),size[x]+=size[e[i].to];
}

void Solve(int x,long long t)
{
	for(int i=head[x];i;i=e[i].next)
		Solve(e[i].to,t+1LL*(size[x]-size[e[i].to])*dep[x]);
	if(!head[x]) Ans[x]+=t;
}
void Clear(){for(int i=1;i<=dd;++i) head[b[i]]=size[b[i]]=0;}
int main()
{
	n=read();	
	for(int i=1,j;i<=n;++i) if(!(j=read())) rt=i; else ins(fa[0][i]=j,i);
	dep[rt]=1;Pre(rt);memset(head,0,sizeof(head));
	for(int i=1;i<=MD;++i)for(int j=1;j<=n;++j)fa[i][j]=fa[i-1][fa[i-1][j]];
	for(int i=1;v[i].size();++i) Build(v[i],i),Dfs(rt),Solve(rt,0),Clear();
	for(int i=1;i<=n;++i) printf("%lld ",Ans[i]);
	return 0;
}