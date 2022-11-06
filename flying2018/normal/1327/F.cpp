#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define N 500010
#define mod 998244353
using namespace std;
int l[N],r[N],lm[N];
int mx[N],c[N],f[N];
int main()
{
    int n,k,m;
    scanf("%d%d%d",&n,&k,&m);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&l[i],&r[i],&lm[i]);
    int ans=1;
    for(int p=0;p<k;p++)
    {
        int sm=1;
        for(int i=1;i<=n;i++) c[i]=0,mx[i]=0;
        for(int i=1;i<=m;i++)
        if((lm[i]>>p)&1) c[l[i]]++,c[r[i]+1]--;
        else mx[r[i]]=max(mx[r[i]],l[i]);
        f[0]=1;
        int j=0;
        for(int i=1;i<=n+1;i++) c[i]+=c[i-1],mx[i]=max(mx[i-1],mx[i]);
        for(int i=1;i<=n+1;i++)
        if(c[i]){f[i]=0;continue;}
        else
        {
            for(;j<mx[i-1];j++) sm=(sm-f[j]+mod)%mod;
            f[i]=sm;
            sm=(sm+f[i])%mod;
        }
        ans=1ll*ans*f[n+1]%mod;
    }
    printf("%d\n",ans);
    return 0;
}