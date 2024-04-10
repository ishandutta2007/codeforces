#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define gcd __gcd
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i=0; i<(n); i++)
#define rep1(i, n) for (int i=1; i<=(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
template<typename T, typename cmp = less<T>>
using ordered_set=tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr int N = 2e6 + 5;
constexpr int M = 1 << 22;
set<tuple<int, int, int>> st;
ll lz[N];
ll t[M];

void modify(int l, int r, ll v) {
    for (l += N, r += N + 1; l < r; l >>= 1, r >>= 1) {
        if(l & 1) t[l++] += v;
        if(r & 1) t[--r] += v;
    }
}

ll query(int p) {
    ll res = 0;
    for (p += N; p > 0; p >>= 1) res += t[p];
    return res;
}

int get_color(int pos) {
    auto it = st.lower_bound({pos, 0, 0});
    if(it != st.end() && get<0>(*it) == pos) return get<2>(*it);
    --it;
    return get<2>(*it);
}

using ITR = set<tuple<int, int, int>>::iterator;
ITR split(int pos) {
    auto it = st.lower_bound({pos, 0, 0});
    if(it != st.end() && get<0>(*it) == pos) return it;
    it--;
    auto [l, r, c] = *it;
    st.erase(it);
    st.emplace(l, pos - 1, c);
    return st.emplace(pos, r, c).fi;
}

void assign(int l, int r, int new_c) {
    auto itr = split(r + 1), itl = split(l);
    for(auto it = itl; it != itr; it++) {
        auto [l, r, c] = *it;
        modify(l, r, lz[c]);
    }
    st.erase(itl, itr);
    st.emplace(l, r, new_c);
    modify(l, r, -lz[new_c]);
}

int32_t main() {
    fastio;
    int n, q; cin >> n >> q;  
    st.emplace(1, n, 1);
    while(q--) {
        string type; cin >> type;
        if(type == "Color") {
            int l, r, c; cin >> l >> r >> c;
            assign(l, r, c);
        }
        else if(type == "Add") {
            int c, x; cin >> c >> x;
            lz[c] += x;
        }
        else {
            int p; cin >> p;
            int c = get_color(p);
            cout << query(p) + lz[c] << endl;
        }
    }
}