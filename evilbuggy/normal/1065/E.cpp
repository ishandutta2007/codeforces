#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll mod = 998244353;

ll modPow(ll a, ll b){
    ll ans = 1;
    a %= mod;
    while(b){
        if(b&1)(ans *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return ans;
}

ll b[200005];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    ll n, sz;
    int m;
    cin>>n>>m>>sz;
    for(int i = 1; i <= m; i++){
        cin>>b[i];
    }
    b[0] = 0;
    ll ans = 1;
    ll inv2 = (mod + 1)/2;
    for(int i = 1; i <= m; i++){
        ll tmp = (modPow(sz, 2*(b[i] - b[i-1])) + modPow(sz, b[i] - b[i-1]))*inv2 % mod;
        (ans *= tmp) %= mod;
    }
    (ans *= modPow(sz, n - 2*b[m])) %= mod;
    cout<<ans<<endl;
}