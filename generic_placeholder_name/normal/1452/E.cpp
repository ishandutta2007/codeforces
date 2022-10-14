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
template<typename T, typename comp = less<T>>
using ordered_set = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

#define max sofieqnfoj
#define min kbjejankda

int l[2005], r[2005];
__attribute__((always_inline)) int max(int a, int b) {return a>b?a:b;}
__attribute__((always_inline)) int min(int a, int b) {return a<b?a:b;}

int32_t main() {
    fastio;
    int n, m, k; cin>>n>>m>>k;
    rep(i, m) {
        cin>>l[i]>>r[i];
        --l[i], --r[i];
    }
    int ans=0;
    for(int i=0; i<n-k+1; i++) {
        for(int j=i; j<n-k+1; j++) {
            int sum=0;
            for(int x=0; x<m; x++) {
                int f=max(min(r[x], i+k-1)-max(l[x], i)+1, 0);
                int s=max(min(r[x], j+k-1)-max(l[x], j)+1, 0);
                sum+=max(f, s);
            }
            ans=max(ans, sum);
        }
    }
    cout<<ans<<endl;
}