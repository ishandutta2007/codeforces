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
LL dp[505][505];
int c[505];
int mod=998244353;
LL DP(int l,int r){
   // printf("%d %d\n",l,r);
 //   getchar();
    if(l>r)return 1;
    if(l==r)return 1;
    if(dp[l][r]!=-1)return dp[l][r];
    int Min=1e9,Mini;
    for(int i = l;i<=r;i++){
        if(c[i]<=Min){
            Min=c[i];
            Mini=i;
        }
    }   
    LL suml=0,sumr=0;
    for(int i = l;i<=Mini;i++){
        suml+=DP(l,i-1)*DP(i,Mini-1)%mod;
        suml%=mod;
    }
    for(int i = Mini+1;i<=r+1;i++){
        sumr+=DP(Mini+1,i-1)*DP(i,r)%mod;
        sumr%=mod;
    }
    dp[l][r]=suml*sumr%mod;
   // printf("%d %d %lld %lld %lld\n",l,r,dp[l][r],suml,sumr);
    return dp[l][r];
}
int main(){
    MEMS(dp);
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i<m;i++)
        scanf("%d",&c[i]);
    printf("%lld\n",DP(0,m-1));
}
/*
1 
2 6 
3 5 
4
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1

if(c[n-(r-l+1)]==)
dp[l][r]
dp[]
1 3 4 2
*/