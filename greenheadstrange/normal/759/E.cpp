#include <bits/stdc++.h>
#define ll long long
#define maxn 300005 /*rem*/
#define mod 1000000007
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
vector<ll> r;
int base = 1000000000;
int dv(int k) { // 
	if (k == 1) return 0;
	int res = 0;
	for (int i = r.size() - 1; i >= 0; i--) {
		if (r[i] % k) {
			if (i == 0) res = r[i] % k;
			else r[i - 1] += r[i] % k * base;
		}
		r[i] /= k;
	}
	while (r.size() > 1 && r[r.size() - 1] == 0) r.resize(r.size() - 1);
	return res;
}
ll c[maxn];
int a[maxn], b[maxn];
int n;
ll bg(ll gg, ll md) {
	return (md - gg % md) % md;
}
vector<ll> dp[maxn];
ll lb[maxn], rb[maxn];
char inp[maxn];
int main() {
	const int test = 0;
	if (test) n = 300000;
	else cin >> n;
	for (int i = 1; i <= n - 1; i++)
		if (test) {
    		if (i % 20) a[i] = 1;
		    else a[i] = 2;
		    
		}
		
		else scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		if (test) if (i <= 20) b[i] = 15000;
		    else b[i] = 0;
		else scanf("%d", &b[i]);
	if (!test) {
		scanf("%s", inp);
		int l = strlen(inp);
		for (int j = l - 1; j >= 0; ) {
			int k = max(0, j - 8);
			int cur = 0;
			for (int m = k; m <= j; m++)
				cur = cur * 10 + inp[m] - '0';
			r.pb(cur);
			j = k - 1;
		}
	//	for (auto v : r) cout << v << ' ' << endl;
	}
	else {
		r.resize(50);
		for (int i = 0; i < r.size(); i++)
			r[i] = (rand() * 32768 + rand()) % base;
	}
	for (int i = 1; i <= n; i++) {
		if (i != n)
			c[i] = dv(a[i]);
		else {
			if (r.size() >= 3) {
				cout << 0 << endl;
				return 0;
			}
			for (int j = r.size() - 1; j >= 0; j--)
				c[n] = c[n] * base + r[j];
		}
	}
	//cout << "AF" << endl;
	lb[1] = rb[1] = 0;
	for (int i = 1; i <= n; i++) {	
	//	cout << i << ' ' << rb[i] << ' ' << lb[i] << endl;
		if (i == n) continue;	
	
		ll gg = lb[i] - c[i], md = a[i];
		lb[i + 1] = (bg(gg, md) + gg) / md;
		rb[i + 1] = (rb[i] - c[i] + b[i]) / a[i]; 
	//	cout << i << ' ' << rb[i] << ' ' << lb[i] << endl;
	}
	for (int i = n; i >= 1; i--) {
	//	cout << "!!!" << i << endl;
		dp[i].resize(rb[i] - lb[i] + 1);
		for (int j = 0; j < dp[i].size(); j++) {
			ll cur = lb[i] + j;
			if (i == n) {
				cur = c[i] - cur;
				if (cur >= 0 && cur <= b[i]) dp[i][j] = 1;
				else dp[i][j] = 0;
			//	cout << i << ' ' << j << ' ' << dp[i][j] << ' ' << c[i] << endl;
				continue;
			}
			ll gg = cur - c[i], md = a[i];
			if (bg(gg, md) > b[i]) {
				dp[i][j] = 0;
				continue;
			}
		
			ll u = (bg(gg, md) + gg) / md;
			ll rs = (b[i] - bg(gg, md)) / md + u;	
		//	cout << i << ' ' << j << ' ' << u << ' ' << rs << ' ' << endl;
			dp[i][j] = dp[i + 1][rs];
			if (u) dp[i][j] -= dp[i + 1][u - 1];
		}
		for (int j = 1; j < dp[i].size(); j++) 
			dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
	}
	ll ans = dp[1][0];
	ans %= mod;
	if (ans < 0) ans += mod;
	cout << ans << endl;	
	return 0;
}
/*
5 3
2
1 3
2 3
1
1 3

*/