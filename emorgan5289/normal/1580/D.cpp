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
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

const int N = 4005;
ll n, m;
ll a[N], dp[N][N];

int construct(int i, int j) {
    if (j < i) return -1;
    int k = min_element(a+i, a+j+1)-a;
    int l = construct(i, k-1);
    int r = construct(k+1, j);
    for (int x = 0; x <= k-i; x++)
        for (int y = 0; y <= j-k; y++) {
            ll c = (l == -1 ? 0 : dp[l][x])+(r == -1 ? 0 : dp[r][y]);
            cmax(dp[k][x+y], c - a[k]*x*y*2);
            cmax(dp[k][x+y+1], c - a[k]*x*y*2 - a[k]*(2*(x+y)+1) + a[k]*m);
        }
    debug(i, j, vector(dp[k], dp[k]+n+1));
    return k;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << dp[construct(0, n-1)][m] << "\n";
}