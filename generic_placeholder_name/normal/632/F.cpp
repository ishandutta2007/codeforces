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

inline void NO() {cout<<"NOT MAGIC\n"; exit(0);}
inline void YES() {cout<<"MAGIC\n"; exit(0);}

constexpr int N=2501;
bitset<N> small[N];
int a[N][N];
vector<pii> idx;
vector<vector<pii>> x;

int32_t main() {
    fastio;
    int n; cin>>n;
    rep(i, n) rep(j, n) cin>>a[i][j];
    rep(i, n) rep(j, n) if(a[i][j]!=a[j][i]) NO();
    rep(i, n) if(a[i][i]) NO();
    rep(i, n) rep(j, n) if(i<=j) idx.eb(i, j);
    sort(all(idx), [&](const pii& x, const pii& y){return a[x.fi][x.se]<a[y.fi][y.se];});
    x.pb(vector<pii>{idx[0]});
    rep1(i, idx.size()-1) {
        if(a[idx[i].fi][idx[i].se]!=a[idx[i-1].fi][idx[i-1].se]) x.pb(vector<pii>());
        x.back().pb(idx[i]);
    }
    rep(i, x.size()) {
        //for(auto& it: x[i]) cout<<"{"<<it.fi<<' '<<it.se<<"} "; cout<<endl;
        for(auto& it: x[i]) if((small[it.fi]&small[it.se]).any()) NO();
        for(auto& it: x[i]) small[it.fi][it.se]=small[it.se][it.fi]=1;
    }
    YES();
}