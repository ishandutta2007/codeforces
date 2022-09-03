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
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define last Last
#define MXN 200005
int cost[5005][5005];
void solve(){
    int n;
    scanf("%d",&n);
    int a[5005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 1;i<=n;i++){
        queue<int> v1,v2;
        int sum=0;
        for(int j = i;j<=n;j++){
            if(a[j]==0){
                if(v2.size()){
                    sum+=j-v2.front();
                    v2.pop();
                }
                else{
                    v1.push(j);
                }
            }
            else{
                if(v1.size()){
                    sum+=j-v1.front();
                    v1.pop();
                }
                else{
                    v2.push(j);
                }
            }
            if(v1.empty()&&v2.empty())cost[i][j]=sum;
            else cost[i][j]=1e9;
        }
    }
    int dp[5005];
    dp[0]=0;
    for(int i = 1;i<=n;i++){
        if(a[i]==0)dp[i]=dp[i-1];
        else dp[i]=1e9;
        for(int j = 0;j<i;j++){
            dp[i]=min(dp[i],dp[j]+cost[j+1][i]);
        }
    }
    printf("%d\n",dp[n]);
}
int main(){
    int t=1;
 //   scanf("%d",&t);
    while(t--)
        solve();
    /*int t=1;00000;
    scanf("%d",&t);
    while(t--){
        solve();
    }*/
}
/*
a b
b a
b a a
a a b
a a b b
a b b a
a b b a a
a b a a b
a b a b a

*/