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
    int c = 0;
    for (int i = 0; i < n; ++i) {
    	if (a[i] < 0) ++c;
    }
    int pt = -1;
    vector <int> used(n);
    if (c % 2) {
    	for (int i = 0; i < n; ++i) {
    		if (a[i] < 0 && (pt == -1 || abs(a[i]) < abs(a[pt]))) {
    			pt = i;
    		}
    	}
    }
    for (int i = 0; i < n; ++i) {
    	if (a[i] == 0 && pt == -1) pt = i;
    }
    if (pt != -1) {
    	used[pt] = 1;
    	int cnt = 0;
    	for (int i = 0; i < n; ++i) {
    		if (a[i] == 0 && i != pt) {
    			++cnt;
    			cout << 1 << ' ' << i + 1 << ' ' << pt + 1 << '\n';
    			used[i] = 1;
    		}
    	}
		if (cnt != n - 1) cout << 2 << ' ' << pt + 1 << '\n';
    }
    int j = 0;
    for (int i = 0; i + 1 < n; ++i) {
    	if (used[i]) continue;
    	j = i + 1;
    	while (j < n && used[j]) ++j;
    	if (j < n) cout << 1 << ' ' << i + 1 << ' ' << j + 1 << '\n';
    }
}