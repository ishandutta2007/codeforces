#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout.precision(10); cout << fixed;
	int n, m; cin >> n >> m;
	for (int i = 0; i < (n + 3) / 4; ++i) cout << "5";
	cout << "\n";
	for (int i = 0; i < (n + 3) / 4 - 1; ++i) cout << "4";
	cout << "5\n";
	return 0;
}