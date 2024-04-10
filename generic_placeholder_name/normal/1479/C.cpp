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

vector<pii> adj[33];

int32_t main() {
    fastio;
    adj[2].eb(1, 1);
    for(int i=3; i<=21; i++) {
        int sum=0;
        for(int j=i-1; j>1; j--) {
            adj[i].eb(j, sum+1);
            sum+=1LL<<(j-2);
        }
        adj[i].eb(1, 1);
    }
    int l, r; cin>>l>>r;
    int x=r-l, sum=0;
    for(int i=21; i>1; i--) if((x>>(i-2))&1) {
        adj[22].eb(i, sum+1);
        sum+=1LL<<(i-2);
    }
    adj[22].eb(1, 1);
    int m=0, n=22;
    if(l!=1) adj[++n].eb(22, l-1);
    rep1(i, n) m+=adj[i].size();
    cout<<"YES\n"<<n<<' '<<m<<endl;
    rep1(i, n) for(auto& [from, w]: adj[i]) cout<<from<<' '<<i<<' '<<w<<endl;
}