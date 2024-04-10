#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

const int N = 1e5 + 228;
const int mod = 998244353;

int f[N];
int _f[N];

int powm(int a, int b) {
	if (b == 0)
		return 1;
	if (b % 2 == 1)
		return 1ll * powm(a, b - 1) * a % mod;
	int z = powm(a, b / 2);
	return 1ll * z * z % mod;
}

void calc() {
	f[0] = 1;
	for (int i = 1; i < N; ++i) {
		f[i] = (1ll * f[i - 1] * i) % mod;
	}
	for (int i = 0; i < N; ++i) {
		_f[i] = powm(f[i], mod - 2);
	}
}

int C(int n, int k) {
	if (k > n)
		return 0;
	// cout << n << ' ' << k << ';' << (1ll * f[n] * _f[k] % mod) * 1ll * _f[n - k] % mod << '\n';
	return (1ll * f[n] * _f[k] % mod) * 1ll * _f[n - k] % mod;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	vector<vector<int>> c(n, vector<int> (m));
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			c[i][j] = s[j] - '0';
		}
	}
	pair<long long, vector<int>> ans = {-1, vector<int> ()};
	for (int mask = 0; mask < (1 << n); ++mask) {
		vector<pair<int, int>> tmp(m);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				tmp[j].second = j;
				if (mask & (1 << i)) {
					tmp[j].first += 1 * c[i][j];
				} else {
					tmp[j].first -= 1 * c[i][j];
				}
			}
		}
		sort(all(tmp));
		vector<int> p(m);
		for (int i = 0; i < m; ++i) {
			p[tmp[i].second] = i + 1;
		}
		long long res = 0;
		for (int i = 0; i < n; ++i) {
			long long sum = 0;
			for (int j = 0; j < m; ++j) {
				if (c[i][j]) {
					sum += p[j];
				}
			}
			res += abs(a[i] - sum);
		}
		ans = max(ans, {res, p});
	}
	for (int i : ans.second)
		cout << i << ' ';
	cout << '\n';
}

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    SOLVE
	// solve();
}