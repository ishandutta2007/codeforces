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
int pool[1005][2005];
int* dp[1005];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    char c[1005];
    scanf("%s",c);
    for(int i =0;i<=n;i++){
        dp[i]=pool[i]+1001;
    }
    MEM(pool);
    dp[0][0]=1;
    for(int i =0;i<n;i++){
        for(int j =-k+1;j<=k-1;j++){
            if(dp[i][j]){
                if(c[i]=='W'){
                    dp[i+1][j+1]=1;
                }
                else if(c[i]=='D'){
                    dp[i+1][j]=2;
                }
                else if(c[i]=='L'){
                    dp[i+1][j-1]=3;
                }
                else{
                    dp[i+1][j+1]=1;
                    dp[i+1][j]=2;
                    dp[i+1][j-1]=3;
                }
            }
        }
    }
    int now=1e9;
    if(dp[n][k]){
        now=k;
    }
    if(dp[n][-k]){
        now=-k;
    }
    if(now==1e9){
        printf("NO\n");
    }
    else{
        vector<char> v;
        char c[5]=" WDL";
        for(int j = n;j>=1;j--){
            v.pb(c[dp[j][now]]);
            now=now+dp[j][now]-2;
        }
        reverse(v.begin(),v.end());
        for(auto it:v)
        printf("%c",it);
        printf("\n");
    }
}