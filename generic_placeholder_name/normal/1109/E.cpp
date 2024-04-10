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

constexpr int N=1e5+1;
int MOD;
vi primes; //primes in MOD

//goddammit
//I wrote a 100-liner
//then realized that segtree doesn't work
//so no I have to redesign that shit
//WHAT THE ACTUAL FUCK THIS SHIT IS INSANE

//elementary functions - exponentiation, inverse
int exp(int a, int b) {
    if(!b) return 1;
    else {
        int x=exp(a, b/2);
        if(b%2) return 1LL*x*x%MOD*1LL*a%MOD;
        else return 1LL*x*x%MOD;
    }
}

int gcdExtended(int a, int b, int *x, int *y) {
    if(a==0) {
        *x=0, *y=1;
        return b;
    }
    int x1, y1;
    int g=gcdExtended(b%a, a, &x1, &y1);
    *x=y1-(b/a)*x1; *y=x1;
    return g;
}

int inv(int a, int m=MOD) {
    int x, y;
    int g=gcdExtended(a, m, &x, &y);
    assert(g==1);
    return (x%m+m)%m;
}
//end

//segment tree
//struct so that i don't lose my fucking mind
struct number {
    int x=1, y=1;
    int cnt[10]={0};
    number() {}
    number(int v) {
        y=v%MOD;
        rep(i, primes.size()) {
            while(v%primes[i]==0) v/=primes[i], cnt[i]++;
        }
        x=v%MOD;
    }
    friend number operator * (const number& x, const number& y) {
        number z;
        z.x=(1LL*x.x*y.x)%MOD;
        z.y=(1LL*x.y*y.y)%MOD;
        rep(i, primes.size()) z.cnt[i]=x.cnt[i]+y.cnt[i];
        return z;
    }
    void operator *= (const number& oth) {
        (*this)=(*this)*oth;
    }
    friend int operator * (int a, const number& oth) {
        return (1LL*a*oth.y)%MOD;
    }
    friend int operator * (const number& oth, int a) {
        return a*oth;
    }
    friend void operator *= (int& a, const number& oth) {
        a=a*oth;
    }
};

int sum[4*N];
number lazy[4*N];

void push(int v) {
    sum[v*2]*=lazy[v];
    sum[v*2+1]*=lazy[v];
    lazy[v*2]*=lazy[v];
    lazy[v*2+1]*=lazy[v];
    lazy[v]=number();
}

void upd(int l, int r, number val, int v=1, int tl=0, int tr=N-1) {
    if(l>r) return;
    if(l==tl&&r==tr) {
        sum[v]*=val;
        lazy[v]*=val;
        return;
    }
    push(v);
    int tm=(tl+tr)/2;
    upd(l, min(r, tm), val, v*2, tl, tm);
    upd(max(l, tm+1), r, val, v*2+1, tm+1, tr);
    sum[v]=(sum[v*2]+sum[v*2+1])%MOD;
}

void upd(int pos, number val, int v=1, int tl=0, int tr=N-1) {
    if(tl==tr) {
        sum[v]=val.y;
        lazy[v]=val;
    }
    else {
        push(v);
        int tm=(tl+tr)/2;
        if(pos<=tm) upd(pos, val, v*2, tl, tm);
        else upd(pos, val, v*2+1, tm+1, tr);
        sum[v]=(sum[v*2]+sum[v*2+1])%MOD;
    }
}

ll get(int l, int r, int v=1, int tl=0, int tr=N-1) {
    if(l>r) return 0;
    if(tl==l&&tr==r) return sum[v];
    push(v);
    int tm=(tl+tr)/2;
    return (get(l, min(r, tm), v*2, tl, tm)+get(max(l, tm+1), r, v*2+1, tm+1, tr))%MOD;
}

number getn(int pos, int v=1, int tl=0, int tr=N-1) {
    if(tl==tr) return lazy[v];
    else {
        push(v);
        int tm=(tl+tr)/2;
        if(pos<=tm) return getn(pos, v*2, tl, tm);
        else return getn(pos, v*2+1, tm+1, tr);
    }
}
//end segment tree

int32_t main() {
    //how the fuck can one possibly make something this fucking toxic
    //fml
    fastio;
    int n; cin>>n>>MOD;
    int tmp=MOD;
    for(int i=2; i*i<=tmp; i++) {
        if(tmp%i==0) {
            primes.pb(i);
            while(tmp%i==0) tmp/=i;
        }
    }
    if(tmp>1) primes.pb(tmp);
    rep(i, n) {int x; cin>>x; upd(i, number(x));}
    int q; cin>>q; while(q--) {
        int t; cin>>t;
        if(t==1) {
            int l, r, x; cin>>l>>r>>x;
            upd(--l, --r, number(x));
        }
        else if(t==2) {
            int pos, x; cin>>pos>>x;
            number p=getn(--pos);
            number q(x);
            p.x=(1LL*p.x*inv(q.x))%MOD;
            rep(i, primes.size()) p.cnt[i]-=q.cnt[i], assert(p.cnt[i]>=0);
            p.y=p.x; rep(i, primes.size()) p.y=(1LL*p.y*exp(primes[i], p.cnt[i]))%MOD;
            upd(pos, p);
        }
        else {
            int l, r; cin>>l>>r; cout<<get(--l, --r)<<endl;
        }
    }
}