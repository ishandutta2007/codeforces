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

const ll N=1e9+7;

struct matrix {
    ll a[3][3];
    ll* operator [] (int x) {return a[x];}
    const ll* operator [] (int x) const {return a[x];}
    friend matrix operator * (const matrix& a, const matrix& b) {
        matrix c;
        rep(i, 3) rep(j, 3) c[i][j]=a[i][0]*b[0][j]+a[i][1]*b[1][j]+a[i][2]*b[2][j];
        return c;
    }
    friend matrix operator % (const matrix& a, const ll x) {
        matrix c;
        rep(i, 3) rep(j, 3) c[i][j]=a[i][j]%x;
        return c;
    }
} src;

template<typename T>
T exp(T a, ll b, ll k) {
    if(b==1) return a;
    T x=exp(a, b/2, k);
    if(b%2) return ((x*x)%k*a)%k;
    else return (x*x)%k;
}

int32_t main() {
    fastio;
    ll n, f1, f2, f3, c;
    cin>>n>>f1>>f2>>f3>>c;
    f1=f1*c%N; f2=f2*c%N*c%N; f3=f3*c%N*c%N*c%N;
    src[0][0]=src[0][1]=src[0][2]=src[1][0]=src[2][1]=1;
    src=exp(src, n-3, N-1);
    cout<<(exp(f1, src[0][2], N)*exp(f2, src[0][1], N)%N*exp(f3, src[0][0], N)%N*exp(exp(c, N-2, N), n, N))%N;
}