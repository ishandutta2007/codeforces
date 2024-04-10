#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <ctime>
#include <memory.h>
#include <string>
#include <sstream>
#include <map>

#define ll long long

using namespace std;

int d[1001][1001];
int dp[502][502][2];
int INF=-2000000000,n,m;
int f[502][502]={0};
int cur=0,next=1;

int sum(int xl,int xr,int yl,int yr) {
    int ret=f[xr][yr];
    if (xl) ret-=f[xl-1][yr];
    if (yl) ret-=f[xr][yl-1];
    if (xl&&yl) ret+=f[xl-1][yl-1];
    return ret;
}

int solve(int i,int j,int k) {
    if (i+k>n||j+k>m) return INF;
    if (k==1) return d[i][j];
    int ret=sum(i,i+k-1,j,j+k-1)-(k!=3 ? dp[i+1][j+1][cur] : d[i+1][j+1])-d[i+1][j];
    return dp[i][j][next]=ret;
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int ans=INF;
    scanf("%d%d\n",&n,&m);
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            scanf("%d",&d[i][j]);
    f[0][0]=d[0][0];
    for(int i=1;i<n;++i)
        f[i][0]=f[i-1][0]+d[i][0];
    for(int j=1;j<m;++j)
        f[0][j]=f[0][j-1]+d[0][j];
    for(int i=1;i<n;++i)
        for(int j=1;j<m;++j)
            f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+d[i][j];
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j) {
            for(int k=0;k<2;++k)
                dp[i][j][k]=ans;
        }
    for(int k=3;k<=500;k+=2) {
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j) {
                ans=max(ans,solve(i,j,k));
//              cout << k << "  " << i << " " << j << " " << solve(i,j,k) << endl;
            }
        cur^=1; next^=1;
    }
    printf("%d\n",ans);
    return 0;
}