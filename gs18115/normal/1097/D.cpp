#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef vector<LL>::iterator vit;
const LL INF=1e18;
const LL MOD=1e9+7;
inline LL pow(LL x,LL y)
{
    LL ans=1;
    while(y>0)
    {
        if(y&1)
            ans=ans*x%MOD;
        x=x*x%MOD;
        y>>=1;
    }
    return ans;
}
inline LL inv(LL X)
{
    return pow(X,MOD-2);
}
vector<LL>V;
LL P[1234],C[1234],D[1234];
LL v,ans;
LL cnt,p;
LL i,j,k;
LL n,N,K;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>K;
    n=N;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            P[cnt]=i;
            while(n%i==0)
            {
                n/=i;
                C[cnt]++;
            }
            cnt++;
        }
    }
    if(n>1)
    {
        P[cnt]=n;
        C[cnt++]=1;
    }
    ans=1;
    for(i=0;i<cnt;i++)
    {
        D[0]=1;
        for(j=1;j<=C[i];j++)
            D[j]=0;
        for(j=0;j<K;j++)
        {
            v=0;
            for(k=0;k<=C[i];k++)
                D[k]=v=(v+D[k]*inv(C[i]-k+1))%MOD;
        }
        v=0;
        p=1;
        for(j=C[i];j>=0;j--)
        {
            v=(v+p*D[j])%MOD;
            p=p*P[i]%MOD;
        }
        ans=ans*v%MOD;
    }
    cout<<ans<<endl;
    return 0;
}