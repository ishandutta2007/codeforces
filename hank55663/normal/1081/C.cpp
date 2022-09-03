/*#include<utility>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<iostream>
#include<string.h>*/
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
typedef long long LL ;
int mod=998244353;
LL dp[2005][2005];
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    dp[1][0]=m;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=k;j++){
            dp[i][j]+=dp[i-1][j];
            if(j!=0)
            dp[i][j]+=dp[i-1][j-1]*(m-1);
            dp[i][j]%=mod;
        }
    }
   printf("%lld\n",dp[n][k]);
}
/*
0 1 0
0 0 1
1 0 1
*/