#pragma GCC optimize("O3")

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

void solve_case() {
    int n, m; cin>>n>>m;
    vi ans(m, -1);
    vi deg(n);
    vvi occ(n), a(m);
    rep(i, m) {
        int k; cin>>k;
        a[i].resize(k);
        rep(j, k) cin>>a[i][j], --a[i][j];
        if(a[i].size()==1) ans[i]=a[i][0], deg[a[i][0]]++;
        else rep(j, k) occ[a[i][j]].pb(i);
    }
    int mx=0;
    rep(i, n) {
        if(deg[i]>(m+1)/2) return void(cout<<"NO\n");
        if(occ[i].size()+deg[i]>occ[mx].size()+deg[mx]) mx=i;
    }
    for(; deg[mx]<(m+1)/2&&!occ[mx].empty(); deg[mx]++, occ[mx].pop_back()) {
        ans[occ[mx].back()]=mx;
    }
    rep(i, m) if(!~ans[i]) {
        if(a[i][0]!=mx) ans[i]=a[i][0];
        else {
            assert(a[i].size()>=2);
            ans[i]=a[i][1];
        }
    }
    cout<<"YES\n";
    rep(i, m) cout<<ans[i]+1<<' '; cout<<endl;
}

int32_t main() {
    fastio;
    int T; cin>>T;
    while(T--) solve_case();
}