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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define MXN 3000000
int mod=1e9+7;
void solve(int T){
    int n;
    scanf("%d",&n);
    int dp[100005];
    char c[2][100005];
    scanf("%s %s",c[0]+1,c[1]+1);
    dp[0]=0;
    if(c[0][1]=='1'&&c[1][1]=='1')dp[1]=0;
    else if(c[0][1]=='0'&&c[1][1]=='0')dp[1]=1;
    else dp[1]=2;
    for(int i = 2;i<=n;i++){
        int cnt[2]={0,0};
        cnt[c[0][i]-'0']++;
        cnt[c[1][i]-'0']++;
        if(cnt[0]){
            if(cnt[1])dp[i]=dp[i-1]+2;
            else dp[i]=dp[i-1]+1;
        }
        else dp[i]=dp[i-1];
        cnt[c[0][i-1]-'0']++;
        cnt[c[1][i-1]-'0']++;
         if(cnt[0]){
            if(cnt[1])dp[i]=max(dp[i],dp[i-2]+2);
            else dp[i]=max(dp[i],dp[i-2]+1);
        }
        else dp[i]=max(dp[i],dp[i-1]);
    }
    printf("%d\n",dp[n]);
}
int main(){
    int t=1;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve(i);
    }
    return 0;
}
/*
000010000
001010000
001010100
001011100

1 1 2
1 1 2 1
2 1
2


XOXOXOXOOXOXXOXOXOXOOXOX
*/