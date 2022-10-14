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

constexpr int L=2e7+1;
int f[L], g[L];
struct __INIT {
    __INIT() {
        for(int i=2; i*i<L; i++) if(!f[i]) {
            for(int j=i*i; j<L; j+=i) if(!f[j]) f[j]=i;
        }
        for(int i=2; i<L; i++) if(!f[i]) f[i]=i;
        for(int i=2; i<L; i++) {
            if(f[i]==f[i/f[i]]) g[i]=g[i/f[i]];
            else g[i]=g[i/f[i]]+1;
        }
    }
} __init;

int count_prime_factors(int x) {
    return g[x];
}

int32_t main() {
    fastio;
    int T; cin>>T;
    while(T--) {
        int c, d, x; cin>>c>>d>>x;
        ll ans=0;
        const auto try_g = [&](int g) -> void {
            ll sum=x+d*1LL*g;
            if(sum%c) return;
            ll lcm=sum/c;
            if(lcm%g) return;
            ans+=1LL<<count_prime_factors(lcm/g);
        };
        int _sqrtx=sqrt(x);
        rep1(i, _sqrtx) {
            if(x%i==0) {
                try_g(i);
                if(i*i!=x) try_g(x/i);
            }
        }
        cout<<ans<<endl;
    }
}