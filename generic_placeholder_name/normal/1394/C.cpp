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

//fucked up pretty badly on this one

constexpr int N=5e5;
int a[N], b[N]; string s[N];
int n;

int l, r; 
int d, u; 
int dl, ur; 
int dr, ul; 

constexpr int INF=5e8;
void calc(int m){
    l=0, r=INF;
    d=0, u=INF;
    dl=1, ur=INF+INF;
    ul=-INF, dr=INF;
    rep(i, n) {
        l=max(l, a[i]-m);
        r=min(r, a[i]+m);
        d=max(d, b[i]-m);
        u=min(u, b[i]+m);
        dl=max(dl, a[i]+b[i]-2*m);
        ur=min(ur, a[i]+b[i]+2*m);
        ul=max(ul, a[i]-b[i]-m);
        dr=min(dr, a[i]-b[i]+m);
    }
}

pii find(){
    pii ans={-2, -2};
    if (l>r||d>u||dl>ur||ul>dr) return {-1, -1};
    for(int x=l; x<=r; x++) {
        int ly=d, ry=u;
        ly=max(ly, dl-x); ry=min(ry, ur-x);
        ly=max(ly, x-dr); ry=min(ry, x-ul);
        if (ly>ry) continue;
        return {x, ly};
    }
    return {-1, -1};
}

int32_t main() {
    fastio;
    cin>>n;
    rep(i, n) {
        cin>>s[i];
        for(char c: s[i]) if(c=='B') a[i]++; else b[i]++;
    }
    int ansb=-1, ansn=-1, ans=INT_MAX;
    int l=0, r=N;
    while(l<r) {
        int m=(l+r)/2;
        calc(m);
        auto x=find();
        if(x.fi==-1) l=m+1;
        else {
            ans=r=m;
            ansb=x.fi, ansn=x.se;
        }
    }
    assert(ansb!=-1&&ansn!=-1);
    cout<<ans<<endl;
    rep(i, ansb) cout<<'B'; rep(i, ansn) cout<<'N'; cout<<endl;
}