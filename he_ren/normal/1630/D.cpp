#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int gcd(int a,int b){ return b? gcd(b,a%b): a;}

int a[MAXN];

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	int d = 0;
	for(int i=1; i<=m; ++i)
	{
		int x;
		scanf("%d",&x);
		d = gcd(d, x);
	}
	
	auto get = [&] (int k)
	{
		vector<ll> dp = {a[k], -a[k]};
		for(int i=k+d; i<=n; i+=d)
		{
			vector<ll> nxt(2, -linf);
			for(int x=0; x<=1; ++x)
				for(int y=0; y<=1; ++y)
					nxt[x^y] = max(nxt[x^y], dp[x] + (y? -a[i]: a[i]));
			swap(dp, nxt);
		}
		return dp;
	};
	
	vector<ll> res(2);
	for(int i=1; i<=d; ++i)
	{
		auto cur = get(i);
		res[0] += cur[0]; res[1] += cur[1];
	}
	printf("%lld\n",max(res[0], res[1]));
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}