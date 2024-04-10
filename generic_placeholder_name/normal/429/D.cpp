#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,mmx,avx,avx2,fma")

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

constexpr int N=100000, BUF_SIZE=8192;
constexpr ll INF=1e18;
int a[N], f[N]; ll buf[BUF_SIZE], ans;

int32_t main() {
    fastio;
    int n; cin>>n; rep(i, n) cin>>a[i], f[i]=i?f[i-1]+a[i]:a[i];
    ans=INF; rep(i, BUF_SIZE) buf[i]=INF;
    int c;
    for(c=0; c+BUF_SIZE<n; c+=BUF_SIZE) {
        for(int i=c; i<c+BUF_SIZE; i++) {
            for(int j=0; j<i; j++) {
                const ll v=(f[i]-f[j])*1LL*(f[i]-f[j])+(i-j)*1LL*(i-j);
                buf[i-c]=buf[i-c]>v?v:buf[i-c];
            }
        }
    }
    for(int i=c; i<n; i++) {
        for(int j=0; j<i; j++) {
            const ll v=(f[i]-f[j])*1LL*(f[i]-f[j])+(i-j)*1LL*(i-j);
            ans=ans>v?v:ans;
        }
    }
    rep(i, BUF_SIZE) ans=ans>buf[i]?buf[i]:ans;
    cout<<ans<<endl;
}