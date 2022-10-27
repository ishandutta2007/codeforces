#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

const ll mod = 1000000007;

ll modpow(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b&1)(ans *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return ans;
}

ll a[200005], fac[200005], ifac[200005];

void pre(){
    fac[0] = ifac[0] = 1;
    for(int i = 1; i < 200005; i++){
        fac[i] = (i*fac[i-1])%mod;
        ifac[i] = modpow(fac[i], mod-2);
    }
}

void perform(int n, bool op){
    for(int i = 1; i < n; i++){
        if(i%2 == 1){
            if(op)(a[i] += a[i+1]) %= mod;
            else (a[i] += mod - a[i+1]) %= mod;
        }else{
            if(!op)(a[i] += a[i+1]) %= mod;
            else (a[i] += mod - a[i+1]) %= mod;
        }
    }
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pre();
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    bool op = true;
    while(n%4 != 1){
        perform(n, op);
        if(n%2 == 0){
            op ^= true;
        }
        n--;
    }
    if(n == 1){
        cout<<a[1]<<endl;
        return 0;
    }
    ll ans = 0;
    int k = n/2;
    for(int i = 1; i <= n; i += 2){
        ll tmp = (fac[k]*ifac[k-(i/2)])%mod;
        (tmp *= ifac[i/2]) %= mod;
        (tmp *= a[i]) %= mod;
        (ans += tmp) %= mod;
    }
    cout<<ans<<endl;
}