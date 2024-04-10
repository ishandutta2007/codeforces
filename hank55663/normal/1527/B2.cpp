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
#define last Last
#define MXN 200005
int dp[1005][1005][2][2];
int vis[1005][1005][2][2];
int DP(int a,int b,int x,int y){
    if(vis[a][b][x][y])return dp[a][b][x][y];
    if(a==0&&b==0&&y==1)return dp[a][b][x][y]=0;
    dp[a][b][x][y]=1e9;
    vis[a][b][x][y]=1;
    if(x==0&&a){
        dp[a][b][x][y]=min(dp[a][b][x][y],-DP(a,b,1,y));
    }
    if(y==0){
        dp[a][b][x][y]=min(dp[a][b][x][y],1-DP(a,b,0,1));
    }
    if(a){
        dp[a][b][x][y]=min(dp[a][b][x][y],1-DP(a-1,b,0,y));
    }
    if(b){
        dp[a][b][x][y]=min(dp[a][b][x][y],1-DP(a+1,b-1,0,y));
    }
    return dp[a][b][x][y];
}
void solve(){
    int n;
    scanf("%d",&n);
    char c[1005];
    scanf("%s",c);
    int a=0,b=0,x=0,y=1;
    for(int i = 0,r=n-1;i<r;i++,r--){
        if(c[i]==c[r]&&c[i]=='0')b++;
        if(c[i]!=c[r])a++;
    }
    if(n%2==1&&c[n/2]=='0')y=0;
    int ans=DP(a,b,x,y);
    if(ans>0)printf("BOB\n");
    else if(ans==0)printf("DRAW\n");
    else printf("ALICE\n");
}
int main(){
    int t=1;
    scanf("%d",&t);
    MEMS(dp);
    while(t--)
        solve();
    /*int t=1;00000;
    scanf("%d",&t);
    while(t--){
        solve();
    }*/
}
/*

*/