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
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

pii ask(vi a) {
    cout<<"? "; rep(i, a.size()) cout<<a[i]<<' '; cout<<endl;
    pii ret; cin>>ret.fi>>ret.se;
    fflush(stdout);
    return ret;
}

void answer(int n) {
    cout<<"! "<<n<<endl; fflush(stdout);
}
 
int32_t main() {
    fastio;
    int n, k; cin>>n>>k;
    int a[n]; rep(i, n) a[i]=INT_MAX;
    vi arr; 
    rep(i, k) arr.pb(i+1); 
    pii fp=ask(arr); a[fp.fi-1]=fp.se;
    arr.clear();
    rep(i, k) if(i+1!=fp.fi) arr.pb(i+1); arr.pb(k+1);
    pii sp=ask(arr); a[sp.fi-1]=sp.se;
    if(fp.se>sp.se) swap(fp, sp);
    int ans=1;
    rep(i, k+1) if(a[i]==INT_MAX) {
        arr.clear(); rep(j, k+1) if(a[j]==INT_MAX&&i!=j) arr.pb(j+1); arr.pb(fp.fi); arr.pb(sp.fi);
        pii val=ask(arr);
        if(val.fi==sp.fi) ans++;
    }
    answer(ans); return 0;
}