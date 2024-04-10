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
template<typename T, typename cmp = less<T>>
using ordered_set=tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr int CUTOFF=333;

void solve_case() {
    int n; cin>>n;
    vvi a(n);
    vi large, small;
    vb is_large(n, 0);
    rep(i, n) {
        int sz; cin>>sz; a[i].resize(sz);
        for(auto& x: a[i]) cin>>x;
        sort(all(a[i]));
        if(a[i].size()>=CUTOFF) is_large[i]=1, large.pb(i);
        else small.pb(i);
    }
    auto coordinate_compress = [](vvi& a) mutable {
        set<int> x;
        for(auto& vec: a) for(auto& elem: vec) x.insert(elem);
        cc_hash_table<int, int> y;
        int m=0;
        while(!x.empty()) y[*x.begin()]=m++, x.erase(x.begin());
        for(auto& vec: a) for(auto& elem: vec) elem=y[elem];
        return m;
    };
    int m=coordinate_compress(a);
    for(auto& i: large) {
        vb vis(m, 0);
        for(auto& x: a[i]) vis[x]=1;
        for(int j=0; j<n; j++) if(!is_large[j]||j>i) {
            int cnt=0;
            for(auto& x: a[j]) {
                cnt+=vis[x];
                if(cnt==2) return void(cout<<i+1<<' '<<j+1<<endl);
            }
        }
    }
    vi lst(m, -1);
    vvi pos(m);
    for(int i: small) for(auto& x: a[i]) pos[x].pb(i);
    rep(x, m) {
        for(int i: pos[x]) {
            for(int j: a[i]) if(j!=x) {
                if(~lst[j]) return void(cout<<i+1<<' '<<lst[j]+1<<endl);
                else lst[j]=i;
            }
        }
        for(int i: pos[x]) for(int j: a[i]) lst[j]=-1;
    }
    cout<<"-1\n";
}

int32_t main() {
    fastio;
    int T; cin>>T;
    while(T--) solve_case();
}