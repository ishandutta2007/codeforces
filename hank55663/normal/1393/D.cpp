#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
using namespace std;
int dp[2005][2005];
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    //MEM(dp);
    char c[2005][2005];
    for(int i= 2;i<=n+1;i++){
        scanf("%s",c[i]+2);
    }
    LL ans=0;
    for(int i = 0;i<26;i++){
        for(int j=2;j<=n+1;j++){
            for(int k = 2;k<=m+1;k++){
                if(c[j][k]==i+'a'){
                    dp[j][k]=min(min(dp[j-1][k-1],dp[j-1][k]),min(dp[j-1][k+1],dp[j-2][k]))+1;
                    ans+=dp[j][k];//*(dp[j][k]+1)/2;
                    
                }
                else{
                    dp[j][k]=0;
                }
              //  printf("%d ",dp[j][k]);
            }
          //  printf("\n");
        }
    }
    printf("%lld\n",ans);
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