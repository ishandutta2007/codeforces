#include <bits/stdc++.h>

// Contest: Codeforces Global Round 5 (https://codeforces.com/contest/1237)
// Problem: B: Balanced Tunnel (https://codeforces.com/contest/1237/problem/B)

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

struct Bit {
    using T = ll;
    vector<T> d;

    Bit(int n) : d(n) {}

    ll sum(int r) {
        T res = 0;
        for (u32 i = r + 1; i > 0; i &= i - 1)
            res += d[i - 1];
        return res;
    }

    void add(u32 i, T v) {
        for (; i < d.size(); i |= i + 1)
            d[i] += v;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vi a(n), bpos(n);
    for (auto& ai : a) cin >> ai, --ai;
    for (int i = 0; i < n; ++i) {
        int bi; cin >> bi;
        bpos[bi - 1] = i;
    }

    Bit b(n);
    int c = 0;
    for (int i = 0; i < n; ++i) {
        auto p = bpos[a[i]];
        c += b.sum(p) < i;
        b.add(p, 1);
    }

    cout << c << '\n';
    return 0;
}