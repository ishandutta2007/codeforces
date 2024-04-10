#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL MOD=998244353;
const LL A=119,B=23,R=3;
inline LL Pow(LL X,LL Y)
{
    LL ans=1;
    for(;Y>0;Y>>=1)
    {
        if(Y&1)
            ans=ans*X%MOD;
        X=X*X%MOD;
    }
    return ans;
}
inline void NTT(vector<LL>&X,bool inv)
{
    int i,j,k;
    LL x,y,z;
    int N=X.size();
    j=0;
    for(i=1;i<N;i++)
    {
        for(k=N>>1;j>=k;k>>=1)
            j-=k;
        j+=k;
        if(i<j)
            swap(X[i],X[j]);
    }
    for(i=1;i<N;i<<=1)
    {
        x=Pow(inv?Pow(R,MOD-2):R,MOD/i>>1);
        for(j=0;j<N;j+=i<<1)
        {
            y=1;
            for(k=0;k<i;k++)
            {
                z=X[i|j|k]*y%MOD;
                X[i|j|k]=X[j|k]-z;
                if(X[i|j|k]<0)
                    X[i|j|k]+=MOD;
                X[j|k]+=z;
                if(X[j|k]>=MOD)
                    X[j|k]-=MOD;
                y=y*x%MOD;
            }
        }
    }
    if(inv)
    {
        x=Pow(N,MOD-2);
        for(i=0;i<N;i++)
            X[i]=X[i]*x%MOD;
    }
    return;
}
vector<LL>V,ans;
LL N,K,i,ret;
LL D[10];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>K;
    for(i=0;i<K;i++)
        cin>>D[i];
    LL MAX=1;
    while(MAX<N*18+10)
        MAX<<=1;
    V.resize(MAX);
    ans.resize(MAX);
    for(i=0;i<MAX;i++)
        V[i]=ans[i]=0;
    for(i=0;i<K;i++)
        V[D[i]]=1;
    NTT(V,false);
    N>>=1;
    for(i=0;i<MAX;i++)
        ans[i]=1;
    for(;N>0;N>>=1)
    {
        if(N&1)
            for(i=0;i<MAX;i++)
                ans[i]=ans[i]*V[i]%MOD;
        for(i=0;i<MAX;i++)
            V[i]=V[i]*V[i]%MOD;
    }
    NTT(ans,true);
    for(i=0;i<MAX;i++)
        ret=(ret+ans[i]*ans[i])%MOD;
    cout<<ret<<endl;
    return 0;
}