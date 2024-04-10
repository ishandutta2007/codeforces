#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define LL long long
using namespace std;
const LL MOD = 1000000007LL;
int n,a,b;
LL fac[1000005]={1};
LL PowMod(LL a,LL b){
    LL ret=1;
    while(b){
        if(b&1) ret=(ret*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ret;
}
void Init(){
    for(int i=1;i<=1000000;i++)
        fac[i]=(fac[i-1]*i)%MOD;
}
LL cal(int n,int m){
    return (fac[n]*PowMod(fac[n-m],MOD-2)%MOD)*PowMod(fac[m],MOD-2)%MOD;
}
bool check(int n){
    while(n){
        if(n%10!=a&&n%10!=b) return false;
        n/=10;
    }
    return true;
}
int main(){
    cin>>a>>b>>n;
    LL ans=0;
    Init();
    for(int i=0;i<=n;i++){
        if(check(a*i+b*(n-i)))
            ans=(ans+cal(n,i))%MOD;
    }
    cout<<ans<<endl;
    return 0;
}