#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define pii pair<int,int>
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
vector<int> v[205];
int a[205];
int dp[205][205];
int k;
void dfs(int x,int f){
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
        }
    }
    for(int i=1;i<=k;i++){
        int temp=0;
        for(auto it:v[x]){
            dp[x][i]+=dp[it][max(k-i,i-1)];
            dp[x][i]=max(dp[x][i],dp[it][i-1]+temp);
            temp+=dp[it][max(k-i,i-1)];
           // dp[x][i]+=dp[it][i-1];
        }
    }
    for(auto it:v[x]){
        dp[x][0]+=dp[it][k];
    }
    dp[x][0]+=a[x];
    //printf("%d ",x);
    for(int i=201;i>=0;i--){
        dp[x][i]=max(dp[x][i],dp[x][i+1]);
      //  if(i<=5)printf("%d ",dp[x][i]);
    }
   // printf("\n");
}
int main(){
    int n;
    scanf("%d %d",&n,&k);
    for(int i = 1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0);
    printf("%d\n",dp[1][0]);
}