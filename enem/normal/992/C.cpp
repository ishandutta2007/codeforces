/*
    Author - Param Kothari
    Ah shit, here we go again
*/

#include <bits/stdc++.h>
 
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define mk make_pair

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

ll modp(ll x, ll y, ll p){  
    ll res = 1;
    x = x % p;
    while(y > 0){  
        if (y & 1){ 
            res = (res * x) % p; 
        } 
        y = y >> 1;
        x = (x * x) % p;  
    }  
    return res % p;  
}

void solve(){
    ll x, k, x1;
    cin >> x >> k;
    if(x == 0){
        cout << 0 << "\n";
        return;
    }
    ll den = modp(2LL, k, MOD);
    ll den2 = (den - 1 + MOD) % MOD;
    x1 = (x % MOD) * (den % MOD);
    x1 %= MOD;
    ll x2 = (x % MOD) + (den2 % MOD) * (x%MOD - 1);
    x2 %= MOD;
    swap(x1, x2);
    ll num = ((x2 % MOD) * (x2 % MOD)) % MOD;
    num += (x2 % MOD);
    num %= MOD;
    // cout << num << "\n";
    x1--;
    num = (num - (((x1 % MOD) * (x1 % MOD)) % MOD) + MOD) % MOD;
    num = (num - (x1 % MOD) + MOD) % MOD;
    // cout << num << "\n";
    ll res = (num * modp(den, MOD - 2, MOD)) % MOD;
    cout << res << "\n";
    return;
}

int main(){
    IOS;
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    return 0;
}