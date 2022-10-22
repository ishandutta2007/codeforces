#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1007;

int a[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    a[0] = 0;
    a[n + 1] = 1001;
    n += 2;
            
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int r = i;
        while (r + 1 < n && a[r + 1] == a[r] + 1) ++r;
        ans = max(ans, r - i - 1);
    }   

    cout << ans << '\n';
    return 0;
}