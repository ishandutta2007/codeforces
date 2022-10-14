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

constexpr int N=1e7;
int f[N+1];
int ans[N+1];
ll g[N+1];

struct __INIT {
    __INIT() {
        for(int p=2; p*p<=N; p++) if(!f[p]) {
            for(int i=p*p; i<=N; i+=p) f[i]=p;
        }
        rep1(i, N) if(!f[i]) f[i]=i;
        memset(ans, -1, sizeof(ans));
        ans[0]=g[0]=0, ans[1]=g[1]=1;
        for(int i=2; i<=N; i++) {
            int tmp=i, cur=1; ll sum=1;
            while(tmp%f[i]==0) {tmp/=f[i]; cur*=f[i]; sum+=cur;}
            g[i]=sum*g[tmp];
            if(g[i]<=N&&!~ans[g[i]]) ans[g[i]]=i;
        }
    }
} __init;

int32_t main() {
    fastio;
    int T; cin>>T;
    while(T--) {
        int x; cin>>x;
        cout<<ans[x]<<endl;
    }
}