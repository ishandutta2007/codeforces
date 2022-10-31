#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1010,NN=N*N*10,inf=100000000;
struct rec {int k,l,r,v;};
int n,vx,vy,num;
rec a[N*N];
int s[NN],tag[NN],lc[NN],rc[NN];
void add(int i,int j,int x)
{
	int k=inf,l=inf,r=-inf;
	for (int p=i-1;p<=i;p++)
	for (int q=j-1;q<=j;q++)
	{
		k=min(k,vx*p+vy*q);
		l=min(l,vy*p-vx*q);
		r=max(r,vy*p-vx*q);
	}
	a[++num]=(rec){k,l,r-1,x};
}
void change(int &i,int l,int r,int ll,int rr,int v)
{
	if (i==0) i=++num;
	if (ll<=l&&r<=rr)
	{
		s[i]=max(s[i],v);
		tag[i]=max(tag[i],v);
		return;
	}
	int mid=(l+r)>>1;
	if (ll<=mid) change(lc[i],l,mid,ll,rr,v);
	if (rr> mid) change(rc[i],mid+1,r,ll,rr,v);
	s[i]=max(tag[i],min(s[lc[i]],s[rc[i]]));
}
int  query(int i,int l,int r,int ll,int rr)
{
	if (i==0) return 0;
	if (ll<=l&&r<=rr) return s[i];
	int mid=(l+r)>>1,res=inf*20;
	if (ll<=mid) res=min(res,query(lc[i],l,mid,ll,rr));
	if (rr> mid) res=min(res,query(rc[i],mid+1,r,ll,rr));
	return max(res,tag[i]);
}
int cmp(rec a,rec b) { return a.k<b.k;}
int main()
{
	scanf("%d%d%d",&n,&vx,&vy);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	{
		int x;
		scanf("%d",&x);
		add(i,j,x);
	}
	num=0;
	sort(a+1,a+n*n+1,cmp);
	num=1;
	long long ans=0;
	int rt=1;
	for (int i=1;i<=n*n;i++)
	{
		int k=query(1,1,inf*2,a[i].l+inf,a[i].r+inf);
		ans+=max(0,a[i].v-k);
		change(rt,1,inf*2,a[i].l+inf,a[i].r+inf,a[i].v);
	}
	cout<<ans<<endl;
	return 0;
}