#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int M=998244353;
const int maxn=1e6+10;
int n,_,k,a[maxn],dp[maxn][2][2];
void Max(int &x,int y){if (y>x) x=y;}
int main(){
    cin >> _;
    while (_--){
        cin >> n;
        for (int i=0;i<n;i++) cin >> a[i];
        cin >> k;
        memset(dp,-1,sizeof(dp));
        dp[0][0][0]=0;
        for (int i=0;i<n;i++)
            for (int x=0;x<2;x++)
                for (int y=0;y<2;y++){
                    int res=dp[i][x][y];
                    if (res==-1) continue;
                    Max(dp[i+1][0][x],res);
                    if (x==1&&a[i-1]+a[i]<k*2) continue;
                    if (x==1&&y==1&&a[i-2]+a[i-1]+a[i]<k*3) continue;
                    Max(dp[i+1][1][x],res+1);
                }
        int ans=0;
        for (int i=0;i<2;i++)
            for (int j=0;j<2;j++)
                Max(ans,dp[n][i][j]);
        printf("%d\n",ans);
    }
}