#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

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
template<typename T, typename comp = less<T>>
using ordered_set = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

map<array<int, 3>, bool> cache;
bool ask(int a, int b, int c) {
    if(a>c) swap(a, c);
    if(cache.find({a, b, c})!=cache.end()) return cache[{a, b, c}];
    cout<<"? "<<a<<" "<<b<<" "<<c<<endl;
    string ret; cin>>ret;
    assert(ret=="Yes"||ret=="No");
    return cache[{a, b, c}]=(ret=="Yes");
}

int get_rnd(int l, int r) {
    uniform_int_distribution<int> engine(l, r);
    return engine(rng);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n, k; cin>>n>>k;
    int h=log(n*(k-1)+1)/log(k)+.5;
    auto is_leaf = [&](int v) {
        int x=(v==1?2:1);
        rep1(i, n) if(i!=v&&i!=x&&ask(i, v, x)) return 0;
        return 1;
    };
    auto path = [&](int u, int v) {
        vi ans;
        rep1(i, n) if(i!=u&&i!=v&&ask(u, i, v)) ans.pb(i);
        return ans;
    };
    int u=get_rnd(1, n);
    while(!is_leaf(u)) u=get_rnd(1, n);
    int v=get_rnd(1, n);
    vi p=path(u, v);
    while(p.size()<2*h-3) v=get_rnd(1, n), p=path(u, v);
    for(int x: p) {
        auto t=path(u, x);
        if(t.size()==h-2) return cout<<"! "<<x<<endl, 0;
    }
    assert(0);
}