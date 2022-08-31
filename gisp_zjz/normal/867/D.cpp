#include<bits/stdc++.h>
#define maxn 105
#define maxm 10500
#define eps 1e-9

using namespace std;
typedef long long ll;

double l,r,mid,p[maxn],dp[maxn][maxn*100],sum[maxn];
int n,m,a[maxn],b[maxn];

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++)
    {
        scanf("%d%d%lf",&a[i],&b[i],&p[i]);
        p[i]/=100.0;
    }
    l=0;r=1e15;
    for (int k=0;k<100;k++)
    {
        for (int j=0;j<=m;j++) dp[n][j]=j;
        for (int j=m+1;j<maxm;j++) dp[n][j]=1e15;
        mid=(l+r)/2;
        for (int i=n-1;i>=0;i--)
            for (int j=0;j<maxm-100;j++)
                dp[i][j]=(min(mid+(double)a[i]+j,dp[i+1][j+a[i]]))*p[i]+(min(mid+(double)b[i]+j,dp[i+1][j+b[i]]))*(1-p[i]);
        if (dp[0][0]<mid) r=mid; else l=mid;
    }
    printf("%.10f\n",mid);
    return 0;
}