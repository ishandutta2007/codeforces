#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 1500
int mod=1e9+7;
int main(){
    char c[100005];
    scanf("%s",c+1);
    int dp[100005];
    dp[0]=1;
    dp[1]=1;
    if(c[1]=='m'||c[1]=='w'){
        printf("0\n");
        return 0;
    }
    for(int i=2;c[i]!=0;i++){
        dp[i]=dp[i-1];
        if((c[i]=='u'||c[i]=='n')&&c[i-1]==c[i])
        {
            dp[i]=(dp[i]+dp[i-2])%mod;
        }
        if(c[i]=='m'||c[i]=='w'){
            printf("0\n");
            return 0;
        }
    }
    printf("%d\n",dp[strlen(c+1)]);
}