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
template<typename T, typename cmp = less<T>>
using ordered_set=tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

int32_t main() {
    fastio;
    int n; cin>>n;
    vector<pll> a(n);
    ll ans=0;
    rep(i, n) {
        cin>>a[i].fi>>a[i].se;
        ans+=a[i].se;
        a[i].se+=a[i].fi;
    }
    sort(all(a));
    vector<vector<pair<int, ll>>> adj(n);
    rep(i, n) {
        int p=upper_bound(all(a), mp(a[i].se, LLONG_MAX))-a.begin();
        if(p<n) adj[i].eb(p, a[p].fi-a[i].se);
        if(p>i+1) adj[i].eb(p-1, 0);
        if(i>0) adj[i].eb(i-1, 0);
    }
    constexpr ll INF=1LL<<50;
    vll dist(n, INF); dist[0]=0;
    deque<int> q; q.push_back(0);
    vb in(n, 0); in[0]=1;
    while(!q.empty()) {
        int u=q.front(); q.pop_front();
        in[u]=0;
        for(auto& [v, w]: adj[u]) if(dist[v]>dist[u]+w) {
            dist[v]=dist[u]+w;
            if(!in[v]) {
                if(!q.empty()&&dist[v]<dist[q.front()]) q.push_front(v);
                else q.push_back(v);
                in[v]=1;
            }
        }
    }
    ans+=dist[n-1];
    cout<<ans<<endl;
}