#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

constexpr int N = 2005;
int n, m;
bitset<N> pf[N];
bitset<N> a[N];
int cnt[N];
bitset<N> good;
set<pii> idx;

void remove(int x) {
    auto itr = idx.find({cnt[x], x});
    if(itr != idx.begin()) {
        int prv = prev(itr) -> se;
        if(itr != prev(idx.end())) {
            int nxt = next(itr) -> se;
            good[prv] = (a[nxt] | a[prv]) != a[nxt];
        }
        else good[prv] = 0;
    }
    good[x] = 0;
    idx.erase(itr);
}

void add(int x) {
    idx.emplace(cnt[x], x);
    auto itr = idx.find({cnt[x], x});
    if(itr != idx.begin()) {
        int prv = prev(itr) -> se;
        good[prv] = (a[x] | a[prv]) != a[x];
    }
    if(itr != prev(idx.end())) {
        int nxt = next(itr) -> se;
        good[x] = (a[nxt] | a[x]) != a[nxt];
    }
}

void precalc() {
    rep1(i, m) {
        pf[i] = pf[i - 1];
        pf[i][i - 1] = 1;
    }
    rep(i, n) idx.emplace(0, i);
}

void upd(int x, int l, int r) {
    remove(x);
    a[x] ^= (pf[r + 1] ^ pf[l]);
    cnt[x] = a[x].count();
    add(x);
}

optional<pair<pii, pii>> query() {
    static bitset<N> one, two;
    if(!good.count()) return {};
    int x1 = good._Find_first();
    int x2 = idx.upper_bound({cnt[x1], x1}) -> se;
    one = a[x1] & (pf[m] ^ a[x2]);
    two = a[x2] & (pf[m] ^ a[x1]);
    int y1 = one._Find_first(), y2 = two._Find_first();
    if(x1 > x2) swap(x1, x2);
    if(y1 > y2) swap(y1, y2);
    return mp(mp(x1, y1), mp(x2, y2));
}

int32_t main() {
    fastio;
    int q; cin >> n >> m >> q;
    precalc();
    while(q--) {
        int x, l, r; cin >> x >> l >> r;
        upd(--x, --l, --r);
        auto ans = query();
        if(!ans.has_value()) cout << "-1\n";
        else {
            auto& [a, b] = *ans;
            cout << a.fi + 1 << ' ' << a.se + 1 << ' ' << b.fi + 1 << ' ' << b.se + 1 << endl;
        }
    }
}