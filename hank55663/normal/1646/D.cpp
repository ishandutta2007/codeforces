#include<bits/stdc++.h>
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#pragma GCC optimize("O3,unroll-loops")
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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
pll dp[200005][2];
vector<int> v[200005];
void dfs(int x,int f){
    dp[x][0]=mp(0,0);
    dp[x][1]=mp(1,-(int)v[x].size());
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
            pii p1=max(dp[it][0],dp[it][1]);
            dp[x][0].x+=p1.x;
            dp[x][0].y+=p1.y;
            dp[x][1].x+=dp[it][0].x;
            dp[x][1].y+=dp[it][0].y;
        }
    }
}
int val[200005];
void dfs2(int x,int a,int f){
   // printf("%d %d\n",x,a);
    if(a==0)val[x]=1;
    else val[x]=v[x].size();
    for(auto it:v[x]){
        if(it!=f){
            if(a==1)dfs2(it,0,x);
            else{
                if(dp[it][0]>dp[it][1])dfs2(it,0,x);
                else dfs2(it,1,x);
            }
        }
    }
}
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    if(n==2){
        printf("2 2\n1 1\n");
    }
    else{
        dfs(1,0);
        pll p=max(dp[1][0],dp[1][1]);
        printf("%lld %lld\n",p.x,-p.y+n-p.x);
        if(p==dp[1][0])dfs2(1,0,0);
        else dfs2(1,1,0);
        for(int i = 1;i<=n;i++)printf("%d ",val[i]);
        printf("\n");
    }
}
int main(){
    int t=1;0000;
//    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}