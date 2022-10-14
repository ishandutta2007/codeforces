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

constexpr int MOD=1e9+7;
int add(int x, int y) {return (x+=y)>=MOD?x-MOD:x;}
int mul(int x, int y) {return (x*1ll*y)%MOD;}

constexpr int N=5e5+5;
ll a[N]; int cnt[60][2], e[60];

int32_t main() {
    fastio;
    e[0]=1;
    rep1(i, 59) e[i]=add(e[i-1], e[i-1]);
    int T; cin>>T;
    while(T--) {
        int n; cin>>n;
        memset(cnt, 0, sizeof(cnt));
        rep(i, n) {
            cin>>a[i];
            rep(j, 60) cnt[j][(a[i]>>j)&1]++;
        }
        int ans=0;
        rep(i, n) {
            int x=0, y=0;
            rep(j, 60) {
                if((a[i]>>j)&1) {
                    x=add(x, mul(cnt[j][1], e[j]));
                    y=add(y, mul(n, e[j]));
                }
                else {
                    y=add(y, mul(cnt[j][1], e[j]));
                }
            }
            ans=add(ans, mul(x, y));
        }
        cout<<ans<<endl;
    }
}