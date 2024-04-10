// Contest: Codeforces Round #616 (Div. 1) (https://codeforces.com/contest/1290)
// Problem: C: Prefix Enlightenment (https://codeforces.com/contest/1290/problem/C)
 
 
// region {{{ boilerplate
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
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
 
#if __cpp_lib_nonmember_container_access >= 201411
#   define sz(x) ((int)size(x))
#else
#   define sz(x) ((int)(x).size())
#endif
 
#define rep(a, b)      for(int a = 0; a < (b); ++a)
#define reps(a, b, c)  for(int a = (b); a < (c); ++a)
#define all(a)         (a).begin(),(a).end()
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
 
#if __has_cpp_attribute(maybe_unused) >= 201603
#   define MAYBE_UNUSED [[maybe_unused]]
#else
#   define MAYBE_UNUSED
#endif
 
MAYBE_UNUSED static constexpr int INF = (int)1e9;
MAYBE_UNUSED static constexpr ll INFL = (ll)1e18;
//endregion }}}
 
struct Node {
    int p;
    int one_count;
    list<int> l;
    bool forced;
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vpi l(n, pair(-1, -1));
    rep(i, k) {
        int c; cin >> c;
        while(c--) {
            int li; cin >> li, --li;
            (l[li].first == -1 ? l[li].first : l[li].second) = i;
        }
    }
 
    vi col(k, 0);
    vector<Node> dsu(k, Node{-1, 0, list<int>{}, false});
    rep(i, k)
        dsu[i].l.emplace_back(i);
    int cost = 0;
    auto find2 = [&](int i, auto&& f) -> int { return dsu[i].p == -1 ? i : dsu[i].p = f(dsu[i].p, f); };
    auto find = [&](int i) { return find2(i, find2); };
    auto compcost = [&](int i) { return min(dsu[i].one_count, dsu[i].forced ? INF : sz(dsu[i].l) - dsu[i].one_count); };
 
    rep(i, n) {
        if (l[i].first == -1) {
        } else if (l[i].second == -1) {
            int idx = l[i].first;
            int comp = find(idx);
            cost -= compcost(comp);
            dsu[comp].forced = true;
            if (col[idx] == (s[i] == '1')) {
                dsu[comp].one_count = sz(dsu[comp].l) - dsu[comp].one_count;
                for (auto idx2 : dsu[comp].l)
                    col[idx2] = 1 - col[idx2];
            }
            cost += compcost(comp);
        } else {
            auto [idx1, idx2] = l[i];
            int comp1 = find(idx1), comp2 = find(idx2);
            if (comp1 != comp2) {
                cost -= compcost(comp1);
                cost -= compcost(comp2);
                if (dsu[comp2].forced)
                    swap(comp1, comp2), swap(idx1, idx2);
                else if (!dsu[comp1].forced && sz(dsu[comp1].l) < sz(dsu[comp2].l))
                    swap(comp1, comp2), swap(idx1, idx2);
                bool toggle = false;
                if (s[i] == '1')
                    toggle = col[idx2] != col[idx1];
                else
                    toggle = col[idx2] == col[idx1];
                if (toggle) {
                    dsu[comp2].one_count = sz(dsu[comp2].l) - dsu[comp2].one_count;
                    for (auto idx3 : dsu[comp2].l)
                        col[idx3] = 1 - col[idx3];
                }
                dsu[comp2].p = comp1;
                dsu[comp1].one_count += dsu[comp2].one_count;
                dsu[comp1].l.splice(end(dsu[comp1].l), dsu[comp2].l);
                cost += compcost(comp1);
            }
        }
 
        cout << cost << '\n';
    }
 
    return 0;
}