#include <bits/stdc++.h>

using namespace std;

signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    const int MAXN = 200;

    int ans = 0;
    for (int i = 0; i < MAXN; ++i) {
        if (i <= a && i + 1 <= b && i + 2 <= c) {
            ans = max(ans, i * 3 + 3);
        }   
    }   

    cout << ans << '\n';
    return 0;
}