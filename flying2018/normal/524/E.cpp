#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 200010
using namespace std;
struct node{
	int x,y;
	bool operator <(const node a)const{return y==a.y?x<a.x:y<a.y;}
}a[N];
bool can[N];
struct sq{
	int xl,xr,yl,yr,id;
	bool operator <(const sq a)const{return yr==a.yr?yl<a.yl:yr<a.yr;}
}s[N];
int val[N<<2];
void insert(int u,int l,int r,int p,int v)
{
	if(l==r){val[u]=v;return;}
	int mid=(l+r)>>1;
	if(p<=mid) insert(u<<1,l,mid,p,v);
	else insert(u<<1|1,mid+1,r,p,v);
	val[u]=min(val[u<<1],val[u<<1|1]);
}
int answer(int u,int l,int r,int L,int R)
{
	if(R<L || R<l || r<L) return 10000000;
	if(L<=l && r<=R) return val[u];
	int mid=(l+r)>>1;
	return min(answer(u<<1,l,mid,L,R),answer(u<<1|1,mid+1,r,L,R));
}
void work(int n,int m,int k,int q)
{
	sort(a+1,a+k+1);
	sort(s+1,s+q+1);
	memset(val,0,sizeof(val));
	int u=1,v=1;
	for(int i=1;i<=m;i++)
	{
		for(;u<=k && a[u].y==i;u++) insert(1,1,n,a[u].x,a[u].y);
		for(;v<=q && s[v].yr==i;v++)
		can[s[v].id]|=(answer(1,1,n,s[v].xl,s[v].xr)>=s[v].yl);
	}
}
int main()
{
	int n,m,k,q;
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for(int i=1;i<=k;i++) scanf("%d%d",&a[i].x,&a[i].y);
	for(int i=1;i<=q;i++) scanf("%d%d%d%d",&s[i].xl,&s[i].yl,&s[i].xr,&s[i].yr),s[i].id=i;
	work(n,m,k,q);
	for(int i=1;i<=k;i++) swap(a[i].x,a[i].y);
	for(int i=1;i<=q;i++) swap(s[i].xl,s[i].yl),swap(s[i].xr,s[i].yr);
	work(m,n,k,q);
	for(int i=1;i<=q;i++) puts(can[i]?"YES":"NO");
	return 0;
}