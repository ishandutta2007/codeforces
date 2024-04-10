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

struct dsu {

    vector<int> p, sz;

    dsu(int n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
    }

    int rep(int x) {
        while (x != p[x]) x = p[x] = p[p[x]];
        return x;
    }

    // returns true if a and b are in the same set, and then unites them.
    bool unite(int a, int b) {
        a = rep(a), b = rep(b);
        if (sz[a] < sz[b]) swap(a, b);
        if (a != b) p[b] = a, sz[a] += sz[b];
        return a == b;
    }

    // returns true if a and b are in the same set.
    bool query(int a, int b) {
        return rep(a) == rep(b);
    }

    // returns the size of the set containing x
    int size(int x) {
        return sz[rep(x)];
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        ll ans = 0;
        for (int i = 0; i < n; i++)
            if (a[i] == 0)
                ans++, a[i]++;
        bool ok = 0;

        auto check = [&]() {
            dsu u(n);
            for (ll x = 1; x <= 1ll<<30; x *= 2) {
                int p = -1;
                for (int i = 0; i < n; i++)
                    if (a[i]&x) {
                        if (p == -1) p = i;
                        else u.unite(p, i);
                    }
            }
            if (u.size(0) == n)
                ok = 1;
        };

        check();

        if (!ok)
            for (int i = 0; i < n; i++) {
                a[i]++; check();
                if (ok) { ans++; break; }
                a[i] -= 2; check();
                if (ok) { ans++; break; }
                a[i]++;
            }

        // can do in 2
        if (!ok) {
            ll m = 0;
            for (int i = 0; i < n; i++)
                cmax(m, (ll)__builtin_ctzll(a[i]));
            for (int i = 0; i < n; i++)
                for (int j = i+1; j < n; j++)
                    if (__builtin_ctzll(a[i]) == m && __builtin_ctzll(a[j]) == m) {
                        ok = 1;
                        a[i]--, ans++;
                        a[j]++, ans++;
                        goto done2;
                    }
            done2:;
        }
        cout << ans << "\n";
        for (int i = 0; i < n; i++)
            cout << a[i] << " \n"[i == n-1];
    }
}