#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL INF=1e18;
const LL MOD=998244353;
inline LL Pow(LL X,LL Y)
{
    LL ans=1;
    while(Y>0)
    {
        if(Y&1)
            ans=ans*X%MOD;
        X=X*X%MOD;
        Y>>=1;
    }
    return ans;
}
LL ans,N,i;
LL fac[1234567],invf[1234567];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    fac[0]=1;
    for(i=1;i<=N;i++)
        fac[i]=fac[i-1]*i%MOD;
    for(i=0;i<=N;i++)
        invf[i]=Pow(fac[i],MOD-2);
    ans=fac[N];
    for(i=1;i<N;i++)
    {
        ans=(ans+fac[N]*invf[i]%MOD*(fac[i]+MOD-1))%MOD;
    }
    cout<<ans<<endl;
    return 0;
}