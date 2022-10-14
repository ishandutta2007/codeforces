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

constexpr int M=1e7+1;
int f[M], g[M];
struct __INIT {
    __INIT() {
        for(int i=2; i*i<M; i++) if(!f[i]) {
            for(int j=i*i; j<M; j+=i) if(!f[j]) f[j]=i;
        }
        for(int i=2; i<M; i++) if(!f[i]) f[i]=i;
        for(int i=1; i<M; i++) {
            int ans=1, cur=i;
            while(cur!=1) {
                if(ans%f[cur]!=0) ans*=f[cur];
                else ans/=f[cur];
                cur/=f[cur];
            }
            g[i]=ans;
        }
    }
} __init;

constexpr int N=2e5+50, K=21;
int a[N], nxt[N];
bool ban[N];
int dp[N][K];
int lst[M];
constexpr int INF=0x3f3f3f3f;

int32_t main() {
    fastio;
    int T; cin>>T;
    memset(lst, -1, sizeof(lst));
    while(T--) {
        int n, k; cin>>n>>k;
        memset(ban, 0, (n+k+1)*sizeof(bool));
        rep(i, k+1) rep(j, k+1) dp[n+i][j]=0;
        rep(i, n) {
            int x; cin>>x;
            a[i]=g[x];
        }
        for(int i=n-1; ~i; i--) {
            if(!~lst[a[i]]) nxt[i]=n;
            else nxt[i]=lst[a[i]];
            lst[a[i]]=i;
        }
        vi cur(k+1);
        iota(all(cur), n);
        rep(i, k+1) ban[n+i]=1;
        for(int i=n-1; ~i; i--) {
            if(nxt[i]!=n) {
                ban[nxt[i]]=1;
                rep(j, k+1) if(cur[j]>=nxt[i]) {
                    do cur[j]--; while(!ban[cur[j]]);
                }
            }
            rep(j, k+1) dp[i][j]=INF;
            rep(j, k+1) rep(df, j+1) {
                dp[i][j]=min(dp[i][j], dp[cur[df]][j-df]+1);
            }
            rep(j, k+1) dp[i][j]=max(dp[i][j], dp[i+1][j]);
        }
        rep(i, n) lst[a[i]]=-1;
        cout<<*min_element(dp[0], dp[0]+(k+1))<<endl;
    }
}