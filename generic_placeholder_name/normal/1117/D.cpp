#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma 03

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

ll n; int m;
vvi mat(101, vi(101, 0));

constexpr int MOD=1e9+7;
vvi mul(vvi& a, vvi& b) {
    vvi c(101, vi(101, 0));
    rep(i, 101) rep(j, 101) rep(k, 101) c[i][j]=(c[i][j]+1LL*a[i][k]*b[k][j])%MOD;
    return c;
}

vvi exp(vvi& a, ll n) {
    if(n==1) return a;
    else {
        vvi x=exp(a, n/2);
        x=mul(x, x);
        if(n%2) return mul(x, a);
        else return x;
    }
}

int32_t main() {
    scanf("%I64d%d", &n, &m);
    rep(i, m-1) mat[i][i+1]=1;
    mat[m-1][0]=mat[m-1][m-1]=1;
    mat=exp(mat, n);
    printf("%d\n", mat[m-1][m-1]);
}