#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=5e3+1e2+7,P=998244353;

int T,n,a[N],cnt[N];

int C[N][N],f[N][N];

signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        C[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            C[i][0]=1;
            for(int j=1;j<=i;j++)
                C[i][j]=(C[i-1][j-1]+C[i-1][j])%P;
        }
        fill(cnt+1,cnt+n+1,0);
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]),cnt[a[i]]++;
        int now=1,last=0;
        f[now][0]=1;
        for(int i=1;i<=n/2;i++)
            f[now][i]=0;
        int sum=0;
        for(int i=n;i>=1;i--)
            if(cnt[i])
            {
                swap(now,last);
                for(int j=0;j<=n/2;j++)
                {
                    f[now][j]=0;
                    if(j*2-sum-(j!=n/2)>=cnt[i])
                        f[now][j]=(f[now][j]+f[last][j]*C[j*2-sum-(j!=n/2)][cnt[i]])%P;
                    if(j&&j*2-2-sum-(j-1!=0)>=cnt[i]-1)
                        f[now][j]=(f[now][j]+f[last][j-1]*C[j*2-2-sum-(j-1!=0)][cnt[i]-1])%P;
                }
                sum+=cnt[i];
            }
        printf("%lld\n",f[now][n/2]);
    }
}