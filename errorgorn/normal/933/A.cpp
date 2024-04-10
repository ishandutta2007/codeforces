#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int arr[2005];
int memo[2005][4];
int dp(int i,int j){
    if (memo[i][j]!=-1) return memo[i][j];
    else{
        int best=1;
        for (int x=i+1;x<n;x++){
            if (arr[x]==1){
                if (j==0)  best=max(best,1+dp(x,0));
                else if (j<=2) best=max(best,1+dp(x,2));
            }
            else{
                if (j<=1) best=max(best,1+dp(x,1));
                else best=max(best,1+dp(x,3));
            }
        }
        //printf("%d %d %d\n",i,j,best);
        return memo[i][j]=best;
    }
}
int main(){
    memset(memo,-1,sizeof(memo));
    scanf("%d",&n);
    for (int x=0;x<n;x++){
        scanf("%d",&arr[x]);
    }    
    
    int ans=0;
    for (int x=0;x<n;x++){
        if (arr[x]==1) ans=max(ans,dp(x,0));
        else ans=max(ans,dp(x,1));
    }
    
    printf("%d\n",ans);
}