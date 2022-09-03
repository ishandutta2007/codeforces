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
int cnt[26][26];
int cnt2[1<<20][20];
int dp[1<<20];
int m;
int DP(int x){
    if(dp[x]!=-1)return dp[x];
    int dis=__builtin_popcount(x)-1;
    dp[x]=1e9;
    for(int i=0;i<m;i++){
        if(((1<<i)&x))
        dp[x]=min(dp[x],DP(x-(1<<i))+dis*cnt2[x][i]);
    }
    return dp[x];
}
int main(){
    int n;
    scanf("%d %d",&n,&m);
    char c[200005];
    scanf("%s",c);
    for(int i = 0;c[i+1]!=0;i++){
        cnt[c[i]-'a'][c[i+1]-'a']++;
        cnt[c[i+1]-'a'][c[i]-'a']++;
    }
    for(int i = 0;i<(1<<m);i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<m;k++){
                if(k==j)continue;
                if((1<<k)&i){
                    cnt2[i][j]+=cnt[k][j];
                }
                else{
                    cnt2[i][j]-=cnt[k][j];
                }
            }
        }
    }
    MEMS(dp);
    for(int i= 0;i<m;i++)
        dp[1<<i]=0;
    int ans=2e9;
    for(int i=0;i<m;i++)
        ans=min(ans,DP((1<<m)-1));
    printf("%d\n",ans);
}