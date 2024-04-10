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
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    multiset <int> kek;
	for (int i = 0; i < n; ++i) kek.insert(a[i]);
	for (int i = 0; i < m; ++i) {
		int x = *kek.begin();
		kek.erase(kek.begin());
		kek.insert(x + 1);
	}
	int mx = -1;
	for (int i = 0; i < n; ++i) mx = max(mx, a[i]);
	cout << (*kek.rbegin()) << ' ' << mx + m << '\n';
}