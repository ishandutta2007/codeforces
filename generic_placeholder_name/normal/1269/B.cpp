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
    int n, m; cin>>n>>m;
    int a[n], b[n], aux[n], ans=m+1;
    unordered_map<int, int> ma, mb;
    rep(i, n) {cin>>a[i]; ma[a[i]]++;}
    rep(i, n) {cin>>b[i]; mb[b[i]]++;}
    sort(b, b+n);
    rep(i, n) if(mb[b[i]]==ma[a[0]]) {
        int add=(b[i]-a[0]+m)%m;
        rep(i, n) aux[i]=(a[i]+add)%m;
        sort(aux, aux+n);
        bool c=1;
        rep(i, n) {
            if(aux[i]!=b[i]) c=0;
        }
        if(c) ans=min(ans, add);
    }
    cout<<ans;
}