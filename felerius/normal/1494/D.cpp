// Dogeforces (https://codeforces.com/contest/1494/problem/D)
// begin "cp-lib/boilerplate.hpp"
#include <bits/stdc++.h>

#define _choose(_1, _2, _3, chosen, ...) chosen
#define _rep(i, l, r)     for (int i = l; i < r; ++i)
#define _rep0(i, r)       _rep(i, 0, r)
#define _repr(i, r, l)    for (int i = r; i >= l; --i)
#define _repr0(i, r)      _repr(i, r, 0)
#define rep(...)          _choose(__VA_ARGS__, _rep, _rep0, suppress_warning)(__VA_ARGS__)
#define repr(...)         _choose(__VA_ARGS__, _repr, _repr0, suppress_warning)(__VA_ARGS__)
#define all(a)      ::begin(a),::end(a)
#define sz(c)       int(::size(c))
#define trav(a, b)  for(auto& a : b)

using namespace std;

using ll = long long;
using ld = long double;
using u64 = uint64_t;
using u32 = uint32_t;

[[maybe_unused]] static constexpr int INF = int(1e9 + 5);
[[maybe_unused]] static constexpr ll INFL = ll(INF) * INF;
[[maybe_unused]] static mt19937 rng(u32(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count()));

namespace cp_lib {}
// end "cp-lib/boilerplate.hpp"
// begin "cp-lib/ds/dsu/base.hpp"
namespace cp_lib {
    struct Dsu {
        vector<int> p;

        explicit Dsu(int n) : p(n, -1) {}

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
}
// end "cp-lib/ds/dsu/base.hpp"

using namespace cp_lib;

template <class T>
struct span {
    T *begin_ = nullptr, *end_ = nullptr;
    span() = default;
    template <class C>
    constexpr explicit span(C& c) : begin_(addressof(*::begin(c))), end_(addressof(*::end(c))) {}
    constexpr span(T* begin, T* end) : begin_(begin), end_(end) {}
    constexpr auto begin() const noexcept { return begin_; }
    constexpr auto end() const noexcept { return end_; }
    constexpr auto rbegin() const noexcept { return reverse_iterator(end_); }
    constexpr auto rend() const noexcept { return reverse_iterator(begin_); }
    constexpr T& front() const { return *begin_; }
    constexpr T& back() const { return *(end_ - 1); }
    constexpr T& operator[](size_t idx) const { return begin_[idx]; }
    constexpr T* data() const noexcept { return begin_; }
    constexpr size_t size() const noexcept { return end_ - begin_; }
    [[nodiscard]] constexpr bool empty() const noexcept { return begin_ == end_; }
    constexpr span sub(size_t l, size_t r) const noexcept { return {begin_ + l, begin_ + r}; }
};
template <class C> span(C&) -> span<remove_const_t<remove_reference_t<decltype(*::begin(declval<C>()))>>>;

constexpr int N = 505;
int a[N][N];
vector<int> salary;
vector<pair<int, int>> edges;
int n, k;

int build(span<int> nodes) {
    if (sz(nodes) == 1)
        return nodes[0];

    int mx = 0, m = sz(nodes);
    rep(i, m) rep(j, i + 1, m)
        mx = max(mx, a[nodes[i]][nodes[j]]);
    int root = k++;
    salary.push_back(mx);

    Dsu dsu(n);
    rep(i, m) rep(j, i + 1, m)
        if (a[nodes[i]][nodes[j]] != mx)
            dsu.join(nodes[i], nodes[j]);
    sort(all(nodes), [&](int i, int j) { return dsu.find(i) < dsu.find(j); });
    while (sz(nodes)) {
        auto first_repr = dsu.find(nodes[0]);
        auto l = int(find_if(all(nodes), [&](auto i) { return dsu.find(i) != first_repr; }) - begin(nodes));
        auto sub_root = build(nodes.sub(0, l));
        edges.emplace_back(sub_root, root);
        nodes = nodes.sub(l, sz(nodes));
    }

    return root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    rep(i, n) rep(j, n)
        cin >> a[i][j];
    rep(i, n)
        salary.push_back(a[i][i]);
    k = n;

    vector<int> nodes(n);
    iota(all(nodes), 0);
    int root = build(span(nodes));

    cout << k << '\n';
    trav(i, salary)
        cout << i << ' ';
    cout << '\n' << (root + 1) << '\n';
    for (auto& [x, y] : edges)
        cout << (x + 1) << ' ' << (y + 1) << '\n';
}