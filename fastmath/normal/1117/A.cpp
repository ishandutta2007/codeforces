#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int n;
int a[N];
signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin); cout.precision(20);
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.precision(20);
    #endif
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int mx = -1;
    for (int i = 0; i < n; ++i) mx = max(mx, a[i]);
    int ans = 0;
    int c = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == mx) ++c;
        else {
            ans = max(ans, c);
            c = 0;
        }   
    }   
    ans = max(ans, c);
    cout << ans << '\n';
}