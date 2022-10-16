#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())

using namespace std;

void no() {
	puts("-1");
	exit(0);
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10); cout << fixed;
	int n, m; cin >> n >> m;
	int sa = 0, sb = 0;
	multiset<int, greater<int>> deltas;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		sa += a;
		sb += b;
		deltas.insert(a - b);
	}
	if (sa <= m) {
		puts("0\n");
		return 0;
	}
	int cnt = 0;
	for (auto &x: deltas) {
		++cnt;
		sa -= x;
		if (sa <= m) {
			cout << cnt << "\n";
			return 0;
		}
	}
	puts("-1\n");
	return 0;	
}