#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
using namespace __gnu_pbds;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define gcd __gcd
#define lcm(a, b) (a)*(b)/gcd((a), (b))
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (register int i=0; i<(n); i++)
#define rep1(i, n) for (register int i=1; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"

int32_t main() {
    fastio;
    int n; cin>>n; vi a(n, 0); rep(i, n) cin>>a[i];
    sort(all(a)); a.erase(unique(all(a)), a.end());
    shuffle(all(a), rng);
    rep(x, 1<<30) {
        int curr=__builtin_popcount(a[0]^x); bool c=1;
        rep1(i, a.size()) if(__builtin_popcount(a[i]^x)!=curr) {c=0; break;}
        if(c) {cout<<x<<endl; return 0;}
    }
    cout<<-1<<endl;
}