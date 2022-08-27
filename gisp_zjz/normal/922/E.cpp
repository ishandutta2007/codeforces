#include<bits/stdc++.h>
#define maxn 10001

using namespace std;
typedef long long ll;

ll x,w,n,c[maxn],b[maxn],z,dp[maxn];

int main()
{
    scanf("%d%d%d%d",&n,&w,&z,&x);
    memset(dp,-1,sizeof(dp));
    for (int i=0;i<n;i++) scanf("%d",&b[i]);
    for (int i=0;i<n;i++) scanf("%d",&c[i]);
    dp[0]=w;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<b[i];j++)
            for (int k=maxn-1;k>=1;k--)
                if (dp[k-1]>=0) dp[k]=max(dp[k],dp[k-1]-c[i]);
        for (int k=maxn-1;k>=1;k--)
            if (dp[k]!=-1) dp[k]=min(w+k*z,dp[k]+x);
    }
    for (int i=maxn-1;;i--) if (dp[i]!=-1) {printf("%d\n",i);return 0;}
}