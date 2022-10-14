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

constexpr int P=135;
uint C[P];
uint rst[P], cnt[P];

uint exp(uint a, uint b) {
    uint ans=1;
    while(b) {
        if(b&1) ans*=a;
        a*=a;
        b>>=1;
    }
    return ans;
}

int32_t main() {
    fastio;
    uint n, p, q; cin>>n>>p>>q;
    p=min(p, n-1);
    C[0]=rst[0]=1;
    rep1(i, p) {
        rst[i]=rst[i-1];
        cnt[i]=cnt[i-1];
        int r=n-i+1;
        int lr=__builtin_ctz(r);
        int li=__builtin_ctz(i);
        cnt[i]+=lr-li;
        rst[i]*=(r/(1u<<lr));
        rst[i]*=exp(i/(1u<<li), (1u<<31)-1);
        C[i]=rst[i]*(1u<<cnt[i]);
    }
    uint ans=0;
    rep1(i, q) {
        uint cur=0, pw=1;
        rep(j, p+1) cur+=C[j]*pw, pw*=i;
        cur*=i;
        ans^=cur;
    }
    cout<<ans<<endl;
}