#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

const ll mod = 998244353;

ll modPow(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b&1)(ans *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return ans;
}

ll fact[1000005], ifact[1000005];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    fact[0] = ifact[0] = 1;
    for(int i = 1; i <= n; i++){
        fact[i] = (fact[i-1]*i) % mod;
        ifact[i] = (ifact[i-1]*modPow(i, mod-2))%mod;
    }
    ll ans = 0;
    for(int len = 0; len < n; len++){
        ll cnt = (fact[n]*ifact[n-len])%mod;
        cnt = (cnt*(n-len-1))%mod;
        ans += cnt*(len+1);
        ans %= mod;
    }
    cout<<ans + 1<<endl;
}