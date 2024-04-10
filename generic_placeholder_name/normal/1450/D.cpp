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
template<typename T, typename comp = less<T>>
using ordered_set = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr int N=3e5+5, K=19;
int a[N];
int t[N][K+1];
int lg[N];

int32_t main() {
    fastio;
    lg[1]=0;
    for(int i=2; i<N; i++) lg[i]=lg[i>>1]+1;
    int T; cin>>T;
    while(T--) {
        int n; cin>>n;
        rep(i, n) cin>>a[i];
        rep(i, n) t[i][0]=a[i];
        rep1(j, K) {
            rep(i, n-(1<<j)+1) {
                t[i][j]=min(t[i][j-1], t[i+(1<<(j-1))][j-1]);
            }
        }
        auto get = [&](int l, int r) {
            int j=lg[r-l+1];
            return min(t[l][j], t[r-(1<<j)+1][j]);
        };
        bool ans[n+1];
        memset(ans, 0, sizeof(ans));
        //1 check
        bool occ[n+1];
        memset(occ, 0, sizeof(occ));
        rep(i, n) occ[a[i]]=1;
        ans[1]=1;
        rep1(i, n) if(!occ[i]) ans[1]=0;
        //n check
        ans[n]=occ[1];
        //rest
        int l=0, r=n-1;
        for(int i=1; i<=n-2; i++) {
            if(a[l]==i) l++;
            else if(a[r]==i) r--;
            else break;
            ans[n-i]=(get(l, r)==i+1);
        }
        rep1(i, n) cout<<ans[i]; cout<<endl;
    }
}