#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<long double,long double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acosl(-1)
//#define N 524288
#define ld long double
using namespace std;
int dp[3005][3005];
int mod=998244353;
int main(){
    int n,m;
    char s[3005],t[3005];
    scanf("%s %s",s,t);
    n=strlen(s);
    m=strlen(t);
    for(int i = 0;i<n;i++){
        if(i<m){
            if(t[i]==s[0])dp[i][i]=2;
        }
        else{
            dp[i][i]=2;
        }
    }
    for(int i = 1;i<n;i++){
        for(int j=0;j+i<=n;j++){
         //   printf("%d %d %d\n",j,i,dp[j][j+i-1]);
            if(j!=0&&(j-1>=m||s[i]==t[j-1])){
                dp[j-1][j+i-1]+=dp[j][j+i-1];
                dp[j-1][j+i-1]%=mod;
            }
            if(j+i!=n&&(j+i>=m||s[i]==t[j+i])){
                dp[j][j+i]+=dp[j][j+i-1];
                dp[j][j+i]%=mod;
            }
        }
    }
   // printf("%d\n",dp[0][3]);
    LL ans=0;
    for(int i = m-1;i<=n;i++)ans+=dp[0][i];
    printf("%lld\n",ans%mod);
}
/*
00 00
01 10
10 11
11 01

*/