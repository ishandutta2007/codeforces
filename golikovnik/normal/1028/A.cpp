#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const int N = 120;
int a[N][N];

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout.precision(10); cout << fixed;
	int n, m; cin >> n >> m;
	int imn = n, imx = 0, jmn = m, jmx = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c; cin >> c;
			if (c == 'B') {
				imn = min(imn, i);
				imx = max(imx, i);
				jmn = min(jmn, j);
				jmx = max(jmx, j);
			}
		}
	}
	cout << (imx + imn) / 2 + 1 << " " << (jmx + jmn) / 2 + 1;
	return 0;
}