#include<bits/stdc++.h>
#define N 505000
#define F first
#define S second
using namespace std;
typedef pair<int,int>pi;
int a[N],c[N],d[N],n,k,dp[4][N],r;
pi b[N];

int main()
{
    scanf("%d%d",&k,&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    for (int i=1;i<n;i++) d[i]=b[i].F=a[i]-a[i-1],b[i].S=i;
    sort(b+1,b+n);
    for (int i=1;i<min(n,k*3);i++) c[b[i].S]=1;
    for (int i=1;i<=k;i++) dp[0][i]=1e9;
    for (int i=1;i<n;i++)
    {
        if (!c[i]) continue; r++;
        for (int j=1;j<=min(r,k);j++) dp[r&3][j]=min(dp[(r-1-c[i-1])&3][j-1]+d[i],dp[(r-1)&3][j]);
        for (int j=r+1;j<=k;j++) dp[r&3][j]=1e9;
    }
    cout << dp[r&3][k] << endl;
    return 0;
}