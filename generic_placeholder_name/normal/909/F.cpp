#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma 03

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
template<typename _def> using ordered_set=tree<_def, null_type, less<_def>, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

uint msb32(register uint x) {
    x|=(x>>1);
    x|=(x>>2);
    x|=(x>>4);
    x|=(x>>8);
    x|=(x>>16);
    return(x&~(x>>1));
}


void solve_query_1(int n) {
    if(n&1) {cout<<"NO\n"; return;}
    if(n==2) {cout<<"YES\n2 1\n"; return;}
    int a[n]; iota(a, a+n, 1);
    int tmp=n;
    while(tmp) {
        int lst=msb32(uint(tmp));
        if(lst==tmp) {
            reverse(a, a+tmp-2); swap(a[tmp-2], a[tmp-1]);
            tmp=0;
        }
        else {
            rep(i, tmp-lst+1) swap(a[lst-i-2], a[lst+i-1]);
            tmp=2*lst-tmp-2;
        }
    }
    cout<<"YES\n";
    rep(i, n) cout<<a[i]<<' '; cout<<endl;
}

void solve_query_2(int n) {
    vi gr[19];
    for(uint x=1; x<=n; x++) {
        rep(i, 19) {
            if(x&(1<<i)&&gr[i].size()<2) {gr[i].pb(x); break;}
            if((1<<i)==msb32(x)) {gr[i].pb(x); break;}
        }
    }
    rep(i, 19) if(gr[i].size()==1) {cout<<"NO\n"; return;}
    int ans[n];
    rep(i, 19) rep(j, gr[i].size()) ans[gr[i][j]-1]=gr[i][(j+1)%gr[i].size()];
    cout<<"YES\n";
    rep(i, n) cout<<ans[i]<<' '; cout<<endl;
}

int32_t main() {
    fastio;
    int n; cin>>n;
    solve_query_1(n);
    solve_query_2(n);
}