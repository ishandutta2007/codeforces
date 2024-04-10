#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
#define N 1000000
#define Point pdd
#define Polygon vector<Point>
#define Line pair<Point,Point>
int dp[105][10005];
bool solve(){
    int n;
    scanf("%d",&n);
    int a[105],b[105];
    int tot=0;
    for(int i = 1;i<=n;i++){
        scanf("%d %d",&a[i],&b[i]);
        tot+=b[i];
    }
    for(int i =0;i<105;i++){
        for(int j  =0;j<10005;j++){
            dp[i][j]=-1e9;
        }
    }
    dp[0][0]=0;
    int tota=0;
    for(int i = 1;i<=n;i++){
        for(int j = i-1;j>=0;j--){
            for(int k = 0;k<=tota;k++){
                dp[j+1][k+a[i]]=max(dp[j+1][k+a[i]],dp[j][k]+b[i]);
            }
        }
        tota+=a[i];
    }
    for(int i = 1;i<=n;i++){
        int Max=0;
        for(int j = 0;j<=tota;j++){
            Max=max(Max,min(dp[i][j]+tot,j*2));
         //   printf("%d %d %d\n",i,j,dp[i][j]);
        }
        printf("%d",Max/2);
        if(Max%2)printf(".5");
        printf(" ");
    }
    printf("\n");
}
int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--)solve();
}
/*
1 4 10100
1 6 1010100
1 8 101010100
1 y 10100  (y+1)  y/2
2 5 1100100
2 6 11001100
2 7 110011000
2 8 1100110000
2 9 11001100100
*/