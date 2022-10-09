#include <bits/stdc++.h>
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();
 
using namespace std;

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    long long l, r, k;
    cin >> l >> r >> k;
    if (k == 2) {
        if (r - l + (l % 2 != 1) >= k) {
            if (l % 2 == 1)
                ++l;
            cout << 1 << '\n' << 2 << '\n' << l << ' ' << l + 1 << '\n';
            return 0;
        }
        if (r - l == 1 && (l ^ (l + 1)) < l) {
            cout << (l ^ (l + 1)) << '\n' << 2 << '\n' << l << ' ' << l + 1 << '\n';
            return 0;
        }
    }
    if (k < 3) {
        cout << l << '\n' << 1 << '\n' << l << '\n';
        return 0;
    }
    if (k >= 4) {
        if (r - l + (l % 2 != 1) >= k) {
            if (l % 2 == 1)
                ++l;
            cout << 0 << '\n' << 4 << '\n' << l << ' ' << l + 1 << ' ' << l + 2 << ' ' << l + 3 << '\n';
            return 0;
        }
    }
    long long now = l, pw = 3;
    while(now > 1){
        now /= 2;
        pw *= 2;
    }
    while (pw <= l)
        pw *= 2;
    if (pw > r) {
        if (l % 2 == 1)
                ++l;
        cout << 1 << '\n' << 2 << '\n' << l << ' ' << l + 1 << '\n';
        return 0;
    } else {
        cout << 0 << '\n' << 3 << '\n' << l << ' ' << pw << ' ' << (pw ^ l) << '\n';
        return 0;
    }
}