#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 7;
const int INF = 1e9 + 7;

int a[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int x, f;
    cin >> x >> f;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] <= x) continue;
        ans += f * ((a[i] - x - 1) / (x + f) + 1);
    }

    cout << ans << '\n';
    return 0;
}