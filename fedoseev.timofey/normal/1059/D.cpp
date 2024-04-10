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

const int N = 1e5 + 7;

int x[N], y[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    bool fl1 = 0, fl2 = 0;
    for (int i = 0; i < n; ++i) {
    	cin >> x[i] >> y[i];
    	if (y[i] > 0) fl1 = 1;
    	else fl2 = 1;
    	y[i] = abs(y[i]);
    }
    if (fl1 && fl2) {
    	cout << "-1\n";
    	return 0;
    }
    ld l = 0.2, r = 1e15;
    for (int i = 0; i < 300; ++i) {
    	ld rd = sqrtl(l * r);
    	ld cl = -1e18, cr = 1e18;
    	bool fl = 1;
    	for (int i = 0; i < n; ++i) {
    		ld cur = rd * rd - (y[i] - rd) * (y[i] - rd);
    		if (cur < 0) {
    			fl = 0;
    			break;
    		}
    		cur = sqrtl(cur);
    		cr = min(cr, x[i] + cur);
    		cl = max(cl, x[i] - cur);
    	}
    	if (!fl || cl > cr) {
    		l = rd;
    	}
    	else {
    		r = rd;
    	}
    }
    cout << (l + r) / 2 << '\n';
}