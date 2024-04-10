#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

#pragma 03

using namespace std;
using namespace __gnu_pbds;

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
#define rep(i, n) for (int i=0; i<(n); i++)
#define pcnt __builtin_popcountll
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

ull n, k, l, m;

ull add(ull a, ull b) {return ((a+b)%m+m)%m;}
ull sub(ull a, ull b) {return (a%m+m-b%m)%m;}
ull mult(ull a, ull b) {return (((a%m)*(b%m))%m+m)%m;}
ull exp(ull a, ull b) {
    if(b==0) return 1;
    else {
        ll x=exp(a, b/2);
        if(b%2) return mult(mult(x, x), a);
        else return mult(x, x);
    }
}

unordered_map<ull, ull> mm;
ull f(ull x) {
    if(!x) return 0;
    if(x<=2) return 1%m;
    if(mm[x]) return mm[x];
    ull k=(x%2)?(x+1)/2:x/2;
    mm[x]=(x%2)?add(mult(f(k), f(k)), mult(f(k-1), f(k-1))):mult(add(2*f(k-1), f(k)), f(k));
    return mm[x];
}

ull get0(ull x) {
    return f(x+2);
}

ull get1(ull x) {
    return sub(exp(2, x), get0(x));
}

ull solve() {
    if(l<64&&k>=(1LL<<l)) return 0;
    if(m==1) return 0;
    if(l==0) return k==0?1:0;
    ull ans=1, b=get0(n), a=get1(n);
    rep(i, l) {
        ull mask=(1LL<<i);
        if(k&mask) ans=mult(ans, a);
        else ans=mult(ans, b);
    }
    return ans;
}

int32_t main() {
    fastio;
    cin>>n>>k>>l>>m; cout<<solve();
}