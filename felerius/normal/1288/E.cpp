#include <bits/stdc++.h>

// Contest: Educational Codeforces Round 80 (Rated for Div. 2) (https://codeforces.com/contest/1288)
// Problem: E: Messenger Simulator (https://codeforces.com/contest/1288/problem/E)

using namespace std;

#define sz(x)       (int)size(x)
#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define trav(a, b)  for(auto& a : b)

template <class T, size_t... Is> struct arr_helper;
template <class T, size_t... Is> using arr = typename arr_helper<T, Is...>::type;
template <class T> struct arr_helper<T> { using type = T; };
template <class T, size_t I, size_t... Is>
struct arr_helper<T, I, Is...> { using type = array<arr<T, Is...>, I>; };

using ll = long long;
using u64 = uint64_t;
using u32 = uint32_t;

using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vpi = vector<pi>;

[[maybe_unused]] const int INF = (int)1e9;
[[maybe_unused]] const ll INFL = (ll)1e18;

struct Bit {
    using T = int;
    vector<T> b;

    Bit() = default;
    explicit Bit(size_t n) : b(n) {}

    T sum(int r) {
        T ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += b[r];
        return ret;
    }

    void add(u32 idx, T val) {
        for (; idx < b.size(); idx = idx | (idx + 1))
            b[idx] += val;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    Bit b(n + m);
    vi p(n);
    iota(all(p), m);
    rep(i, n) b.add(m + i, 1);
    vpi mm(n);
    rep(i, n) mm[i] = {i, i};

    rep(i, m) {
        int ai; cin >> ai; --ai;
        mm[ai].second = max(mm[ai].second, b.sum(p[ai]) - 1);
        mm[ai].first = 0;
        b.add(p[ai], -1);
        p[ai] = m - 1 - i;
        b.add(p[ai], 1);
    }

    rep(i, n)
        mm[i].second = max(mm[i].second, b.sum(p[i]) - 1);
    rep(i, n)
        cout << (mm[i].first + 1) << ' ' << (mm[i].second + 1) << '\n';

    return 0;
}