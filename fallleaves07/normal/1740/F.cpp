#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int M = 998244353;

int f[501][501][501];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int n;
	cin >> n;
	vector<int> len(n + 1), a(n + 1), res(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i], ++len[a[i]];
	}
	auto inc = [](int &v, int val) {
		v += val;
		if (v >= M) {
			v -= M;
		}
	};
	vector<int> l;
	for (auto v : len) {
		if (v > 0) {
			l.emplace_back(v);
		}
	}
	sort(l.begin(), l.end(), greater<int>());
	for (int i = 1; i < (int)l.size(); i++) {
		l[i] += l[i - 1];
	}
	int m = l.size();
	vector f(m + 1, array<int, 2001>{});
	f[0][0] = 1;
	for (int x = n; x >= 1; x--) {
		for (int i = 0; i < m; i++) {
			for (int j = 1ll * i * x; j + x <= n; j++) {
				if (f[i][j] > 0 && j + x >= l[i]) {
					inc(f[i + 1][j + x], f[i][j]);
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		inc(ans, f[i][n]);
	}
	printf("%d\n", ans);
    return 0;
}