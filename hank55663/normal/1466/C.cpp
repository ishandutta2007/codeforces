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
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define Point pdd
#define Polygon vector<Point>
#define Line pair<Point,Point>
#define N 1000000
int dp[100005][4];
bool solve(){
    char c[100005];
    scanf("%s",c);
    if(strlen(c)==1){
        printf("0\n");
        return true;
    }
    else if(strlen(c)==2){
        if(c[0]==c[1])printf("1\n");
        else printf("0\n");
        return true;
    }
    dp[0][0]=0;
    dp[0][1]=0;
    if(c[0]==c[1])
    dp[1][0]=1e9;
    else dp[1][0]=0;
    dp[1][1]=1;
    dp[1][2]=1;
    dp[1][3]=2;
    for(int i = 2;c[i]!=0;i++){
        if(c[i]==c[i-2]){
            dp[i][0]=dp[i-1][2];
            dp[i][1]=min(dp[i-1][2],dp[i-1][0])+1;
            dp[i][2]=dp[i-1][3];
            dp[i][3]=min(dp[i-1][1],dp[i-1][3])+1;
        }
        else{
            dp[i][0]=min(dp[i-1][2],dp[i-1][0]);
            dp[i][1]=min(dp[i-1][2],dp[i-1][0])+1;
            dp[i][2]=min(dp[i-1][3],dp[i-1][1]);
            dp[i][3]=min(dp[i-1][1],dp[i-1][3])+1;
        }
        if(c[i]==c[i-1]){
            dp[i][0]=1e9;
        }
    }
    int len=strlen(c)-1;
    printf("%d\n",min(min(dp[len][0],dp[len][1]),min(dp[len][2],dp[len][3])));
    return true;
}
int main(){
    int t=1;00000;
    scanf("%d",&t);
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