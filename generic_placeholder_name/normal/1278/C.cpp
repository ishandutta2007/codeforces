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
#define gcd __gcd
#define lcm(a, b) (a)*(b)/gcd((a), (b))
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int32_t main() {
    fastio;
    int q; cin>>q; while(q--) {
        int n; cin>>n; int a[2*n]; rep(i, 2*n) cin>>a[i];
        int fwd[2*n+1], bwd[2*n+1];
        rep(i, 2*n+1) {fwd[i]=INT_MIN; bwd[i]=INT_MIN;} fwd[n]=0; bwd[n]=0;
        int curr=0;
        rep(i, n) {
            if(a[i]==1) curr++; else curr--;
            fwd[curr+n]=i+1;
        }
        curr=0;
        for(int i=2*n-1; i>=n; i--) {
            if(a[i]==1) curr++; else curr--;
            bwd[curr+n]=2*n-i;
        }
        ll ans=2*n;
        rep(i, 2*n+1) ans=min(ans, (ll)2*n-fwd[i]-bwd[2*n-i]);
        cout<<ans<<endl;
    }
}