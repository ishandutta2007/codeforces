#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 5e5+5;
int a[N], f[N], l[N], r[N], c[N], dp[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    fill(r, r+n, -1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], r[a[i]] = i;
    for (int i = n; i > 0; i--) {
        f[a[i]]++, l[a[i]] = i;
        c[i] = max(c[i+1], f[a[i]]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i-1];
        if (r[a[i]] == i)
            cmax(dp[i], f[a[i]]+dp[l[a[i]]-1]);
        cmax(ans, dp[i]+c[i+1]);
    }
    cout << n-ans << "\n";
}