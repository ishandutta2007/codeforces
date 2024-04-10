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
#define LL unsigned long long
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
LL dp[40][40][40];
LL cal(LL x){
    MEM(dp);
    vector<int> c;
    LL k=x;
    while(k){
        c.pb(k&1);
        k>>=1;
    }
    reverse(c.begin(),c.end());
    int a=0,b=0;
    for(int i=0;i<c.size();i++){
        for(int j=0;j<c[i];j++){
            if(i==0&&j==0)continue;
            dp[i][a+1][b]++;
        }
        if(c[i]==0)
        a++;
        else
        b++;
    }
    for(int i=1;i<c.size();i++){
        dp[i][0][1]++;
    }
    for(int i=1;i<c.size();i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<39;k++){
                for(int l=0;l<39;l++){
                    int aa=k,bb=l;
                    if(j==0)
                    aa++;
                    else
                    bb++;
                    dp[i][aa][bb]+=dp[i-1][k][l];
                }
            }
        }
    }
    LL tot=0;
    int len=c.size()-1;
    for(int i=0;i<40;i++){
        for(int j=0;j<=i;j++)
//        printf("%d %d %d\n",x,j,dp[len][j][1]);
        tot+=dp[len][i][j];
    }
    return tot;
}
int main(){
    string s;  
    int n;
    cin>>n>>s;
    for(int i=0;i<s.size()-1;i++){
        if(s[i]!=s[i+1]){
            printf("YES\n%c%c",s[i],s[i+1]);
            return 0;
        }
    }
    printf("NO\n");
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