#include<bits/stdc++.h>
/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
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
void solve(){
    int n;
    scanf("%d",&n);
    char c[200005];
    scanf("%s",c+1);
    c[n+1]=c[1];
    c[n+2]=c[2];
    c[n+3]=c[3];
    int ans=1e9;
    for(int i = 1;i<=4;i++){
        int dp[200005];
        dp[i-1]=0;
        dp[i]=1e9;
        for(int j = i+1;j<n+i;j++){
            dp[j]=1e9;
            int cnt=0;
            if(c[j]!='L')cnt++;
            if(c[j-1]!='R')cnt++;
            dp[j]=dp[j-2]+cnt;
            if(j>i+1){
                cnt=0;
                if(c[j]!='L')cnt++;
                if(c[j-2]!='R')cnt++;
                dp[j]=min(dp[j-3]+cnt,dp[j]);
            }
            if(j>i+2){
                cnt=0;
                if(c[j]!='L')cnt++;
                if(c[j-1]!='L')cnt++;
                if(c[j-2]!='R')cnt++;
                if(c[j-3]!='R')cnt++;
                dp[j]=min(dp[j-4]+cnt,dp[j]);
            }
         //   printf("%d ",dp[j]);
        }
        //printf("\n");
        ans=min(ans,dp[n+i-1]);
    }
    printf("%d\n",ans);
}
int main(){
    int t=1;
    scanf("%d",&t);
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