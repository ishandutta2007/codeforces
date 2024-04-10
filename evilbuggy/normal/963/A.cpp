#include <bits/stdc++.h>

using namespace std;

long long int mod = 1000000009;

long long int modPow(long long int n, long long int p){
    if(p == 0)return 1;
    long long int t = modPow(n, p/2);
    t = (t*t)%mod;
    if(p%2 == 0)return t;
    return (t*n)%mod;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int n, a, b, c, d, e, f, sum, prod;
    string s;
    int k;
    cin>>n>>a>>b>>k;
    c = b*modPow(a, mod-2), sum = 0, prod = 1;
    c %= mod;
    cin>>s;
    for(int i = 0; i < k; i++){
        if(s[i] == '+'){
            sum += prod;
            sum %= mod;
        }else{
            sum += (mod - prod);
            sum %= mod;
        }
        prod = (prod*c)%mod;
    }
    d = modPow(c, k);
    e = modPow(c, n+1);
    if(d != 1){
        f = (e-1)*modPow(d-1, mod - 2);
    }else{
        f = (n+1)/k;
    }
    f %= mod;
    long long int ans = modPow(a, n);
    ans *= sum;
    ans %= mod;
    ans *= f;
    cout<<ans%mod<<endl;
}