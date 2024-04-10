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

#define int long long 

const int md = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    string s;
    cin >> s;
    map <char, int> cnt;
    for (auto c : s) {
    	++cnt[c];
    }
    int mx = -1;
    for (auto p : cnt) mx = max(mx, p.second);
    int kek = 0;
	for (auto p : cnt) if (p.second == mx) ++kek;
	int ans = 1;
	for (int i = 0; i < n; ++i) {
		ans *= kek;
		ans %= md;
	}
	cout << ans << '\n';
}