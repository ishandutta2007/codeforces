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

constexpr int MOD=1e9+7;

inline int add(int a, int b) {return a+b>MOD?a+b-MOD:a+b;}
inline int sub(int a, int b) {return a-b<0?a-b+MOD:a-b;}
inline int mul(int a, int b) {return 1LL*a*b%MOD;}
int exp(int a, int b) {
    if(!b) return 1;
    else {
        int x=exp(a, b/2);
        if(b&1) return mul(mul(x, x), a);
        else return mul(x, x);
    }
}

struct custom_hashes {
    inline static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    template<typename T> //should take care of all types that can turn into integers
    size_t operator()(T x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64((uint64_t)x + FIXED_RANDOM);
    }
};
template<typename _F, typename _T> using safe_map=gp_hash_table<_F, _T, custom_hashes>;

safe_map<int, int> m;
//reformatting this so that i don't have to look at that overwhelmingly stupid solution
int solve(int x) {
    if(x==1) return 1;
    if(m.find(x)!=m.end()) return m[x];
    int ans=sub(exp(2, x-1), 1);
    for(int i=2; i*i<=x; i++) if(x%i==0) {
        ans=sub(ans, solve(i));
        if(i*i!=x) ans=sub(ans, solve(x/i));
    }
    return m[x]=ans;
}

int solve(int a, int b) {
    if(b%a!=0) return 0;
    else return solve(b/a);
}

int32_t main() {
    fastio;
    int a=1, b=1e9; cin>>a>>b; cout<<solve(a, b)<<endl;
}