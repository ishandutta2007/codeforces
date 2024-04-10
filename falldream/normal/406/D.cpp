#include<iostream>
#include<cstdio>
#define pa pair<int,ll>
#define ll long long
#define MD 17
#define MN 100000
using namespace std;
inline ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
pa s[MN+5];
int n,q[MN+5],top,fa[MD+1][MN+5],dep[MN+5];
ll Calc(pa a,pa b,pa c){return 1LL*(b.first-c.first)*(a.second-c.second)-1LL*(a.first-c.first)*(b.second-c.second);}
int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int k=dep[x]-dep[y],j=0;k;k>>=1,++j) if(k&1) x=fa[j][x];
	if(x==y) return x;
	for(int i=MD;~i;--i) if(fa[i][x]!=fa[i][y]) x=fa[i][x],y=fa[i][y];
	return fa[0][x];	
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i) s[i].first=read(),s[i].second=read();
	q[top=1]=n;
	for(int i=n-1;i;--i)
	{
		for(;top>1&&Calc(s[i],s[q[top]],s[q[top-1]])<0;--top);
		dep[i]=dep[q[top]]+1;fa[0][i]=q[top];q[++top]=i;
	}	
	for(int i=1;i<=MD;++i)for(int j=1;j<=n;++j)fa[i][j]=fa[i-1][fa[i-1][j]];
	for(int Q=read();Q;--Q) printf("%d ",lca(read(),read()));
	return 0;
}