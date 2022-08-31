#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
const int maxn=55;
char c[55];
int s[55][55],a[55][55],dp[55][55][55][55],n;
void Min(int &x,int y){if (y<x) x=y;}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%s",c+1);
        for (int j=1;j<=n;j++) a[i][j]=c[j]=='#';
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
    for (int r=1;r<=n;r++)
    for (int c=1;c<=n;c++)
    for (int i=1;i<=n-r+1;i++){
        int ii=i+r-1;
        for (int j=1;j<=n-c+1;j++){
            int jj=j+c-1;
            int &ret=dp[i][ii][j][jj];
            if (s[ii][jj]+s[i-1][j-1]-s[ii][j-1]-s[i-1][jj]==0){
                ret=0;
            } else {
                ret=max(r,c);
                for (int p=i;p<ii;p++)
                    Min(ret,dp[i][p][j][jj]+dp[p+1][ii][j][jj]);
                for (int p=j;p<jj;p++)
                    Min(ret,dp[i][ii][j][p]+dp[i][ii][p+1][jj]);
            }
        }
    }
    cout << dp[1][n][1][n] << endl;
    return 0;
}