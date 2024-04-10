/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<assert.h>
#include<map>
#include<set>
#include<utility>
#include<iostream>
#include<cmath>
#include<sstream>
#include<queue>
#include<bitset>*/
#include<bits/stdc++.h>
#define LL long long
#define pll pair<LL,LL>
#define pii pair<int,int> 
#define pdd pair<double,double>
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define x first
#define y second
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
#define search Search
#define index Index
#define transform Transform
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
LL mod=1e9+7;
int main(){
    int n;
    scanf("%d",&n);
    int dp[1000005];
    MEM(dp);
    dp[0]=1;
    LL res=0;
    for(int i=1;i<=n;i++){
        int a;
        scanf("%d",&a);
        vector<int> v,v2;
        for(int j=1;j*j<=a;j++){
            if(a%j==0){
                v.pb(j);
                if(j*j!=a)
                v2.pb(a/j);
            }
        }
        reverse(v.begin(),v.end());
        for(auto it:v2){
            dp[it]+=dp[it-1];
            dp[it]%=mod;
            res+=dp[it-1];
            res%=mod;
        }
        for(auto it:v){
            dp[it]+=dp[it-1];
            dp[it]%=mod;
            res+=dp[it-1];
            res%=mod;
        }
      // printf("%d\n",res);
    }
    printf("%lld\n",res);
}