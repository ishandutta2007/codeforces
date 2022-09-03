#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
int dp[205][205][205];
void solve(){
    vector<int> rr,gg,bb;
    int r,g,b;
    scanf("%d %d %d",&r,&g,&b);
    for(int i = 0;i<r;i++){
        int x;
        scanf("%d",&x);
        rr.pb(x);
    }
    for(int i = 0;i<g;i++){
        int x;
        scanf("%d",&x);
      //  cnt[x][1]++;
        gg.pb(x);
    }
    for(int i = 0;i<b;i++){
        int x;
        scanf("%d",&x);
        //cnt[x][2]++;
        bb.pb(x);
    }
    sort(rr.begin(),rr.end());
    reverse(rr.begin(),rr.end());
    sort(gg.begin(),gg.end());
    reverse(gg.begin(),gg.end());
    sort(bb.begin(),bb.end());
    reverse(bb.begin(),bb.end());
    for(int i = 0;i<=rr.size();i++){
        for(int j = 0;j<=gg.size();j++){
            for(int k = 0;k<=bb.size();k++){
                if(i!=r&&j!=g)
                dp[i+1][j+1][k]=max(dp[i+1][j+1][k],dp[i][j][k]+rr[i]*gg[j]);
                if(i!=r&&k!=b)
                dp[i+1][j][k+1]=max(dp[i+1][j][k+1],dp[i][j][k]+rr[i]*bb[k]);
                if(j!=g&&k!=b)
                dp[i][j+1][k+1]=max(dp[i][j+1][k+1],gg[j]*bb[k]+dp[i][j][k]);
            }
        }
    }
    int ans=0;
    for(int i = 0;i<=r;i++){
        for(int j =0;j<=g;j++){
            for(int k = 0;k<=b;k++){
               // printf("%d %d %d %d\n",i,j,k,dp[i][j][k]);
                ans=max(ans,dp[i][j][k]);
            }
        }
    }
    printf("%d\n",ans);
}
int main(){
    int t=1;
    //scanf("%d",&t);
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