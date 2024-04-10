#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int mod = 998244353;

inline int get_res(int a[],int n,ll lim)
{
	if(!n) return 1;
	
	int res = 1;
	vector<ll> b[2];
	static int pos[MAXN];
	b[0] = b[1] = vector<ll>(1);
	for(int i=1; i<=n; ++i)
		b[i&1].push_back(a[i]), pos[i] = (int)b[i&1].size() - 1;
	for(int i=0; i<=1; ++i)
		for(int j=1; j<(int)b[i].size(); ++j)
			b[i][j] += b[i][j-1];
	
	for(int i=1; i<=n; ++i)
	{
		ll cur = b[i&1][pos[i]];
		if(cur > lim) continue;
		int ni = !(i & 1);
		int cnt = upper_bound(b[ni].begin(), b[ni].begin() + pos[i-1] + 1, lim - cur) - b[ni].begin();
		res = (res + cnt) %mod;
	}
	
	return res;
}

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	ll tot = 0;
	for(int i=1; i<=n; ++i) tot += a[i];
	
	int ans = 0;
	ll sum = a[n];
	for(int i=n-1; i>2; --i)
	{
		sum += a[i];
		if(sum < (tot - sum)) ++ans;
		else break;
	}
	
	for(int i=0; i<=1; ++i)
		for(int j=0; j<=1; ++j)
		{
			if(n < 3 && (i || j)) continue;
			int l = 1, r = n;
			ll x = 0;
			if(i)
			{
				l += 3;
				x += a[2] + a[3];
			}
			if(j)
			{
				r -= 3;
				x += a[n];
			}
			if(r - l + 1 < 0) continue;
			
			ll cur = tot - x - x;
			if(cur < 0) continue;
			cur = (cur + 1) / 2;
			if(!cur) continue;
			
//			printf("%d %d: %d\n",i,j,get_res(a+l-1,r-l+1,cur-1));
			ans = (ans + get_res(a+l-1, r-l+1, cur - 1)) %mod;
		}
	
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}