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

constexpr int wins[]={0, 1, 0}; ///if this is incorrect i die

int get(int x, int y) {
    x%=4, y%=4;
    if(x<3) return wins[x];
    else return vi{1, -1}[(x+y)&1];
}

void solve() {
    int n; cin>>n;
    int a[n]; rep(i, n) cin>>a[i];
    for(int mask=1<<30; mask>0; mask>>=1) {
        int ones=0;
        rep(i, n) ones+=!!(a[i]&mask);
        int res=get(ones, n-ones);
        //cout<<mask<<' '<<res<<endl;
        if(!res) continue;
        else if (~res) {cout<<"WIN\n"; return;}
        else {cout<<"LOSE\n"; return;}
    }
    cout<<"DRAW\n"; return;
}

int32_t main() {
    fastio;
    int q; cin>>q; while(q--) {
        solve();
    }
}