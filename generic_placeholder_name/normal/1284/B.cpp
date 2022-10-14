#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

#pragma 03

using namespace std;
using namespace __gnu_pbds;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define gcd __gcd
#define lcm(a, b) (a)*(b)/gcd((a), (b))
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int32_t main() {
    fastio;
    int n; cin>>n; int minv[n], occ[1000001]={0}; bool c[n]={0}; rep(i, n) {
        int m; cin>>m; int x=INT_MIN, y=INT_MAX; 
        int tmp; rep(j, m) {
            cin>>tmp;
            if(tmp>y) c[i]=1; x=max(x, tmp); y=min(y, tmp);
        }
        if(!c[i]) {minv[i]=y; occ[x]++;}
    }
    for(int i=1; i<=1000000; i++) occ[i]+=occ[i-1];
    ll ans=0;
    rep(i, n) {
        if(c[i]) ans+=n;
        else ans+=n-occ[minv[i]];
    }
    cout<<ans;
}