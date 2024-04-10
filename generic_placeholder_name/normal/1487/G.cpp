#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

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

constexpr int MOD=998244353;
#define __F  __attribute__((always_inline))
__F int add(int a, int b) {return (a+=b)>=MOD?a-MOD:a;}
__F int sub(int a, int b) {return (a-=b)<0?a+=MOD:a;}
__F int mul(int a, int b) {return (a*1LL*b)%MOD;}
__F void set_add(int& a, int b) {if((a+=b)>=MOD) a-=MOD;}
__F void set_sub(int& a, int b) {if((a-=b)<0) a+=MOD;}
__F void set_mul(int& a, int b) {a=mul(a, b);}
#undef __F

constexpr int M=205;
int dp1[2][M][2][2];
int dp2[2][M][M][3][3];

void uno(int n) {
    #define cur dp1[0]
    #define nxt dp1[1]
    cur[0][0][0]=25*25;
    cur[1][1][0]=25;
    cur[1][0][1]=25;
    cur[2][1][1]=1;
    for(int len=3; len<=n; len++) {
        memset(nxt, 0, sizeof(nxt));
        rep(i, len/2+2) rep(s1, 2) rep(s2, 2) {
            if(!cur[i][s1][s2]) continue;
            rep(s3, 2) if(!s3||s3!=s1) {
                int t=s3?1:24+s1;
                set_add(nxt[i+s3][s2][s3], mul(t, cur[i][s1][s2]));
            }
        }
        memcpy(cur, nxt, sizeof(cur));
    }
    #undef cur
    #undef nxt
}

void dos(int n) {
    #define cur dp2[0]
    #define nxt dp2[1]
    cur[0][0][0][0]=24*24;
    cur[1][0][0][1]=24;
    cur[0][1][0][2]=24;
    cur[1][0][1][0]=24;
    cur[0][1][2][0]=24;
    cur[1][1][1][2]=1;
    cur[1][1][2][1]=1;
    cur[2][0][1][1]=1;
    cur[0][2][2][2]=1;
    for(int len=3; len<=n; len++) {
        memset(nxt, 0, sizeof(nxt));
        rep(i, len/2+2) rep(j, len/2+2) rep(s1, 3) rep(s2, 3) {
            if(!cur[i][j][s1][s2]) continue;
            rep(s3, 3) if(!s3||s3!=s1) {
                int t=s3?1:23+!!s1;
                set_add(nxt[i+(s3==1)][j+(s3==2)][s2][s3], mul(t, cur[i][j][s1][s2]));
            }
        }
        memcpy(cur, nxt, sizeof(cur));
    }
    #undef cur
    #undef nxt
}

int32_t main() {
    fastio;
    int n; cin>>n;
    int f[26]; rep(i, 26) cin>>f[i];
    uno(n);
    dos(n);
    int ans=26*26;
    rep(_, n-2) set_mul(ans, 25);
    rep(c, 26) {
        for(int i=f[c]+1; i<=n/2+1; i++) {
            rep(s1, 2) rep(s2, 2) set_sub(ans, dp1[0][i][s1][s2]);
        }
    }
    rep(c1, 26) rep(c2, 26) if(c2<c1) {
        for(int i=f[c1]+1; i<=n/2+1; i++) {
            for(int j=f[c2]+1; j<=n/2+1; j++) {
                rep(s1, 3) rep(s2, 3) set_add(ans, dp2[0][i][j][s1][s2]);
            }
        }
    }
    cout<<ans<<endl;
}