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
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rep(i, n) for (int i=0; i<(n); i++)
#define rep1(i, n) for (int i=1; i<=(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define el "\n"
 
int32_t main() {
    fastio;
    ll a[1000001], cyc[1000001], vis[1000001];
    int q; cin>>q; while(q--) {
        int n; cin>>n; rep1(i, n) {
            cin>>a[i]; a[i]+=n-i+1; vis[i]=0;
        }
        ll x=1, k=0;
		while(x) {
			if(vis[x]) break;
			cyc[++k]=x; vis[x]=k; x=n-a[x]+1;
		}
		cout<<k-vis[x]+1<<el; for (int i=vis[x]; i<=k; i++) cout<<cyc[i]<<" "; cout<<el;
    }
}