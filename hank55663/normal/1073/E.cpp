#include<stdio.h>
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
#include<bitset>
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
int mod=998244353;
pll dp[20][1<<10];
LL cal(LL x,int K){
    MEM(dp);
    char c[20];
    sprintf(c,"%lld",x);
    int val=0;
    LL sum=0;
    for(int i=0;c[i]!=0;i++){
        for(int j=0;j<c[i]-'0';j++){
            if(i==0&&j==0)
            continue;
            dp[i][val|(1<<j)].x+=(sum*10+j)%mod;
            dp[i][val|(1<<j)].x%=mod;
            dp[i][val|(1<<j)].y++;
        }
        val|=1<<(c[i]-'0');
        sum=sum*10+c[i]-'0';
        sum%=mod;
    }
    for(int i=1;c[i]!=0;i++){
        for(int j=1;j<=9;j++){
            dp[i][1<<j].x+=j;
            dp[i][1<<j].y++;
        }
    }
    for(int i=1;c[i]!=0;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<(1<<10);k++){
                dp[i][k|(1<<j)].x+=dp[i-1][k].x*10+dp[i-1][k].y*j;
                dp[i][k|(1<<j)].x%=mod;
                dp[i][k|(1<<j)].y+=dp[i-1][k].y;
                dp[i][k|(1<<j)].y%=mod;
            }
        }
    }
    //printf("?\n");
    int len=strlen(c)-1;
    LL ret=0;
    for(int i=0;i<(1<<10);i++){
        int k=i,tot=0;
        while(k){
            if(k&1)tot++;
            k>>=1;
        }
        if(tot<=K){
            ret+=dp[len][i].x;
            ret%=mod;
        }
    }
    return ret;
}
int main(){
    LL l,r;
    int k;
    scanf("%lld %lld %d",&l,&r,&k);
    /*for(int i=1;i<=100;i++)
    printf("%d %lld\n",i,cal(i,k));
    printf("%lld\n",cal(r+1,k));*/
    printf("%lld\n",((cal(r+1,k)-cal(l,k))%mod+mod)%mod);
}
/*
21 3
3 1
4 1
5 1
6 2
7 2
8 2
1 2
9 1
9 10
9 11
9 12
10 13
10 14
10 15
11 16
11 17
11 18
12 19
12 20
12 21

*/