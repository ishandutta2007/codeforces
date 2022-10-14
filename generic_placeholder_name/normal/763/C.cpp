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

ll m; int n;
constexpr int N=1e5;
ll a[N];
ll sum, sq;

inline ll add(ll a, ll b) {return (a+b)%m;}
inline ll sub(ll a, ll b) {return add(a, m-b);}
inline ll mul(ll a, ll b) {return (a*b)%m;}

ll exp(ll a, ll b, ll p=m) {
    if(!b) return 1;
    else {
        ll x=exp(a, b/2);
        x=x*x%p;
        if(b&1) return x*a%p;
        else return x;
    }
}

inline ll inv(ll a) {return exp(a, m-2);}

unordered_set<ll> allowed;
inline ll calc_square_d(ll x) {
    ll c1=mul(2, mul(x, sum));
    ll c2=mul(n, mul(x, x));
    ll lf=add(sub(sq, c1), c2);
    ll rg=mul(6, inv(mul(n, mul(n-1, 2*n-1))));
    return mul(lf, rg);
}

inline ll legendre(ll x) {
    ll ls=exp(x, (m-1)/2);
    if(ls==m-1) return -1;
    else return ls;
}

pll tonelli_shanks(ll a) {
    if(a==0) return {0, -1};
    if(m==2) return {a, -1};
    if(legendre(a)!=1) return {-1, -1};
    if(m%4==3) {
        ll x=exp(a, (m+1)/4);
        return {x, m-x};
    }
    ll q=m-1, s=0;
    while(q%2==0) s++, q/=2;
    ll z=1;
    while(legendre(z)!=-1) z++;
    ll c=exp(z, q);
    ll x=exp(a, (q+1)/2);
    ll t=exp(a, q);
    ll p=s;
    while(t!=1) {
        ll i=0, e=2;
        for(i=1; i<p; i++) {
            if(exp(t, e)==1) break;
            (e*=2)%=m-2;
        }
        ll b=exp(c, exp(2LL, p-i-1, m-2));
        x=mul(x, b);
        c=mul(b, b);
        t=mul(t, c);
        p=i;
    }
    return {x, m-x};
}

bool check(ll x, ll d) {
    unordered_set<int> lf, rg;
    rep(i, n) lf.insert(a[i]);
    rep(i, n) rg.insert(add(x, mul(i, d)));
    return lf==rg;
}

int32_t main() {
    fastio;
    cin>>m>>n;
    rep(i, n) {
        cin>>a[i];
        (sum+=a[i])%=m;
        (sq+=a[i]*a[i])%=m;
    }
    if(n==1) {cout<<a[0]<<' '<<0<<endl; return 0;}
    if(n==2) {cout<<a[0]<<' '<<sub(a[1], a[0])<<endl; return 0;}
    if(n==m) {cout<<"0 1\n"; return 0;}
    int E=0;
    if(m==2*n-1) {
        E=sub(m, n);
        unordered_set<int> has;
        rep(i, n) has.insert(a[i]);
        int k=0; sum=sq=0;
        rep(i, m) if(has.find(i)==has.end()) {
            a[k++]=i;
            (sum+=i)%=m;
            (sq+=1LL*i*i)%=m;
        }
        n=k;
    }
    rep1(i, n-1) {
        allowed.insert(sub(a[0], a[i]));
        allowed.insert(sub(a[i], a[0]));
    }
    rep(i, n) {
        ll tg=calc_square_d(a[i]);
        pll res=tonelli_shanks(tg);
        for(ll d: {res.fi, res.se}) {
            if(d==-1) continue;
            if(allowed.find(d)==allowed.end()) continue;
            if(sub(sum, mul(n, a[i]))!=mul(mul(mul(n, n-1), inv(2)), d)) continue;
            if(!check(a[i], d)) continue;
            cout<<add(mul(E, d), a[i])<<' '<<d<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}