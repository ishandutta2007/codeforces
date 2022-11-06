#include <bits/stdc++.h>

// Contest: Codeforces Round #597 (Div. 2) (https://codeforces.com/contest/1245)
// Problem: D: Shichikuji and Power Grid (https://codeforces.com/contest/1245/problem/D)

using namespace std;

template <class T, size_t... Is> struct arr_helper;
template <class T, size_t... Is> using arr = typename arr_helper<T, Is...>::type;
template <class T> struct arr_helper<T> { using type = T; };
template <class T, size_t I, size_t... Is>
struct arr_helper<T, I, Is...> { using type = array<arr<T, Is...>, I>; };

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

using vi = vector<int>;
using vvi = vector<vi>;
using pi = pair<int, int>;
using vpi = vector<pi>;

struct DSF {
    vi p;
    int c;

    DSF(int n) : p(n), c(n) {
        iota(begin(p), end(p), 0);
    }

    int repr(int i) {
        if (p[i] != i)
            p[i] = repr(p[i]);
        return p[i];
    }

    bool join(int a, int b) {
        a = repr(a), b = repr(b);
        c -= a != b;
        p[a] = b;
        return a != b;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vpi p(n);
    for (auto&[xi, yi] : p) cin >> xi >> yi;
    vi c(n), k(n);
    for (auto& ci : c) cin >> ci;
    for (auto& ki : k) cin >> ki;

    vector<tuple<ll, int, int>> e;
    for (int i = 0; i < n; ++i)
        e.emplace_back(c[i], i, n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ll per_km = k[i] + k[j];
            ll xdist = abs(p[i].first - p[j].first);
            ll ydist = abs(p[i].second - p[j].second);
            e.emplace_back(per_km * (xdist + ydist), i, j);
        }
    }

    sort(begin(e), end(e));
    DSF dsf(n + 1);
    vi station;
    vpi conn;
    ll cost = 0;
    for (auto[c, a, b]: e) {
        if (dsf.join(a, b)) {
            if (b == n)
                station.push_back(a);
            else
                conn.emplace_back(a, b);
            cost += c;
        }
    }

    cout << cost << '\n' << station.size() << '\n';
    for (auto i : station)
        cout << (i + 1) << ' ';
    cout << '\n' << conn.size() << '\n';
    for (auto[a, b] : conn)
        cout << (a + 1) << ' ' << (b + 1) << '\n';

    return 0;
}