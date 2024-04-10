#include <bits/stdc++.h>
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();
 
using namespace std;

signed main() {
    #ifdef DEBUG
        freopen( "main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    long long a, b, x;
    cin >> a >> b >> x;
    if (a >= x || b >= x) {
        cout << 0 << '\n';
        return 0;
    }
    if (a <= 0 && b <= 0) {
        cout << -1 << '\n';
        return 0;
    }
    long long cnt = 0;
    if (a < b)
        swap(a, b);
    if (b < 0) {
        cnt += (-b) / a;
        b += a * cnt;
    }
    while (a < x && b < x) {
        ++cnt;
        if (a < b)
            swap(a, b);
        b = a + b;
    }
    cout << cnt << '\n';
}