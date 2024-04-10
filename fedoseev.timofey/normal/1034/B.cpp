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

signed  main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    if (n > 3 && m > 3) {
    	ll ans = (ll)n * m;
    	if (ans & 1) --ans;
    	cout << ans << '\n';
    	return 0;
    }
    else if (n == 1 || m == 1) {
    	if (m == 1) swap(n, m);
    	ll ans = (ll)(m - (m % 6)) * n;
        m %= 6;
        if (m == 4) ans += 2;
        if (m == 5) ans += 4;
        cout << ans << '\n';
        return 0;
    }
    else if (n == 3 || m == 3) {
        if (m == 3) swap(n, m);
        if (m == 2) {
            cout << 4 << '\n';
            return 0;
        }
        ll ans = (ll)n * m;
        if (ans & 1) --ans;
        cout << ans << '\n';
        return 0;
    }
    else if (n == 2 || m == 2) {
        if (m == 2) swap(n, m);
        if (m == 2) {
            cout << 0 << '\n';
            return 0;
        }
        if (m == 4) {
            cout << 8 << '\n';
            return 0;
        }
        if (m == 7) {
            cout << 12 << '\n';
            return 0;
        }
        cout << (ll)n * m << '\n';
    }
    else assert(0);
}