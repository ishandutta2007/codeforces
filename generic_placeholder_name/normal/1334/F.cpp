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

constexpr int N=5e5+3;
constexpr ll INF=1e18;
ll f[N];
int a[N], b[N], p[N];
int idx[N];

ll get(int x) {
    ll ans=0;
    for (; x>=0; x=(x&(x+1))-1) ans+=f[x];
    return ans;
}

void upd(int x, ll d){
    for (; x<N; x=(x|(x+1))) f[x]+=d;
}

ll get(int l, int r){
    return get(r)-get(l-1);
}

int32_t main() {
    fastio;
    int n; cin>>n;
    rep1(i, n) cin>>a[i];
    rep1(i, n) cin>>p[i];
    int m; cin>>m;
    upd(0, -INF); upd(m, INF);
    rep1(i, m) cin>>b[i], idx[b[i]]=i;
    rep1(i, n) {
        int l=0, r=m;
        int pos=-1; ll pnv=0;
        if(idx[a[i]]) pos=idx[a[i]], pnv=get(pos-1, m);
        while(l<r){
            int mid=(l+r+1)/2;
            if(a[i]>b[mid]) l=mid;
            else r=mid-1;
        }
        if(p[i]<0) upd(m, p[i]);
        else upd(l, p[i]);
        if(pos!=-1) {
            ll org=get(pos, m);
            if(org<=pnv) continue;
            upd(pos, pnv-org);
            upd(pos-1, org-pnv);
        }
    }
    if(get(m, m)>1e17) cout<<"NO\n";
    else cout<<"YES\n"<<get(m, m)<<endl;
}