#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef complex<ld> cd;

const ll mod = 998244353;
const int maxn = 1111111;

ll f[maxn], fi[maxn];

ll modPow(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b&1)(ans *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return ans;
}

void pre(){
    f[0] = fi[0] = 1;
    for(int i = 1; i < maxn; i++){
        f[i] = (f[i-1]*i)%mod;
        fi[i] = (fi[i-1]*modPow(i, mod-2))%mod;
    }
}

ll ncr(int n, int r){
    return f[n]*(fi[n-r]*fi[r]%mod)%mod;
}

void add(ll &a, ll b){
    a += b;
    if(a >= mod)a -= mod;
}

void sub(ll &a, ll b){
    a -= b;
    if(a < 0)a += mod;
}

ll compute1(int n){
    ll t1 = modPow(3, 1LL*n*n);
    ll t2 = modPow(3, n);
    sub(t2, 3);
    t2 = modPow(t2, n);
    sub(t1, t2);
    (t1 *= 2) %= mod;
    return t1;
}

ll computek(int i, int n){
    ll t1 = modPow(3, 1LL*n*i);
    ll t2 = modPow(modPow(3, i) - 1, n);
    sub(t1, t2);
    return t1;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    pre();
    int n;
    cin>>n;
    ll ans = compute1(n);
    // cout<<ans<<endl;
    for(int i = 0; i < n; i++){
        ll t1 = computek(i, n);
        (t1 *= ncr(n, i)) %= mod;
        (t1 *= 3) %= mod;
        if((n+i)&1)sub(ans, t1);
        else add(ans, t1);
    }
    ans %= mod;
    if(ans < 0)ans += mod;
    cout<<ans<<endl;
}