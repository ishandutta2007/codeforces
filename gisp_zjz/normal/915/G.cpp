#include<bits/stdc++.h>
#define maxn 2000010
#define M 1000000007

using namespace std;
typedef long long ll;
ll mu[maxn],a[maxn],d[maxn],n,k,ans,s[maxn],sum;

ll pow_(ll x,ll y)
{
    ll rt=1;
    while (y){
        if (y&1) rt=rt*x%M;
        x=x*x%M;
        y>>=1;
    }
    return rt;
}

int main()
{
    scanf("%d%d",&n,&k); mu[1]=1;
    for (int i=0;i<=k;i++) d[i]=pow_(i,n);
    for (int i=1;i<=k;i++)
        for (int j=2;j*i<=k;j++)
            mu[i*j]-=mu[i];
    for (int i=1;i<=k;i++)
        for (int j=1;j*i<=k;j++)
            (s[i*j]+=mu[j]*(d[i]-d[i-1]))%=M;
    for (int i=1;i<=k;i++)
    {
        sum=(sum+s[i]+M)%M;
        (ans+=sum^i)%=M;
    }
    cout << ans%M << endl;
}