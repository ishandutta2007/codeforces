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

//Z-function
vi Z(const string& s, const string& t) {
    string str=t+"#"+s;
    int n=str.length();
    vi z(n, 0);
    int l=0, r=-1;
    rep1(i, n-1) {
        if(i<=r) z[i]=min(z[i-l], r-i+1);
        while(i+z[i]<n&&str[z[i]]==str[i+z[i]]) z[i]++;
        if(i+z[i]-1>r) l=i, r=i+z[i]-1;
    }
    return vi(z.begin()+t.length()+1, z.end());
}

constexpr int N=5e5+1;

ll t[4*N+110]={0};
ll lz[4*N+110]={0};

void push(int v, int l, int r)
{
    if(lz[v] == 0)
    {
        return;
    }
    t[v] += (r - l + 1) * lz[v];
    if(l != r)
    {
        lz[v << 1] += lz[v];
        lz[v << 1 | 1] += lz[v];

    }
    lz[v]=0;
}

void upd(int l, int r, int val, int v=1, int tl=0, int tr=N-1) {
    push(v, tl, tr);
    if(l > tr or r < tl)
    {
        return;
    }
    if(tl >= l and tr <= r)
    {
        lz[v] += val;
        push(v, tl, tr);
        return;
    }
    int mid = (tl + tr) >> 1;
    upd(l, r, val, v << 1, tl, mid);
    upd(l, r, val, v << 1 | 1, mid + 1, tr);
    t[v] = t[v << 1] + t[v << 1 | 1];
}

ll get(int l, int r, int v=1, int tl=0, int tr=N-1)
{
    push(v, tl, tr);
    if(l>r) return 0;
    if(l>tr or r < tl)
    {
        return 0;
    }
    if(l<=tl&&r>=tr) return t[v];
    else
    {
        push(v, tl, tr);
        int tm=(tl+tr)/2;
        return get(l, r, v*2, tl, tm)+get(l, r, v*2+1, tm+1, tr);
    }
}

int32_t main() {
    fastio;
    int n, m; cin>>n>>m;
    string a, b, s; cin>>a>>b>>s;
    vi ca=Z(a, s);
    reverse(all(b)); reverse(all(s));
    vi cb=Z(b, s);
    reverse(all(cb));
    ll ans=0;
    int l=0, r=-1;
    rep(i, n) if(ca[i]) {
        while(r<min(i+m-2, n-1)) upd(1, cb[++r], 1);
        while(l<i) upd(1, cb[l++], -1);
        ans+=get(max(m-ca[i], 1), m-1);
    }
    cout<<ans<<endl;
}