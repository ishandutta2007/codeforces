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
    vi a(n); vb t(n);
    rep(i, n) {
        int u, v; cin>>u>>v; --u, --v;
        if(!((u<n)^(v<n))) return puts("-1"), 0;
        if(u>v) a[v]=u, t[v]=1;
        else a[u]=v, t[u]=0;
    }
    int mx[2]={INT_MAX, INT_MAX};
    rep(i, n) {
        if(mx[1]<a[i]) return puts("-1"), 0;
        if(mx[0]<a[i]&&mx[1]>a[i]) mx[1]=a[i];
        if(mx[0]>a[i]) mx[0]=a[i];
    }
    vi pf(n), sf(n);
    rep(i, n) pf[i]=(i?min(pf[i-1], a[i]):a[i]);
    for(int i=n-1; ~i; i--) sf[i]=(i+1==n?a[i]:max(sf[i+1], a[i]));
    vi pv{-1};
    rep(i, n) if(pf[i]>sf[i+1]) pv.pb(i);
    pv.pb(n-1);
    int ans=0;
    rep(k, pv.size()-1) {
        int mx[2]={INT_MAX, INT_MAX};
        int cnt[2]={0, 0};
        int cost[2]={0, 0};
        for(int i=pv[k]+1; i<=pv[k+1]; i++) {
            if(mx[0]>a[i]) mx[0]=a[i], cnt[0]++, cost[0]+=t[i];
            else {
                assert(mx[1]>a[i]);
                mx[1]=a[i], cnt[1]++, cost[1]+=t[i];
            }
        }
        ans+=min(cost[0]+cnt[1]-cost[1], cost[1]+cnt[0]-cost[0]);
    }
    cout<<ans<<endl;
}