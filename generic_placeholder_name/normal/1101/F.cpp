#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

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

struct truck {
    int s, f, c, r;
    inline void assign(int _s, int _f, int _c, int _r) {s=_s, f=_f, c=_c, r=_r;}
};

constexpr int N=400, M=2.5e5;
int a[N];
truck t[M];
int n, m;

bool check(int idx, ll v) {
    const truck ct=t[idx];
    ll cur=v; int rf=0;
    for(int i=ct.s; i<ct.f; i++) {
        const ll df=1LL*ct.c*(a[i+1]-a[i]);
        if(cur>=df) cur-=df;
        else if(rf==ct.r||v<df) return 0;
        else cur=v-df, ++rf;
    }
    return 1;
}

int32_t main() {
    fastio;
    cin>>n>>m;
    rep(i, n) cin>>a[i];
    rep(i, m) {
        int s, f, c, r; cin>>s>>f>>c>>r;
        t[i].assign(--s, --f, c, r);
    }
    shuffle(t, t+m, rng);
    //this should be better
    //by taking all the stuff separately we can make successes fail quickly
    //by comparing to current min
    ll ans=0;
    rep(i, m) {
        if(check(i, ans)) continue;
        ll l=ans+1, r=1e18;
        while(l<r) {
            ll mid=(l+r)/2;
            if(check(i, mid)) r=mid;
            else l=mid+1;
        }
        ans=l;
    }
    cout<<ans<<endl;
}