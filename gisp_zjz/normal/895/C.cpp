#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;
typedef long long ll;
const int q=500000004;

ll h[100],cnt[100],ans[100][2048],n,k,r,d,c[70],p[15],a[100],b[100];

bool prime(int x)
{
    for (int j=2;j*j<=x;j++) if (x%j==0) return 0;
    return 1;
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=70;i++) cnt[i]=1;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&k);cnt[k]=cnt[k]*2%mod;
    }
    for (int i=1;i<=70;i++)
    {
        if (cnt[i]==1) a[i]=0,b[i]=1;
        else a[i]=cnt[i]*q%mod,b[i]=a[i];
    }
    d=0;
    for (int i=2;i<32;i++)
    {
        if (prime(i)) c[i]=d,p[d++]=i;
    }
    for (int i=1;i<=70;i++)
    {
        h[i]=0; int t=i;
        for (int j=0;j<11;j++)
        {
            while (t%p[j]==0)
            {
                t/=p[j];
                h[i]^=(1<<j);
            }
        }
    }
    memset(ans,0,sizeof(ans));
    ans[0][0]=1;
    for (int i=1;i<=70;i++)
    {
        if (i>35&&prime(i)){
            for (int j=0;j<2048;j++) ans[i][j]=ans[i-1][j]*b[i];
        }
        else{
            for (int j=0;j<2048;j++)
            {
                ans[i][j]+=ans[i-1][j]*b[i]%mod;
                ans[i][j^h[i]]+=ans[i-1][j]*a[i]%mod;
            }
        }
        for (int j=0;j<2048;j++) ans[i][j]%=mod;
    }
    printf("%d\n",(ans[70][0]+mod-1)%mod);
}