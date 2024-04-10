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
template<typename _def> using ordered_set=tree<_def, null_type, less<_def>, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

int32_t main() {
    fastio;
    int n, m; cin>>n>>m;
    if(n==1) {return puts("0"), 0;}
    ordered_set<int> s[n];
    int sz[n];
    int sum=0;
    rep(i, n) {
        cin>>sz[i]; sum+=sz[i];
        rep(j, sz[i]) {
            int x; cin>>x;
            s[i].insert(x);
        }
    }
    set<pii> q;
    vector<array<int, 3>> ops;
    auto pull = [&](int x, int y) {
        int l=1, r=m;
        while(l<r) {
            int mid=(l+r)/2;
            if(s[x].order_of_key(mid+1)>=s[y].order_of_key(mid+1)) l=mid+1;
            else r=mid;
        }
        s[x].insert(r); sz[x]++;
        s[y].erase(r); sz[y]--;
        ops.pb({y+1, x+1, r});
    };
    rep(i, n) q.emplace(-sz[i], i);
    while(1) {
        int i=q.begin()->se; q.erase({-sz[i], i}); 
        int j=q.rbegin()->se; q.erase({-sz[j], j});
        if(sz[i]<=sz[j]+1) break;
        pull(j, i);
        q.emplace(-sz[i], i);
        q.emplace(-sz[j], j);
    }
    cout<<ops.size()<<endl;
    for(auto& op: ops) cout<<op[0]<<' '<<op[1]<<' '<<op[2]<<endl;
}