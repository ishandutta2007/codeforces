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
#define MXN 1500
#define next Next
int h[10][10];
double dp[10][10];
pii next[10][10];
double DP(int x,int y){
    if(dp[x][y]>-0.5)return dp[x][y];
    //printf("%d %d %lf\n",x,y,dp[x][y]);
   // getchar();
    pii now=mp(x,y);
    double Y=0,X=1;
    for(int i=1;i<=6;i++){
        if(now==mp(0,0)){
            Y+=1.0/6;
        }
        else{
            now=next[now.x][now.y];
            X+=min(DP(now.x,now.y),DP(now.x-h[now.x][now.y],now.y))/6;
        }
    }
    dp[x][y]=X/(1-Y);
  //  printf("%d %d %lf\n",x,y,dp[x][y]);
    return dp[x][y];
}
int main(){
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++){
            dp[i][j]=-1;
            if(i%2==0){
                if(j==0){
                    next[i][j]=mp(i-1,j);
                }
                else
                next[i][j]=mp(i,j-1);
            }
            else{
                if(j==9)
                next[i][j]=mp(i-1,j);
                else
                next[i][j]=mp(i,j+1);
            }
            scanf("%d",&h[i][j]);
        }
    dp[0][0]=0;
    printf("%.12lf\n",DP(9,0));
}