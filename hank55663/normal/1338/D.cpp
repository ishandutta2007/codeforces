#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<long double,long double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acosl(-1)
//#define N 524288
#define ld long double
using namespace std;
vector<int> v[100005];
int dp[100005][2];
int ans=0;
void dfs(int x,int f){
    dp[x][1]=1;
    vector<int> v1,v2;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
            dp[x][1]=max(dp[x][1],dp[it][0]+1);
            v1.pb(dp[it][0]);
            v2.pb(max(dp[it][0],dp[it][1])-1);
        }
    }
    sort(v1.begin(),v1.end());
    reverse(v1.begin(),v1.end());
    v1.pb(0);
    v1.pb(0);
    ans=max(ans,v1[0]+v1[1]+1);
    sort(v2.begin(),v2.end());
    reverse(v2.begin(),v2.end());
    v2.pb(0);
    v2.pb(0);
    ans=max(ans,v2[0]+v2[1]+(int)v[x].size());
    int tmp=0;
    for(auto it:v[x]){
        if(it!=f){
            dp[x][0]=max(dp[x][0]+1,tmp+max(dp[it][0],dp[it][1]));
            tmp++;
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    /*for(int i = 1;i<=n;i++){
        if(v[i].size()==1)tot++;
    }*/
   dfs(1,0);
   printf("%d\n",ans);
}
/*
00 00
01 10
10 11
11 01

*/