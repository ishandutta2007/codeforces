#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
#define N 200005
#define less Less
int mod=1e9+7;
int main(){
    int n;
    scanf("%d",&n);
    char c[1005];
    scanf("%s",c+1);
    int d[26];
    for(int i = 0;i<26;i++)
        scanf("%d",&d[i]);
    LL dp[1005];
    LL dp2[1005];
    dp[0]=1;
    dp2[0]=0;
    int Max=0;
    for(int i = 1;i<=n;i++){
        int Min=d[c[i]-'a'];
        dp2[i]=1e9;
        for(int j=i-1;j>=0;j--){
            if(Min>=i-j){
                dp[i]+=dp[j];
                dp2[i]=min(dp2[i],dp2[j]+1);
                Max=max(Max,i-j);
            }
            else{
                break;
            }
            Min=min(Min,d[c[j]-'a']);
        }
        dp[i]%=mod;
    }
    printf("%lld\n%d\n%lld\n",dp[n],Max,dp2[n]);
}