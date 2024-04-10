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
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int m;
	cin >> m;
	vector <int> b(m);
	for (int i = 0; i < m; ++i) cin >> b[i];
	ll sum = 0;
	for (int i = 0; i < n; ++i) sum += a[i];
	for (int i = 0; i < m; ++i) sum -= b[i];
	if (sum != 0) {
		cout << "-1\n";
		return 0;
	}
	vector <ll> ps(m + 1);
	for (int i = 1; i <= m; ++i) {
		ps[i] = ps[i - 1] + b[i - 1];
	}
	int ans = 0;
	ll csum = 0;
	int al = 0, bl = 0;
	for (int r = 0; r < n; ++r) {
		csum += a[r];
		int cl = bl;
		int cr = m;
		while ((cr - cl) > 1) {
			int cm = (cl + cr) >> 1;
			if (ps[cm + 1] - ps[bl] > csum) cr = cm;
			else cl = cm;
		}
		if (ps[cl + 1] - ps[bl] == csum) {
			++ans;
			csum = 0;
			al = r + 1;
			bl = cl + 1;
		}
	}
	cout << ans << '\n';
}