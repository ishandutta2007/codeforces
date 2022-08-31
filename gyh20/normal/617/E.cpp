#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 5000005
#define int long long
using namespace std;
int n,m,k,clb,fz,fm,len,col[N],cnt[N],ans[N];
struct que{
	int l,r,id;
	bool operator<(que&b)
	{
		return l/clb==b.l/clb?r<b.r:l<b.l;
	}
}q[N];
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
signed main()
{
	int l=1,r=0,g;
	scanf("%lld%lld%lld",&n,&m,&k);
	clb=n/sqrt(m);
if(clb<1)clb=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&col[i]);
		col[i]^=col[i-1];
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld",&q[i].l,&q[i].r);
		q[i].id=i;
		q[i].l--;
	}
	sort(q+1,q+m+1);
	int ans1=0;
	for(int i=1;i<=m;i++)
	{
		while(l>q[i].l)l--,ans1+=cnt[col[l]^k],cnt[col[l]]++;
		while(r<q[i].r)r++,ans1+=cnt[col[r]^k],cnt[col[r]]++;
		while(l<q[i].l)cnt[col[l]]--,ans1-=cnt[col[l]^k],l++;
		while(r>q[i].r)cnt[col[r]]--,ans1-=cnt[col[r]^k],r--;
		ans[q[i].id]=ans1;
	}
	for(int i=1;i<=m;i++)
	{
		printf("%lld\n",ans[i]);
	}
	return 0;
}