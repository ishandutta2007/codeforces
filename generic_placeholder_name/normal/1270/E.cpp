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
#define el "\n"
 
int32_t main() {
    fastio;
    int n, d=0; cin>>n; pii a[n]; rep(i, n){
        cin>>a[i].fi>>a[i].se; 
        d=gcd(d, gcd(a[i].fi, a[i].se));
    }
    vi pts[2][2];
    rep(i, n) {a[i].fi/=d; a[i].se/=d; pts[abs(a[i].fi%2)][abs(a[i].se%2)].pb(i+1);}
    int c=0; rep(i, 2) rep(j, 2) if(pts[i][j].size()==0) c++;
    while(c==3) {
        bool chk=1;
        rep(i, 2) rep(j, 2) if(pts[i][j].size()!=0&&chk) {
            pts[i][j].clear(); chk=0;
            rep(k, n) {(a[k].fi-=i)/=2; (a[k].se-=j)/=2; pts[abs(a[k].fi%2)][abs(a[k].se%2)].pb(k+1);}
        }
        c=0; rep(i, 2) rep(j, 2) if(pts[i][j].size()==0) c++;
    }
    if(pts[0][0].size()+pts[1][1].size()==0) {
        cout<<pts[0][1].size()<<el;
        for(auto i: pts[0][1]) cout<<i<<el;
    }
    else if(pts[0][1].size()+pts[1][0].size()==0) {
        cout<<pts[0][0].size()<<el;
        for(auto i: pts[0][0]) cout<<i<<el;
    }
    else {
        cout<<pts[0][0].size()+pts[1][1].size()<<el;
        for(auto i: pts[0][0]) cout<<i<<el;
        for(auto i: pts[1][1]) cout<<i<<el;
    }
    return 0;
}