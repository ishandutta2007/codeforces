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

constexpr int N=531441, M=12;
int f[N], c[N], w[N];
int x[M], y[M];
int d, n, m;

int dfs(int p, int v) {
    if(p==d) return f[v];
    int ans=dfs(p+1, v*3+x[p]);
    if(~y[p]) ans+=dfs(p+1, v*3+y[p]);
    return ans;
}

int32_t main() {
    fastio;
    cin>>d>>n>>m;
    rep(_, n) {int x; cin>>x; c[x]++;}
    rep(i, 1<<d) for(int j=d-1; ~j; j--) (w[i]*=3)+=(i>>j)&1;
    rep(i, 1<<d) rep(j, 1<<d) if(c[i]&&c[j]) f[w[i]+w[j]]+=c[i]*c[j];
    while(m--) {
        string s; cin>>s;
        memset(x, -1, sizeof(x));
        memset(y, -1, sizeof(y));
        rep(i, s.size()) {
            switch(s[i]) {
                case 'A':
                    x[i]=0, y[i]=1;
                    break;
                case 'O':
                    x[i]=0;
                    break;
                case 'X':
                    x[i]=0, y[i]=2;
                    break;
                case 'a':
                    x[i]=2;
                    break;
                case 'o':
                    x[i]=1, y[i]=2;
                    break;
                case 'x':
                    x[i]=1;
                    break;
                default:
                    assert(0);
                    break;
            }
        }
        cout<<dfs(0, 0)<<endl;
    }
}