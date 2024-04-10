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

const int N = 1<<18;
int f[N], v[N], c[N], p[N], sz[N], val[N];

int rep(int x) {
    while (x != p[x]) x = p[x] = p[p[x]];
    return x;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    iota(p, p+N, 0);
    iota(val, val+N, 0);
    fill(sz, sz+N, 1);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        ans -= x, f[x]++;
    }
    for (int i = N-1; i > 0; i--) {
        for (int j = i; j > i-j; j = (j-1)&i) {
            if (!f[j] || !f[i-j]) continue;
            int x = rep(i-j), y = rep(j);

            if (x != y && min(val[x], val[y]) < i) {
                ll z = 1;
                if (!v[j]) v[j] = 1, z += f[j]-1;
                if (!v[i-j]) v[i-j] = 1, z += f[i-j]-1;
                ans += z*i;
                if (sz[x] < sz[y]) swap(x, y);
                p[y] = x, sz[x] += sz[y];
                val[x] = max(val[x], val[y]);
            }

        }
    }
    // for (int i = 0; i < N; i++)
    //     if (i == u.rep(i)) ans += val[i];
    for (int i = 0; i < N; i++)
        if (f[i]) cmax(c[rep(i)], i);
    for (int i = 0; i < N; i++)
        if (f[i]) {
            if (sz[rep(i)] == 1)
                ans += ll(f[i])*i;
            else if (c[i] > 0)
                ans += c[i];
        }
    cout << ans << "\n";
}