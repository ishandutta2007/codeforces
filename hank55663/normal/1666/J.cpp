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
int a[205][205];
LL val[205][205][205];
LL cost[205][205];
int root[205][205];
LL dp[205][205];
LL DP(int l,int r){
    if(dp[l][r]!=-1)return dp[l][r];
    dp[l][r]=1e18;
    for(int i = l;i<=r;i++){
        LL res=0;
        if(i!=l)res+=DP(l,i-1),res+=cost[l][i-1];
        if(i!=r)res+=DP(i+1,r),res+=cost[i+1][r];
        if(res<dp[l][r]){
            dp[l][r]=res;
            root[l][r]=i;
        }
    }
    return dp[l][r];
}
int ans[205];
void go(int l,int r,int ro){
    if(l>r)return;
    ans[root[l][r]]=ro;
    go(l,root[l][r]-1,root[l][r]+1);
    go(root[l][r]+1,r,root[l][r]+1);
}
void solve(){
    MEMS(dp);
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            for(int k = j;k<n;k++){
                val[i][j][k]=a[i][k];
                if(j!=k)val[i][j][k]+=val[i][j][k-1];
            }
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = i;j<n;j++){
            for(int k =0;k<n;k++){
                if(k<i||k>j){
                    cost[i][j]+=val[k][i][j];
                }
            }
        }
    }
   // printf("%lld\n",DP(0,n-1));
   DP(0,n-1);
    go(0,n-1,0);
    for(int i = 0;i<n;i++)printf("%d ",ans[i]);
    printf("\n");
}
int main(){
    int t=1;00000;
  //  scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
p*t = a^2+b^2
q*t = ab
(p+2*q)*t=(a+b)^2
*/