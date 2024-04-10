#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <ctime>
#include <memory.h>
#include <string>
#include <sstream>
#include <map>

#define ll long long

using namespace std;

int mod=1000000007;
int dp[5002][5002];
char s[5002],t[5002];

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    gets(s); gets(t);
    dp[0][0]=0;
    int n=strlen(s),m=strlen(t),sum[2][5002]={0},cur=0,next=1;
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            if (s[i-1]==t[j-1]) {
                dp[i][j]=1+sum[cur][j-1];
                if (dp[i][j]>=mod) dp[i][j]-=mod;
                sum[next][j]=dp[i][j]+sum[next][j-1];
                if (sum[next][j]>=mod) sum[next][j]-=mod;
//              for(int e=0;e<j;++e) {
//                  dp[i][j]=(dp[i][j]+dp[i-1][e])%mod;
//              }
            } else sum[next][j]=sum[next][j-1];
//          cout << dp[i][j] << "   ";
        }
//      cout << endl;
        memset(sum[cur],0,sizeof(sum[cur]));
        cur^=1; next^=1;
    }
    int ans=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j) {
            ans+=dp[i][j];
            if (ans>=mod) ans-=mod;
        }
    cout << ans << endl;
    return 0;
}