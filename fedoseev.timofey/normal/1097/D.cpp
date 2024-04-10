#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int long long

const int mod = 1e9 + 7;

int mul(int a, int b) {
    return ((ll)a * b) % mod;
}

void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

void sub(int &a, int b) {
    a -= b;
    if (a < 0) a += mod;
}

int power(int a, ll b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int a) {
	return power(a, mod - 2);
}

vector <pair <int, int>> fact(ll n) {
	vector <pair <int, int>> cnt;
	for (int d = 2; (ll)d * d <= n; ++d) {
		if (n % d == 0) {
			int cur = 0;
			while (n % d == 0) {
				++cur;
				n /= d;
			}
			cnt.push_back({d, cur});
		}
	}
	if (n != 1) cnt.push_back({n, 1});
	return cnt;
}

const int N = 1e5;

int pr[N];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll n; int k;
    cin >> n >> k;
    for (int i = 1; i < N; ++i) pr[i] = inv(i);
    vector <pair <int, int>> kek = fact(n);
    int ans = 1;
    for (int i = 0; i < (int)kek.size(); ++i) {
    	int x = kek[i].second;
    	vector <vector <int>> dp(k + 1, vector <int> (x + 1));
    	dp[0][x] = 1;
    	for (int i = 1; i <= k; ++i) {
    		int sum = 0;
    		for (int j = x; j >= 0; --j) {
    			add(sum, mul(dp[i - 1][j], pr[j + 1]));
    			add(dp[i][j], sum);
    		}
    	}
    	int cur = 0;
    	int res = 1;
    	int sum = 0;
    	for (int j = 0; j <= x; ++j) {
    		add(cur, mul(res, dp[k][j]));
    		res = mul(res, kek[i].first);
    	}
    	ans = mul(ans, cur);
    }
    cout << ans << '\n';
}