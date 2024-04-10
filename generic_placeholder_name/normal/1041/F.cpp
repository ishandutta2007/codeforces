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

int32_t main() {
    fastio;
    int n, tmp1; cin>>n>>tmp1; //coords are ints on 2 ends so y doesn't matter
    vi a(n); rep(i, n) cin>>a[i];
    int m, tmp2; cin>>m>>tmp2; //same as above
    vi b(m); rep(i, m) cin>>b[i];
    int ans=0;
    //same spot edge case
    safe_map<int, int> pos;
    rep(i, n) pos[a[i]]++; rep(i, m) pos[b[i]]++;
    for(const auto& it: pos) ans=max(ans, it.se);
    //search for candidate diffences
    for(int d=2; ; d<<=1) {
        auto norm = [&d](int x) {
            return (x%d+d)%d;
        };
        safe_map<int, int> pos;
        rep(i, n) pos[norm(a[i])]++;
        rep(i, m) pos[norm(b[i]-d/2)]++;
        for(const auto& it: pos) ans=max(ans, it.se);
        if(d>=INT_MAX/2) break;
    }
    cout<<ans<<endl;
}