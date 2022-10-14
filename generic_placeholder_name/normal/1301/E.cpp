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
template<typename T, typename cmp = less<T>>
using ordered_set=tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr int N=505;
int pf[4][N][N];
int8_t a[N][N];
int16_t mx[N][N];
int pf_mx[N/2][N][N];

int32_t main() {
    fastio;
    int n, m, q; cin>>n>>m>>q;
    rep1(i, n) rep1(j, m) {
        char c; cin>>c;
        switch(c) {
            case 'R':
                a[i][j]=0;
                break;
            case 'G':
                a[i][j]=1;
                break;
            case 'Y':
                a[i][j]=2;
                break;
            case 'B':
                a[i][j]=3;
                break;
        }
        rep(k, 4) pf[k][i][j]=pf[k][i-1][j]+pf[k][i][j-1]-pf[k][i-1][j-1]+(a[i][j]==k);
    }
    auto chk = [&](int l1, int r1, int l2, int r2) -> bool {
        int id=a[l1][r1], area=(l2-l1+1)*(r2-r1+1);
        return (pf[id][l2][r2]-pf[id][l1-1][r2]-pf[id][l2][r1-1]+pf[id][l1-1][r1-1])==area;
    };
    rep1(i, n-1) rep1(j, m-1) {
        if(a[i][j]!=0||a[i][j+1]!=1||a[i+1][j]!=2||a[i+1][j+1]!=3) continue;
        int l=0, r=min({i, j, n-i, m-j});
        while(l<r) {
            int m=(l+r+1)/2;
            if(!chk(i-m+1, j-m+1, i, j)||
               !chk(i-m+1, j+1, i, j+m)||
               !chk(i+1, j-m+1, i+m, j)||
               !chk(i+1, j+1, i+m, j+m)) r=m-1;
            else l=m;
        }
        mx[i][j]=l;
    }
    rep(k, n/2+1) rep1(i, n) rep1(j, m) {
        pf_mx[k][i][j]=pf_mx[k][i][j-1]+pf_mx[k][i-1][j]-pf_mx[k][i-1][j-1]+(mx[i][j]>=k);
    }
    while(q--) {
        int i1, j1, i2, j2;
        cin>>i1>>j1>>i2>>j2;
        int l=0, r=min((i2-i1+1)/2, (j2-j1+1)/2);
        while(l<r) {
            int m=(l+r+1)/2;
            int qi1=i1+m-1, qj1=j1+m-1, qi2=i2-m, qj2=j2-m;
            if(pf_mx[m][qi2][qj2]-pf_mx[m][qi1-1][qj2]-pf_mx[m][qi2][qj1-1]+pf_mx[m][qi1-1][qj1-1]>0) l=m;
            else r=m-1;
        }
        cout<<4*l*l<<endl;
    }
}