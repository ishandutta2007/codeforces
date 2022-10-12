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

const int N = 1e5+5, K = 20;
int lp[N], f[N], bad;
int a[N], p[K][N];

vector<int> factors(int x) {
    vector<int> out;
    while (x > 1) {
        int y = lp[x];
        out.pb(y);
        while (x%y == 0) x /= y;
    }
    return out;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 2; i < N; i++)
        if (!lp[i])
            for (int j = i; j < N; j += i)
                lp[j] = i;
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0, j = 0; i < n; i++) {
        for (int x : factors(a[i]))
            if (++f[x] == 2) bad++;
        while (bad)
            for (int x : factors(a[j++]))
                if (--f[x] == 1) bad--;
        p[0][i] = j-1;
    }
    for (int k = 1; k < K; k++)
        for (int i = 0; i < n; i++)
            p[k][i] = p[k-1][i] == -1 ? -1 : p[k-1][p[k-1][i]];
    while (q--) {
        int l, r; cin >> l >> r; l--, r--;
        int ans = 1;
        for (int k = K-1; k >= 0; k--) {
            if (p[k][r] >= l) {
                r = p[k][r];
                ans += 1<<k;
            }
        }
        cout << ans << "\n";
    }
}