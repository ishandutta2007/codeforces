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
    for (int i = 0; i < n; ++i) {
    	ll x;
    	cin >> x;
    	int cnt = 0;
    	for (int i = 0; i < 60; ++i) {
    		if (x & (1ll << i)) {
    			++cnt;
    		}
    	}
    	a[i] = cnt;
    }
    vector <int> st;
    vector <int> L(n), R(n);
    for (int i = n - 1; i >= 0; --i) {
    	while (!st.empty() && a[st.back()] <= a[i]) st.pop_back();
    	if (st.empty()) R[i] = n;
    	else R[i] = st.back();
    	st.push_back(i);
    }
    vector <int> b(n + 1);
    for (int i = 1; i <= n; ++i) {
    	b[i] = b[i - 1] + a[i - 1];
    }
    vector <int> cnt(n + 1);
    for (int i = 1; i <= n; ++i) {
    	cnt[i] = cnt[i - 1] + (b[i] % 2);
    }
    ll ans = 0;
    for (int l = 0; l < n; ++l) {
    	int cur = l;
    	while (cur < n) {
    		int cl = cur - 1;
    		int cr = R[cur];
			while (cr - cl > 1) {
    			int cm = (cl + cr) >> 1;
    			if (b[cm + 1] - b[l] < 2 * a[cur]) {
    				cl = cm;
    			}
    			else {
    				cr = cm;
    			}
    		}
	    	if (b[l] % 2) ans += cnt[R[cur]] - cnt[cr];
	    	else ans += (R[cur] - cr) - (cnt[R[cur]] - cnt[cr]);
		    cur = R[cur];
    	}
    }
    cout << ans << '\n';
}