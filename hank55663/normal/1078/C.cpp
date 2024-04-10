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
int mod=998244353; 
LL dp[300005][3];//hav nothav  nohave need
vector<int> v[300005];
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
void dfs(int x,int f){
    LL sum1=1,sum2=1,sum3=1;
    int zero,cnt=0;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
            if((dp[it][0]*2+dp[it][1])%mod==0){
                cnt++;
                zero=it;
            }
            else{
                sum1*=(dp[it][0]*2+dp[it][1])%mod;
                sum1%=mod;
            }
            sum2*=(dp[it][0]+dp[it][1])%mod;
            sum2%=mod;
            sum3*=(dp[it][0]*2+dp[it][1])%mod;
            sum3%=mod;
        }
    }
    dp[x][0]=0;
    dp[x][1]=sum2;
    dp[x][2]=sum3;
    if(cnt==2)
    return;
    for(auto it:v[x]){
        if(it!=f){
            if(cnt==1&&zero!=it)
            continue;
            dp[x][0]+=dp[it][2]*sum1%mod*f_pow(dp[it][1]+dp[it][0]*2,mod-2)%mod;
            dp[x][0]%=mod;
        }
    }/*
   dp[x][0]=dp[it][2]*other(dp[it][1]+dp[it][0]*2);
    dp[x][1]=sum2;//(dp[it][0]+dp[it][1])
    dp[x][2]=sum3;*/
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0);
    printf("%lld\n",(dp[1][0]+dp[1][1])%mod);
}