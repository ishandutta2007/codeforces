#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
int dp[1000005][4];
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    if(n>=4&&m>=4){
        printf("-1\n");
    }
    else if(n==1||m==1){
        printf("0\n");
    }
    else{
      //  int swap=0;
        char c[4][1000005];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(n<m)scanf(" %c",&c[i][j]),c[i][j]-='0';
                else scanf(" %c",&c[j][i]),c[i][j]-='0';
            }
        }
        if(n>m)swap(n,m);
        if(n==2){
            if((c[0][0]+c[1][0])%2){
                dp[0][0]=1;
            }
            else{
                dp[0][1]=1;
            }
            for(int i = 1;i<m;i++){
                if((c[0][i]+c[1][i])%2){
                    dp[i][0]=dp[i-1][1]+1;
                    dp[i][1]=dp[i-1][0];
                }
                else{
                    dp[i][1]=dp[i-1][0]+1;
                    dp[i][0]=dp[i-1][1];
                }
            }
            printf("%d\n",min(dp[m-1][0],dp[m-1][1]));
        }
        else if(n==3){
            int x=(c[0][0]+c[1][0])%2,y=(c[1][0]+c[2][0])%2;
            int a=(x<<1)+y;
            for(int j  =0;j<4;j++){
                if(j!=a)
                dp[0][j]=1;
            }
            for(int i = 1;i<m;i++){
                int x=(c[0][i]+c[1][i])%2,y=(c[1][i]+c[2][i])%2;
                int a=(x<<1)+y;
                for(int j =0;j<4;j++){
                    if(j!=a){
                        dp[i][j]=dp[i-1][3-j]+1;
                    }
                    else{
                        dp[i][j]=dp[i-1][3-j];
                    }
                }
            }
             printf("%d\n",min(min(dp[m-1][0],dp[m-1][1]),min(dp[m-1][2],dp[m-1][3])));
        }
    }
}
int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/