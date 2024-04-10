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
LL C[105][105];
LL modset[10]={1097774749, 1076767633,100102021, 999997771,1001010013,1000512343,987654361, 999991231,999888733,987777733};
LL mod;
void build(){
    for(int i=0;i<=100;i++){
        C[i][0]=C[i][i]=1;
    }
    for(int i=1;i<=100;i++)
        for(int j=1;j<i;j++){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
        }
}
LL dp[105][10005];
int main(){
    srand(time(NULL));
    mod=modset[rand()%10];
    build();
    int n;
    scanf("%d",&n);
    int a[105];
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(n==2){
        printf("2\n");
        return 0;
    }
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=i-1;j>=0;j--){
            for(int k=10000-a[i];k>=0;k--){
                dp[j+1][k+a[i]]+=dp[j][k];
                dp[j+1][k+a[i]]%=mod;
            }
        }
    int cnt[105];
    MEM(cnt);
    vector<int> v;
    for(int i=1;i<=n;i++){
        cnt[a[i]]++;
        if(cnt[a[i]]==1)
        v.pb(a[i]);
    }
    if(v.size()==2){
        if(cnt[v[0]]*v[0]!=cnt[v[1]]*v[1]){
            printf("%d\n",n);
            return 0;
        }
    }
    int ans=1;
    for(int i=1;i<=100;i++){
        for(int j=cnt[i];j>0;j--){
            //printf("%d %d %d %d\n",i,j,C[cnt[i]][j],dp[j][j*i]);
            if(C[cnt[i]][j]==dp[j][j*i]){
                ans=max(ans,j);
                break;
            }
        }
    }
    printf("%d\n",ans);
}