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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 300000
#define N 100005
int dp[85][100005];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    pii p[85];
    for(int i = 1;i<=n;i++)
        scanf("%d %d",&p[i].x,&p[i].y);
    sort(p+1,p+n+1);
    for(int i = 1;i<=m;i++){
        for(int j=0;j<=n;j++)
            dp[j][i]=1e9;
    }
    for(int i=1;i<=n;i++){
        for(int j =1;j<=m;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=p[i].x){
                int val=0;
                int sub=max(j-p[i].x,p[i].y);
                if(i==1){
                    sub=max(max(j-p[i].x,p[i].x-1),p[i].y);
                    val=sub-p[i].y;
                }
                else{
                    val=sub-p[i].y;
                }
               // printf("%d %d %d\n",i,j,val);
                if(p[i].x-sub>0){
                    val+=dp[i-1][p[i].x-sub-1];
                }
                dp[i][j]=min(dp[i][j],val);
                sub=max(max(j-p[i].x,p[i].x-1),p[i].y);
                val=sub-p[i].y;
                if(p[i].x-sub>0){
                    val+=dp[i-1][p[i].x-sub-1];
                }
                dp[i][j]=min(dp[i][j],val);
            }
        }
        for(int j=m;j>1;j--){
            dp[i][j-1]=min(dp[i][j-1],dp[i][j]);
        }
    }
    printf("%d\n",dp[n][m]);
}