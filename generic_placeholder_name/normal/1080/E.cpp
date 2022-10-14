#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize("Ofast")
#pragma GCC optimization("no-stack-protector, unroll-loops")
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

constexpr int N=300;
char a[N][N];
int dp[N][N][26];

template <typename T>
ll manacher(const vector<T>& s) {
    int n=s.size();
    vector<int> d1(n, 0);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    vector<int> d2(n, 0);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
            k++;
        }
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k ;
        }
    }
    ll ans=0;
    for(int it: d1) ans+=it;
    for(int it: d2) ans+=it;
    return ans;
}

int32_t main() {
    fastio;
    int n, m; cin>>n>>m;
    rep1(i, n) rep1(j, m) cin>>a[i][j];
    rep1(i, n) rep1(j, m) rep(k, 26) dp[i][j][k]=dp[i][j-1][k]+(a[i][j]==('a'+k));
    ll ans=0;
    rep1(l, m) for(int r=l; r<=m; r++) {
        vvi x;
        rep1(i, n) {
            vi a(26);
            int cnt=0;
            rep(j, 26) a[j]=dp[i][r][j]-dp[i][l-1][j], cnt+=a[j]&1;
            if(cnt>1) {
                ans+=manacher(x);
                x.clear();
            }
            else x.pb(a);
        }
        if(!x.empty()) ans+=manacher(x);
    }
    cout<<ans<<endl;
}