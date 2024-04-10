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
    int n, m, d;
    cin >> n >> m >> d;
    vector <int> a(n);
    set <pair <int, int>> cur;
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    	cur.insert(make_pair(a[i], i));
    }
    vector <int> ans(n);
    int cnt = 0;
    while (!cur.empty()) {
    	++cnt;
    	ans[cur.begin() -> second] = cnt;
    	int t = cur.begin() -> first + d + 1;
    	cur.erase(cur.begin());
    	while (cur.upper_bound(make_pair(t, -1)) != cur.end()) {
    		auto it = cur.lower_bound(make_pair(t, -1));
    		ans[it -> second] = cnt;
    		t = it -> first + d + 1;
    		cur.erase(it);
    	}
    }
    cout << cnt << '\n';
    for (int i = 0; i < n; ++i) {
    	cout << ans[i] << ' ';
    }
}