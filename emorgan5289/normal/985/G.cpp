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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct splitmix64 {
    size_t operator()(long long x) const {
        static const size_t fixed = chrono::steady_clock::now().time_since_epoch().count();
        x += 0x9e3779b97f4a7c15 + fixed;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
};

// gp_hash_table<A, B>;

// if A is integral, better to use this option:
// gp_gash_table<long long, B, splitmix64>

using ull = unsigned long long;
gp_hash_table<ull, bool> e_set;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ull n, m; cin >> n >> m;
    ull s = sqrt(n);
    ull a, b, c; cin >> a >> b >> c;
    vector<array<ull, 2>> e(m);
    vector<vector<ull>> adjl(n), adjr(n);
    for (ull i = 0; i < m; i++) {
        ull x, y; cin >> x >> y;
        if (x > y) swap(x, y);
        e[i] = {x, y};
        e_set[x*n+y] = 1;
        adjr[x].pb(y), adjl[y].pb(x);
    }

    auto check = [&](ull i, ull j) {
        return e_set.find(i*n+j) != e_set.end();
    };

    vector<ull> hvy;
    ull ans = 0;
    for (ull i = 0; i < n; i++) {

        ull sx = adjl[i].size(), sy = adjr[i].size();
        ull x = 0, y = 0;
        for (ull j : adjl[i]) x += j;
        for (ull j : adjr[i]) y += j;
        sort(all(adjr[i]));
        sort(all(adjl[i]));

        // 0 edge
        ans += a*i*((n-i-1)*(n-i-2)/2);
        ans += b*i*(i*(n-i-1));
        ans += c*i*(i*(i-1)/2);

        // 1 edge
        for (ull j : adjr[i]) {
            ans -= (a*i+b*j)*(n-j-1) + c*((n-1)*n/2 - j*(j+1)/2);
            ans -= (b*i+c*j)*i + a*((i-1)*i/2);
            ans -= (a*i+c*j)*(j-i-1) + b*((j-1)*j/2 - i*(i+1)/2);
        }

        // 2 edge
        // center
        ans += a*x*sy + b*i*sx*sy + c*y*sx;
        // left
        ans += a*i*(sy*(sy-1)/2);
        for (ull j = 0; j < sy; j++) {
            ans += b*adjr[i][j]*(sy-j-1);
            ans += c*adjr[i][j]*(j);
        }
        // right
        ans += c*i*(sx*(sx-1)/2);
        for (ull j = 0; j < sx; j++) {
            ans += a*adjl[i][j]*(sx-j-1);
            ans += b*adjl[i][j]*(j);
        }

        // 3 edge, light
        if (sy < s) {
            for (int j = 0; j < sy; j++)
                for (int k = j+1; k < sy; k++)
                    if (check(adjr[i][j], adjr[i][k]))
                        ans -= a*i+b*adjr[i][j]+c*adjr[i][k];
        } else hvy.pb(i);
    }

    // 3 edge, heavy
    for (auto& [j, k] : e)
        for (int i : hvy)
            if (i < j && check(i, j) && check(i, k))
                ans -= a*i+b*j+c*k;

    cout << ans << "\n";
}