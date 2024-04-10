// region boilerplate
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <chrono>
#include <cstdint>
#include <deque>
#include <exception>
#include <forward_list>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#if __cplusplus >= 201703L
#   include <optional>
#   include <string_view>
#   include <variant>
#endif

using namespace std;

#if __cplusplus >= 201703L
#   define all(a)      begin(a),end(a)
#   define sz(x)       ((int)size(x))
#else
#   define all(a)      (a).begin(),(a).end()
#   define sz(x)       ((int)(x).size())
#endif

#define rep(a, b)      for(int a = 0; a < (b); ++a)
#define reps(a, b, c)  for(int a = (b); a < (c); ++a)
#define trav(a, b)     for(auto& a : b)

using ll = long long;
using ld = long double;
using u64 = uint64_t;
using u32 = uint32_t;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vpi = vector<pi>;

#if __cplusplus >= 201703L
#   define MAYBE_UNUSED [[maybe_unused]]
#else
#   define MAYBE_UNUSED
#endif

MAYBE_UNUSED static constexpr int INF = (int)1e9 + 5;
MAYBE_UNUSED static constexpr ll INFL = (ll)1e18 + 5;
MAYBE_UNUSED static mt19937 rng((u32)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
//endregion

namespace snippets_dsu {
    struct DSU {
        vi p;
        explicit DSU(int n) : p(n, -1) {}

        int find(int i) { return p[i] < 0 ? i : p[i] = find(p[i]); }
        bool same(int i, int j) { return find(i) == find(j); }
        int size(int i) { return -p[find(i)]; }
        bool join(int i, int j) {
            i = find(i), j = find(j);
            if (i == j) return false;
            if (p[i] > p[j]) swap(i, j);
            p[i] += p[j], p[j] = i;
            return true;
        }
    };
} using namespace snippets_dsu;

const int N = 2005;
array<array<int, N>, N> p, l, r, u, d;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vi x(n), y(n), xs, ys;
    rep(i, n)
        cin >> x[i] >> y[i], xs.push_back(x[i]), ys.push_back(y[i]);

    sort(all(xs));
    xs.erase(unique(all(xs)), end(xs));
    sort(all(ys));
    ys.erase(unique(all(ys)), end(ys));

    int szxs = sz(xs), szys = sz(ys);
    rep(i, szxs-1)
        if (xs[i+1] - xs[i] > 1)
            xs.push_back((xs[i+1] + xs[i]) / 2);
    rep(i, szys-1)
        if (ys[i+1] - ys[i] > 1)
            ys.push_back((ys[i+1] + ys[i]) / 2);
    sort(all(xs));
    sort(all(ys));

    rep(i, n) {
        x[i] = (int)(lower_bound(all(xs), x[i]) - begin(xs));
        y[i] = (int)(lower_bound(all(ys), y[i]) - begin(ys));
    }

    vector<pair<int, pi>> e;
    rep(i, n) reps(j, i+1, n) {
        if (x[i] == x[j])
            e.emplace_back(abs(ys[y[i]] - ys[y[j]]), pi(i, j));
        else if (y[i] == y[j])
            e.emplace_back(abs(xs[x[i]] - xs[x[j]]), pi(i, j));
    }
    sort(all(e));

    rep(i, sz(xs)) rep(j, sz(ys))
        p[i][j] = l[i][j] = r[i][j] = u[i][j] = d[i][j] = -1;
    rep(i, n)
        p[x[i]][y[i]] = l[x[i]][y[i]] = r[x[i]][y[i]] = u[x[i]][y[i]] = d[x[i]][y[i]] = i;

    rep(i, n) {
        int xi = x[i], yi = y[i];
        for (int xl = x[i] - 1; xl >= 0 && p[xl][yi] == -1; --xl)
            r[xl][yi] = i;
        for (int xr = x[i] + 1; xr < sz(xs) && p[xr][yi] == -1; ++xr)
            l[xr][yi] = i;
        for (int yu = y[i] - 1; yu >= 0 && p[xi][yu] == -1; --yu)
            d[xi][yu] = i;
        for (int yd = y[i] + 1; yd < sz(ys) && p[xi][yd] == -1; ++yd)
            u[xi][yd] = i;
    }

    int low = 0, high = 2 * INF;
    while (high - low > 1) {
        int t = low + (high - low) / 2;
        DSU dsu(n);
        for (auto [w, uv] : e) {
            if (w > t)
                break;
            dsu.join(uv.first, uv.second);
        }

        set<int> repr;
        for (int i = 0; i < n; ++i)
            repr.emplace(dsu.find(i));

        if (sz(repr) == 1) {
            high = t;
            continue;
        }
        if (sz(repr) > 4) {
            low = t;
            continue;
        }

        array<int, 4> re;
        re.fill(-1);
        array<bool, 4> init_hit;
        init_hit.fill(true);
        copy(all(repr), begin(re));
        rep(i, sz(repr)) init_hit[i] = false;

        bool pos = false;
        rep(i, sz(xs)) {
            rep(j, sz(ys)) {
                if (p[i][j] != -1)
                    continue;

                auto hit = init_hit;
                auto handle_dir = [&](auto& dir) {
                    if (dir[i][j] == -1)
                        return;
                    int v = dir[i][j];
                    int dist = abs(xs[i] - xs[x[v]]) + abs(ys[j] - ys[y[v]]);
                    if (dist > t)
                        return;
                    auto it = find(all(re), dsu.find(v));
                    hit[(int)(it - begin(re))] = true;
                };
                handle_dir(l);
                handle_dir(r);
                handle_dir(u);
                handle_dir(d);

                if (hit[0] && hit[1] && hit[2] && hit[3]) {
                    pos = true;
                    goto end;
                }
            }
        }
end:
        (pos ? high : low) = t;
    }

    cout << (high == 2 * INF ? -1 : high) << '\n';
    return 0;
}