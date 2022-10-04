#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector <int> a(n), b(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    vector <vector <int>> res(n, vector <int> (m));
	int x1 = 0, x2 = 0;
	for (int i = 0; i + 1 < m; ++i) {
		res[n - 1][i] = b[i];
		x1 ^= b[i];
	}
	for (int i = 0; i + 1 < n; ++i) {
		res[i][m - 1] = a[i];
		x2 ^= a[i];
	}
	if ((x1 ^ a[n - 1]) != (x2 ^ b[m - 1])) {
		cout << "NO\n";
		return 0;
	}
	res[n - 1][m - 1] = x1 ^ a[n - 1];
	cout << "YES\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << res[i][j] << ' ';
		}
		cout << '\n';
	}
}