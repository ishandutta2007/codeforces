#include<cstdio>
#include<iostream>
using namespace std;
const int N=200010,M=N*19;
int n,q,num;
long long ans;
int T[N];
int lc[M],rc[M],s[M];
int change(int j,int l,int r,int k)
{
	int i=++num,mid=(l+r)/2;
	lc[i]=lc[j];rc[i]=rc[j];s[i]=s[j]+1;
	if (l==r) return i;
	if (k<=mid) lc[i]=change(lc[j],l,mid,k);
	if (k> mid) rc[i]=change(rc[j],mid+1,r,k);
	return i;
}
int query(int i,int l,int r,int ll,int rr)
{
	if (i==0) return 0;
	if (ll<=l&&r<=rr) return s[i];
	int mid=(l+r)/2,res=0;
	if (ll<=mid) res+=query(lc[i],l,mid,ll,rr);
	if (rr> mid) res+=query(rc[i],mid+1,r,ll,rr);
	return res;
}
int main()
{
	scanf("%d%d",&n,&q);
	num=0;
	for (int i=1;i<=n;i++)
	{
		int x;scanf("%d",&x);
		T[i]=change(T[i-1],1,n,x);
	}
	while (q--)
	{
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		int k1=query(T[x1-1],1,n,1,y1-1);
		int k2=query(T[x1-1],1,n,1,y2)-k1;
		int k3=x1-1-k1-k2;
		int k4=query(T[x2],1,n,1,y1-1)-k1;
		int k5=query(T[x2],1,n,y1,y2)-k2;
		int k6=x2-x1+1-k4-k5;
		int k7=y1-1-k1-k4;
		int k8=y2-y1+1-k2-k5;
		int k9=n-x2-k7-k8;
		ans=0;
		ans+=1LL*k1*(k5+k6+k8+k9);
		ans+=1LL*k2*(n-x1+1);
		ans+=1LL*k3*(k4+k5+k7+k8);
		ans+=1LL*k4*(n-y1+1);
		ans+=1LL*k5*n-k5;
		ans+=1LL*k6*y2;
		ans+=1LL*k7*(k2+k3+k5+k6);
		ans+=1LL*k8*x2;
		ans+=1LL*k9*(k1+k2+k4+k5);
		ans/=2;
		printf("%lld\n",ans);
	}
	return 0;
}