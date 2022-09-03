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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 205
int dp[505][505];
int val[505][505];
int DP(int l,int r){
    if(dp[l][r]!=-1)return dp[l][r];
    dp[l][r]=r-l+1;
    for(int i = l;i<r;i++){
        int ll=DP(l,i);
        int rr=DP(i+1,r);
        if(ll==1&&rr==1&&val[l][i]==val[i+1][r]){
            val[l][r]=val[l][i]+1;
            dp[l][r]=1;
        }
        else{
            dp[l][r]=min(dp[l][r],ll+rr);
        }
    }
    return dp[l][r];
}
int main(){
    int n;
    scanf("%d",&n);
    int a[505];
    for(int i = 1;i<=n;i++)scanf("%d",&a[i]);
    MEMS(dp);
    for(int i = 1;i<=n;i++){
        dp[i][i]=1;
        val[i][i]=a[i];
    }
    printf("%d\n",DP(1,n));
}
/*
[1,2,4,3,5,6]
concat(sorted([4,2,1]),sorted([5,3,6]))
concat(shuffle([2,1]),shuffle([2,3]))
concat(shuffle([2,1,3]),shuffle([3]))
*/