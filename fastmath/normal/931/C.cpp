#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <time.h>
#include <queue>

using namespace std;
#define int long long

const int INF = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int mx = -INF;
    int mn = INF;
    for (int i = 0; i < n; ++i) {
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }
    
    for (int i = 0; i < n; ++i) {
        a[i] -= mn;
    }

    if (mn == mx) {
        cout << n << '\n';
        for (int i = 0; i < n; ++i) {
            cout << mn << ' ';
        }
        cout << '\n';
        return 0;
    }

    if (mn == mx - 1) {
        cout << n << '\n';
        for (int i = 0; i < n; ++i) {
            cout << a[i] + mn << ' ';
        }
        cout << '\n';
        return 0;
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }

    int c0 = 0, c1 = 0, c2 = 0;
    for (int i = 0; i < n; ++i) {
        c0 += (a[i] == 0);
        c1 += (a[i] == 1);
        c2 += (a[i] == 2);
    }

    int ans = INF;
    int best0 = -1, best1 = -1, best2 = -1;
    for (int nc0 = 0; nc0 <= n; ++nc0) {
        int r = n - nc0;
        if (sum < r || r * 2 < sum) continue;
        
        int nc2 = sum - r;
        int nc1 = r - nc2;
    
        int newans = min(c0, nc0) + min(c1, nc1) + min(c2, nc2);
        if (newans < ans) {
            ans = newans;
            best0 = nc0;
            best1 = nc1;
            best2 = nc2;
        }
    }
    
    cout << ans << '\n';
    for (int i = 0; i < best0; ++i) cout << mn << ' ';
    for (int i = 0; i < best1; ++i) cout << mn + 1 << ' ';
    for (int i = 0; i < best2; ++i) cout << mn + 2 << ' ';
    cout << '\n';

    return 0;
}