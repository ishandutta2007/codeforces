#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int t;
    for (cin >> t; t; t -= 1) {
        LL n, s, k;
        cin >> s >> n >> k;
        if (s == k) {
            cout << "YES\n";
            continue;
        }
        LL x = s / (2 * k) * k + min(s % (2 * k), k);
        if (s - k >= 0 and (s - k) % (k * 2) < k) x -= 1;
        if (x >= n) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}