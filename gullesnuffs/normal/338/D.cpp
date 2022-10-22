#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long n, m, k;
long long a[10005];

long long Gcd(long long a, long long b){
    return b?Gcd(b, a%b):a;
}

long long Mgm(long long a, long long b){
    long long gcd=Gcd(a, b);
    if(a/gcd > 1000000000000000L/b)
        return 1000000000000000L;
    return (a/gcd)*b;
}

vector<long long> primes;

long long modMult(long long x, long long y, long long mod){
    long long b[2][2];
    x%=mod;
    y%=mod;
    b[0][0]=x/1e6L;
    b[0][1]=x%1000000L;
    b[1][0]=y/1e6L;
    b[1][1]=y%1000000L;
    long long res=0;
    for(int j=0; j < 2; ++j)
        for(int k=0; k < 2; ++k){
            long long MM=(b[0][j]*b[1][k])%mod;
            if(!j)
                MM=(MM*1000000L)%mod;
            if(!k)
                MM=(MM*1000000L)%mod;
            res += MM;
        }
    return res;
}

long long powerMod(long long x, long long y, long long mod){
    long long a[60];
    a[0]=x;
    for(int i=1; 1LL<<i <= y; ++i){
        a[i]=modMult(a[i-1], a[i-1], mod);
    }
    long long z=1;
    for(int i=0; 1LL<<i <= y; ++i){
        if(!(y&(1LL<<i)))
            continue;
        z=modMult(z, a[i], mod);
    }
    return z;
}

long long inv(long long x, long long mod){
    if(Gcd(x, mod) > 1)
        return 0;
    long long phi=mod;
    for(int i=0; i < primes.size(); ++i){
        if(!(mod%primes[i]))
            phi=(phi/primes[i])*(primes[i]-1);
    }
    return powerMod(x, phi-1, mod);
}

int main(){
    scanf("%I64d%I64d%I64d", &n, &m, &k);
    long long mgm=1;
    long long mod=1;
    for(int i=0; i < k; ++i){
        scanf("%I64d", a+i);
        long long mgmPrev=mgm;
        mgm=Mgm(mgm, a[i]);
        if(mgm > n){
            printf("NO");
            return 0;
        }       
    }
    for(long long i=2; i*i <= mgm; ++i){
        if(!(mgm%i)){
            primes.push_back(i);
            while(!(mgm%i))
                mgm /= i;
        }
    }
    if(mgm > 1)
        primes.push_back(mgm);
    mgm=1;
    mod=1;
    for(int i=0; i < k; ++i){
        long long mgmPrev=mgm;
        long long ai=a[i];
        mgm=Mgm(mgm, a[i]);
        long long aM=mgmPrev, bM=a[i];
        for(int j=0; j < primes.size(); ++j){
            for(long long k=primes[j]; true; k *= primes[j]){
                if(aM%k){
                    aM/=(k/primes[j]);
                    break;
                }
                if(bM%k){
                    bM/=(k/primes[j]);
                    break;
                }
            }
        }
        long long a=mod, b=(-(i%bM)+bM)%bM;
        long long x=modMult(modMult(a, bM, mgm), inv(bM, aM), mgm)+modMult(modMult(aM, b, mgm), inv(aM, bM), mgm);
        x=(x+mgm-1)%mgm+1;
        if(x%(mgmPrev) != a%(mgmPrev) || x%(ai) != (-(i%ai)+ai)%(ai) || x+k-1 > m){
            printf("NO");
            return 0;
        }
        mod=x;
    }
    for(long long i=mod; i < mod+k; ++i){
        if(Gcd(i, mgm) != a[i-mod]){
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}