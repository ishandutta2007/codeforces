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

constexpr int D=20, N=1e5+1;
array<int, D> basis[N];
int sz[N];
int a[N];

void add_vector(array<int, D>& basis, int& sz, int x) {
    rep(i, D) {
        if(!(x&(1<<i))) continue;
        if(!basis[i]) {
            basis[i]=x;
            sz++;
            return;
        }
        x^=basis[i];
    }
}

void process(int idx) {
    basis[idx]=basis[idx-1];
    sz[idx]=sz[idx-1];
    add_vector(basis[idx], sz[idx], a[idx]);
}

constexpr int MOD=1e9+7;
int exp(int a, int b) {
    if(!b) return 1;
    else {
        int x=exp(a, b/2);
        x=1LL*x*x%MOD;
        if(b&1) return 1LL*x*a%MOD;
        else return x;
    }
}

bool check(array<int, D>& basis, int x) {
    rep(i, D) {
        if(!(x&(1<<i))) continue;
        if(!basis[i]) return 0;
        x^=basis[i];
    }
    return 1;
}

int get(int idx, int x) {
    if(!check(basis[idx], x)) return 0;
    return exp(2, idx-sz[idx]);
}

int32_t main() {
    fastio;
    int n, q; cin>>n>>q;
    rep1(i, n) {cin>>a[i]; process(i);}
    while(q--) {
        int l, x; cin>>l>>x;
        cout<<get(l, x)<<endl;
    }
}