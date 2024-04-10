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
	int n; cin >> n;
	vector<int> p(n);
	for (int i = 1; i < n; ++i) {
		int x; cin >> x;
		p[i] = x - 1;
	}	
	vector<int> path;
	for (int i = n - 1; p[i] != i; i = p[i]) {
		path.push_back(i + 1);
	}
	path.push_back(1);
	reverse(all(path));
	for (int x: path) cout << x << " ";
	cout << "\n";
	return 0;
}