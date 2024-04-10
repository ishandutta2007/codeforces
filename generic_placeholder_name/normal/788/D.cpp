#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

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
template<typename _def> using ordered_set=tree<_def, null_type, greater<_def>, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

//randomized
//ironically, this solution only works because the space is big
//ehh but if space is small then we can maybe brute for x

constexpr int N=1e8;
vi pos;
unordered_set<int> lx, ly;

int ask(int x, int y) {
    cout<<0<<' '<<x<<' '<<y<<endl;
    int ret; cin>>ret; return ret;
}

void answer() {
    cout<<1<<' '<<lx.size()<<' '<<ly.size()<<endl;
    for(int x: lx) cout<<x<<' '; cout<<endl;
    for(int y: ly) cout<<y<<' '; cout<<endl;
    exit(0);
}

int get_rand(int l, int r) {
    auto engine = uniform_int_distribution<int>(l, r);
    return engine(rng);
}

void search_points(int l, int r) {
    if(r-l<=5) {
        for(int i=l+1; i<r; i++) {
            if(!ask(i, i)) pos.pb(i);
        }
        return;
    }
    int m=(l+r)/2;
    int x=ask(m, m);
    if(m-x!=l&&!ask(m-x, m-x)) {
        pos.pb(m-x);
        search_points(l, m-x);
        search_points(m-x, r);
        return;
    }
    else if(m+x!=r&&!ask(m+x, m+x)) {
        pos.pb(m+x);
        search_points(l, m+x);
        search_points(m+x, r);
        return;
    }
}

constexpr int iter=5;
void search_vert(int x) {
    int ans=0;
    rep(_, iter) ans|=ask(x, get_rand(-N, N));
    if(!ans) lx.insert(x);
}

void search_hori(int y) {
    int ans=0;
    rep(_, iter) ans|=ask(get_rand(-N, N), y);
    if(!ans) ly.insert(y);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int l=-N+ask(-N, -N), r=N-ask(N, N);
    pos.pb(l); pos.pb(r);
    search_points(l, r);
    for(int x: pos) {
        search_vert(x);
        search_hori(x);
    }
    answer();
}