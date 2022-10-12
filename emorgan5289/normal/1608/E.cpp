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

auto now() {
    return chrono::steady_clock::now();
}

template<typename T>
string delta(T a, T b) {
    return to_string(chrono::duration_cast<chrono::milliseconds>(b-a).count())+"ms";
}

bool first_pass = 1;
int subs = 0;

ll solve1(vector<array<ll, 3>> a) {

    vector<ll> ux;
    for (auto& [x, y, z] : a)
        ux.pb(x);
    sort(all(ux));
    ux.erase(unique(all(ux)), ux.end());

    vector<array<ll, 4>> my3;
    for (auto& [x, y, z] : a)
        my3.pb({x, y, z, 1});
    sort(all(my3), [&](auto i, auto j){ return i[1] < j[1]; });
    for (int i = 1; i < my3.size(); i++)
        if (my3[i][1] == my3[i-1][1])
            my3[i][3] = 0;

    auto sub = [&](ll k) {

        // auto t = now();

        ll p = 0, q = 0, r = 0, mqr = 0;
        for (auto& x : a) {
            if (x[0] <= k && x[2] == 0) p++;
            if (x[0] > k && x[2] == 2) r++;
        }
        // debug(delta(t, now())); t = now();
        for (auto& [x, y, z, b] : my3) {
            if (x > k && z == 2) r--;
            if (x > k && z == 1) q++;
            if (b) cmax(mqr, min(q, r));
            // if (first_pass) debug(v, p, q, r);
        }
        // debug(delta(t, now()));

        // debug(subs++);

        return array<ll, 2>({p, mqr});
    };

    int i = 0;
    for (int j = 1<<20; j > 0; j /= 2) {
        if (i+j+1 >= ux.size()) continue;
        auto r = sub(ux[i+j]);
        if (r[0] <= r[1]) i += j;
    }

    ll ans = 0;
    for (int j = i; j <= i+1; j++)
        if (j >= 0 && j < ux.size()) {
            auto r = sub(ux[j]);
            cmax(ans, min(r[0], r[1]));
        }
    return ans;
}

ll solve2(vector<array<ll, 3>> a) {

    auto t = now();
    vector<ll> ux;
    for (auto& [x, y, z] : a)
        ux.pb(x);
    sort(all(ux));
    ux.erase(unique(all(ux)), ux.end());
    debug(delta(t, now()));

    vector<array<ll, 4>> my3;
    for (auto& [x, y, z] : a)
        my3.pb({x, y, z, 1});
    sort(all(my3), [&](auto i, auto j){ return i[0] < j[0]; });
    for (int i = 1; i < my3.size(); i++)
        if (my3[i][0] == my3[i-1][0])
            my3[i][3] = 0;

    debug(delta(t, now()));

    auto sub = [&](ll k) {

        ll p = 0, q = 0, r = 0, mqr = 0;
        for (auto& [x, y, z] : a) {
            if (x <= k && z == 0) p++;
            if (x > k && z == 2) r++;
        }
        for (auto& [x, y, z, b] : my3) {
            if (x > k && z == 2) r--;
            if (x > k && z == 1) q++;
            if (b) cmax(mqr, min(q, r));
            // if (first_pass) debug(v, p, q, r);
        }

        // debug(subs++);

        // debug(k, p, mqr);
        return array<ll, 2>({p, mqr});
    };

    int i = 0;
    for (int j = 1<<20; j > 0; j /= 2) {
        if (i+j+1 >= ux.size()) continue;
        auto r = sub(ux[i+j]);
        if (r[0] <= r[1]) i += j;
    }

    ll ans = 0;
    for (int j = i; j <= i+1; j++)
        if (j >= 0 && j < ux.size()) {
            auto r = sub(ux[j]);
            cmax(ans, min(r[0], r[1]));
        }

    // debug(ux, i);

    first_pass = 0;
    debug(delta(t, now()));

    // debug(a, ans);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    vector<array<ll, 3>> a(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];
        a[i][2]--;
    }
    ll ans = 0;
    int attempts = 0;
    for (int t = 0; t < 4; t++) {
        vector<int> p = {0, 1, 2};
        for (int u = 0; u < 6; u++) {
            vector<array<ll, 3>> b;
            for (int i = 0; i < n; i++)
                b.pb({a[i][0], a[i][1], p[a[i][2]]});
            cmax(ans, solve1(b));
            if (t < 2)
                cmax(ans, solve2(b));
            debug(attempts++);
            next_permutation(all(p));
        }
        for (int i = 0; i < n; i++) {
            ll x = a[i][0], y = a[i][1];
            a[i][1] = -x, a[i][0] = y;
        }
    }
    cout << 3*ans << "\n";
}