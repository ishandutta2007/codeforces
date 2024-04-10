#include <bits/stdc++.h>

using namespace std;

long long int mod = 1000000007;

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
    int x,y;
    cin>>x>>y;
    if(y%x != 0){
        cout<<0<<endl;
    }else{
        y /= x;
        int sy = sqrt(double(y)), z = y;
        vector<int> pf;
        for(int i = 2; i <= sy; i++){
            if(y == 1)break;
            if(y%i == 0){
                pf.push_back(i);
                while(y%i == 0){
                    y /= i;
                }
            }
        }
        if(y != 1){
            pf.push_back(y);
        }
        int n = pf.size();
        long long int ans = 0;
        for(int mask = 0; mask < (1<<n); mask++){
            int prod = 1, mu = 0;
            for(int i = 0; i < n; i++){
                if(mask&(1<<i)){
                    prod *= pf[i];
                    mu ^= 1;
                }
            }
            if(mu == 0){
                ans += modPow(2, z/prod - 1);
            }else{
                ans += mod - modPow(2, z/prod - 1);
            }
            ans %= mod;
        }
        cout<<ans<<endl;
    }
}