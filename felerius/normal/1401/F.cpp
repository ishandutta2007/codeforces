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

const int N = 18;
const int NP = N + 1;
ll sum[1 << NP];
bool swp[1 << NP];
array<bool, NP> lazyrev[1 << NP], lazyswap[1 << NP];

void apply_rev(int i, int d) {
    swp[i] ^= 1;
    if (d + 1 < NP)
        lazyrev[i][d+1] ^= 1;
}

void apply_swap(int i) {
    swp[i] ^= 1;
}

void push(int i, int d) {
    assert(d + 1 < NP);
    for (int j : {2*i, 2*i+1}) {
        reps(k, d + 2, NP)
            lazyrev[j][k] ^= lazyrev[i][k], lazyswap[j][k] ^= lazyswap[i][k];
        if (lazyrev[i][d+1])
            apply_rev(j, d+1);
        if (lazyswap[i][d+1])
            apply_swap(j);
    }
    fill(all(lazyswap[i]), false);
    fill(all(lazyrev[i]), false);
}

void segset(int i, int d, int l, int r, int qi, int qv) {
    if (r - l == 1) {
        sum[i] = qv;
        return;
    }

    push(i, d);
    int m = (l + r) / 2;
    int li = 2*i, ri = 2*i+1;
    if (swp[i])
        swap(li, ri);
    if (qi < m)
        segset(li, d+1, l, m, qi, qv);
    else
        segset(ri, d+1, m, r, qi, qv);
    sum[i] = sum[li] + sum[ri];
}

ll segquery(int i, int d, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr)
        return sum[i];
    if (qr <= l || r <= ql)
        return 0;

    push(i, d);
    int m = (l + r) / 2;
    int li = 2*i, ri = 2*i+1;
    if (swp[i])
        swap(li, ri);
    return segquery(li, d+1, l, m, ql, qr) + segquery(ri, d+1, m, r, ql, qr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, ai; cin >> n >> q;
    rep(i, 1 << n)
        cin >> ai, segset(1, 0, 0, 1 << N, i, ai);

    while (q--) {
        int ty; cin >> ty;
        if (ty == 1) {
            int x, k; cin >> x >> k; --x;
            segset(1, 0, 0, 1 << N, x, k);
        } else if (ty == 2) {
            int k; cin >> k;
            k = N - k;
            if (k)
                lazyrev[1][k] ^= 1;
            else
                apply_rev(1, 0);
        } else if (ty == 3) {
            int k; cin >> k;
            k = N - k - 1;
            if (k)
                lazyswap[1][k] ^= 1;
            else
                apply_swap(1);
        } else {
            int l, r; cin >> l >> r; --l;
            cout << segquery(1, 0, 0, 1 << N, l, r) << '\n';
        }
    }

    return 0;
}