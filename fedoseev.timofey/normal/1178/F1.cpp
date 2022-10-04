#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int md = 998244353;

void add(int &a, int b) {
	a += b;
	if (a >= md) a -= md;
}

int mul(int a, int b) {
	return ((ll)a * b) % md;
}

const int N = 507;

int dp[N][N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector <int> a(m);
    for (int i = 0; i < m; ++i) {
    	cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
    	dp[i][i] = 1;
    }
    auto get = [&] (int l, int r) {
    	if (l <= r) return dp[l][r];
    	return 1;
    };
    for (int len = 2; len <= n; ++len) {
    	for (int l = 0; l + len <= n; ++l) {
    		int r = l + len - 1;
    		int mn = n + 1, pos = -1;
    		for (int i = l; i <= r; ++i) {
    			if (a[i] < mn) {
    				mn = a[i];
    				pos = i;
    			}
    		}
    		int f = 0, s = 0;
    		for (int nl = l; nl <= pos; ++nl) {
    			add(f, mul(get(l, nl - 1), get(nl, pos - 1)));
    		}
    		for (int nr = pos; nr <= r; ++nr) {
    			add(s, mul(get(nr + 1, r), get(pos + 1, nr)));
    		}
    		dp[l][r] = mul(f, s);
    	}
    }
    cout << dp[0][n - 1] << '\n';
}