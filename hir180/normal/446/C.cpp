#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000001
#define mod 1000000009
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
ll f[300005],s[300005];
ll sumf[300005],sums[300005];

ll seg[(1<<20)];
ll lazy[(1<<20)];
ll lazy2[(1<<20)];
void lazy_evaluate(int k,int p)
{
	lazy[k*2+1] = (lazy[k*2+1]+lazy[k])%mod;
	lazy2[k*2+1] = (lazy2[k*2+1]+lazy2[k])%mod;
	seg[k*2+1] = (seg[k*2+1]+sumf[p-1]*lazy[k]%mod+sums[p-1]*lazy2[k]%mod)%mod;
	lazy[k*2+2] = (lazy[k*2+2] + f[p]*lazy[k]%mod + s[p]*lazy2[k]%mod)%mod;
	lazy2[k*2+2] = (lazy2[k*2+2] + f[p+1]*lazy[k]%mod + s[p+1]*lazy2[k]%mod)%mod;
	seg[k*2+2] = (seg[k*2+2]+(sumf[2*p-2]*lazy[k]+sums[2*p-2]*lazy2[k])-(sumf[p-1]*lazy[k]+sums[p-1]*lazy2[k]))%mod;
	if(seg[k*2+2] < 0) seg[k*2+2]+=mod;
	lazy[k]=0;
	lazy2[k]=0;
}
ll update(int beg,int end,int idx,int lb,int ub)
{
	if(ub<beg||end<lb)
	{
		return seg[idx];
	}
	if(beg<=lb&&ub<=end)
	{
		int st = lb-beg+1;
		lazy[idx] = (lazy[idx]+f[st]+s[st])%mod;
		lazy2[idx] = (lazy2[idx]+f[st+1]+s[st+1])%mod;
		seg[idx] = (seg[idx]+sumf[st+ub-lb]+sums[st+ub-lb]-sumf[st-1]-sums[st-1]+mod+mod)%mod;
		return seg[idx];
	}
	if(lazy[idx] || lazy2[idx])
	{
		lazy_evaluate(idx,1+(ub-lb+1)/2);
	}
	return seg[idx]=(update(beg,end,idx*2+1,lb,(lb+ub)/2)+update(beg,end,idx*2+2,(lb+ub)/2+1,ub))%mod;
}
ll query(int beg,int end,int idx,int lb,int ub)
{
	if(ub<beg||end<lb)
	{
		return 0LL;
	}
	if(beg<=lb&&ub<=end)
	{
		return seg[idx];
	}
	if(lazy[idx] || lazy2[idx])
	{
		lazy_evaluate(idx,1+(ub-lb+1)/2);
	}
	return (query(beg,end,idx*2+1,lb,(lb+ub)/2)+query(beg,end,idx*2+2,(lb+ub)/2+1,ub))%mod;
}
ll rui[300005];
int n,q;

int segg[(1<<20)]={};
void updatee(int k)
{
	k+=(1<<19)-1; segg[k]++;
	while(k>0)
	{
		k=(k-1)/2;
		segg[k]=(segg[k*2+1]+segg[k*2+2]);
	}
}
int queryy(int a,int b,int k,int l,int r)
{
	if(r<a || b<l) return 0;
	if(a<=l && r<=b) return segg[k];
	else{
		int vl=queryy(a,b,k*2+1,l,(l+r)/2);
		int vr=queryy(a,b,k*2+2,(l+r)/2+1,r);
		return (vl+vr);
	}
}
int main()
{
	f[1] = 1;
	s[2] = 1;
	for(int i=3;i<=300000;i++)
	{
		f[i] = (f[i-1]+f[i-2])%mod;
		s[i] = (s[i-1]+s[i-2])%mod;
	}
	sumf[1] = 1;
	for(int i=2;i<=300000;i++)
	{
		sumf[i] = (sumf[i-1]+f[i])%mod;
		sums[i] = (sums[i-1]+s[i])%mod;
	}
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		int x; scanf("%d",&x);
		rui[i] = (rui[i-1]+x)%mod;
	}
	for(int i=0;i<q;i++)
	{
		int t; scanf("%d",&t);
		if(t == 1)
		{
			int a,b; scanf("%d%d",&a,&b);
			if(a == b)
			{
				updatee(a);
				continue;
			}
			update(a,b,0,0,(1<<19)-1);
		}
		else
		{
			int a,b; scanf("%d%d",&a,&b);
			ll res = rui[b]-rui[a-1];
			res = (res%mod+mod)%mod;
			res = (res+queryy(a,b,0,0,(1<<19)-1))%mod;
			res = (res+query(a,b,0,0,(1<<19)-1))%mod;
			printf("%lld\n",res);
		}
	}
}