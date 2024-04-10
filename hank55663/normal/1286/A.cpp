#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500
#define N 100005
int dp[105][105][105][2];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++)
                dp[i][j][k][0]=dp[i][j][k][1]=1e9;
        }
    }
    int odd=(n+1)/2,even=n/2;
    int a[105];
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]!=0){
            if(a[i]%2)odd--;
            else even--;
        }
    }
    if(a[1]==0){
        dp[1][odd][even-1][0]=0;
        dp[1][odd-1][even][1]=0;
    }
    else{
        if(a[1]%2){
            dp[1][odd][even][1]=0;
        }
        else{
            dp[1][odd][even][0]=0;
        }
    }
    for(int i = 2;i<=n;i++){
        for(int j=0;j<=odd;j++){
            for(int k = 0;k<=even;k++){
                if(a[i]==0){
                    dp[i][j][k][0]=min(dp[i-1][j][k+1][0],dp[i-1][j][k+1][1]+1);
                    dp[i][j][k][1]=min(dp[i-1][j+1][k][0]+1,dp[i-1][j+1][k][1]);
                }
                else{
                    if(a[i]%2){
                        dp[i][j][k][1]=min(dp[i-1][j][k][1],dp[i-1][j][k][0]+1);
                    }
                    else
                    {
                        dp[i][j][k][0]=min(dp[i-1][j][k][0],dp[i-1][j][k][1]+1);
                    }
                }
            }
        }
    }
    printf("%d\n",min(dp[n][0][0][1],dp[n][0][0][0]));
}