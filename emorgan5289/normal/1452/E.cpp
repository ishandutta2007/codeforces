#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 2005;
array<int, 2> a[N];
ll p[N][N], s[N][N], pm[N], sm[N];

#define intersect(a, b, c, d) max(0, 1+min(min(b-a, d-c), min(b-c, d-a)))

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
        cin >> a[i][0] >> a[i][1];
    sort(a+1, a+m+1, [](auto x, auto y){ return x[0]+x[1] < y[0]+y[1]; });
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n+1-k; j++) {
            p[i][j] = s[i][j] = intersect(a[i][0], a[i][1], j, j+k-1);
            p[i][j] += p[i-1][j];
            cmax(pm[i], p[i][j]);
        }
    for (int i = m; i >= 1; i--)
        for (int j = 1; j <= n+1-k; j++) {
            s[i][j] += s[i+1][j];
            cmax(sm[i], s[i][j]);
        }
    ll ans = 0;
    for (int i = 0; i <= m; i++)
        cmax(ans, pm[i]+sm[i+1]);
    cout << ans << "\n";
}