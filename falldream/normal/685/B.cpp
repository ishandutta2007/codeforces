#include<iostream>
#include<cstdio>
#include<vector>
#define MN 300000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
vector<int> v[MN+5];
int n,Q,Res[MN+5],cnt=0,size[MN+5],rt[MN+5],mx[MN+5];
struct Tree{int l,r;pair<int,int> mx;}T[MN*40+5];
int Build(int l,int r,int k,pair<int,int> v)
{
	int x=++cnt;T[x].mx=v;
	if(l!=r) 
	{
		int mid=l+r>>1;
		if(k<=mid) T[x].l=Build(l,mid,k,v);
		else T[x].r=Build(mid+1,r,k,v);
	}
	return x;
}
int Merge(int x,int y,int l,int r)
{
	if(!x||!y) return x|y;
	T[x].mx=max(T[x].mx,T[y].mx);
	if(l<r)
	{
		int mid=l+r>>1;
		T[x].l=Merge(T[x].l,T[y].l,l,mid);
		T[x].r=Merge(T[x].r,T[y].r,mid+1,r);
	}
	return x;
}
int Solve(int x,int l,int r,pair<int,int> v,int S)
{
	if(l==r) return max(v,T[x].mx).second;	
	int mid=l+r>>1;
	if(S-max(v,T[T[x].l].mx).first<=mid) return Solve(T[x].l,l,mid,v,S);
	else return Solve(T[x].r,mid+1,r,max(v,T[T[x].l].mx),S);
}
void dfs(int x)
{
	size[x]=1;
	for(int i=0;i<v[x].size();++i)	
		dfs(v[x][i]),size[x]+=size[v[x][i]],mx[x]=max(mx[x],size[v[x][i]]),rt[x]=Merge(rt[x],rt[v[x][i]],1,n);
	rt[x]=Merge(rt[x],Build(1,n,mx[x],make_pair(size[x],x)),1,n);
	Res[x]=Solve(rt[x],1,n,T[0].mx,size[x]);
}
int main()
{
	n=read();Q=read();T[0].mx=make_pair(-1e9,0);
	for(int i=2;i<=n;++i) v[read()].push_back(i);
	dfs(1);
	for(int i=1;i<=Q;++i) printf("%d\n",Res[read()]);
	return 0;
}