/*#include<utility>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<iostream>
#include<string.h>*/
#include<bits/stdc++.h>
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
using namespace std;
typedef long long LL;
int main(){
    int dp[155];
    MEMS(dp);
    dp[0]=0;
    for(int i=0;i<105;i++){
        for(int j=2;j<=7;j++){
            if(dp[i]!=-1){
                dp[i+j]=dp[i]+1;
            }
        }
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int x;
        scanf("%d",&x);
        printf("%d\n",dp[x]);
    }
}
/*
0 1 0
0 0 1
1 0 1
*/