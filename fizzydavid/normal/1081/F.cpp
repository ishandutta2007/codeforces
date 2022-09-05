//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
const int mod=1e9+7;
ll qpow(ll x, ll k) {return k==0? 1: 1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
int n;
int cur, lst, dlt;
int query(int l, int r)
{
	printf("? %d %d\n", l, r);
	fflush(stdout);
	int x;
	scanf("%d", &x);
	if (x==-1) exit(0);
	lst = cur;
	cur = x;
	dlt = cur-lst;
}
void query_det(int l, int r, bool m0, bool m1)
{
	assert(r%2!=(n-l+1)%2);
	bool msk0 = 0, msk1 = 0;
	while (true)
	{
		query(l, r);
		if ((dlt-r)%2==0) msk0 ^= 1;
		else msk1 ^= 1;
		if (msk0==m0&&msk1==m1) break;
	}
}
const int maxn = 311;
int ans[maxn];
int main()
{
	cin>>n>>cur;
	if (n==1)
	{
		ans[1] = cur;
	}
	else if (n%2==0)
	{
		for (int i=1; i<=n; i++)
		{
			int d = -cur;
			query_det(i,i,1,0);
			d += cur;
			ans[i] = (i-d)/2;
			query_det(i,i,1,0);
		}
		for (int i=n; i>=2; i--) ans[i] -= ans[i-1];
	}
	else
	{
		for (int i=2; i<=n; i++)
		{
			int d = -cur;
			query_det(i-1,i,1,0);
			d += cur;
			ans[i] = (i-d)/2;
			query_det(i-1,i,1,0);
		}
		for (int i=n; i>=3; i--) ans[i] -= ans[i-1];
		int sum;
		{
			int d = -cur;
			query_det(2,3,0,1);
			d += cur;
			sum = (n-1-d)/2;
		}
		for (int i=3; i<=n; i++) sum -= ans[i];
		ans[1] = ans[2]-sum;
		ans[2] = sum;
	}
	printf("! ");
	for (int i=1; i<=n; i++) printf("%d", ans[i]);
	puts("");
	fflush(stdout);
	return 0;
}