#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
#define N 262144
int dp[100005][2];
vector<pii> v[100005];
int n,k;
void dfs(int x,int f){
    vector<pii> vv;
    for(auto it:v[x]){
        if(it.x!=f){
            dfs(it.x,x);
            vv.pb(mp(dp[it.x][0]+it.y,dp[it.x][1]+it.y));
        }
    }
    sort(vv.begin(),vv.end());
    reverse(vv.begin(),vv.end());
    for(int i = 0;i<k&&i<vv.size();i++){
        dp[x][0]+=vv[i].x;
    }
    int sum=dp[x][0];
    if(vv.size()>k)sum+=vv[k].x;
    for(int i = k;i<vv.size();i++){
        dp[x][1]=max(dp[x][1],dp[x][0]+vv[i].y);
    }
    for(int i = 0;i<=k&&i<vv.size();i++){
        dp[x][1]=max(dp[x][1],sum-vv[i].x+vv[i].y);
    }
 //   printf("%d %d %d\n",x,dp[x][0],dp[x][1]);
}
int main(){
    
    scanf("%d %d",&n,&k);
    k--;
    for(int i = 1;i<n;i++){
        int x,y,c;
        scanf("%d %d %d",&x,&y,&c);
        v[x].pb(mp(y,c));
        v[y].pb(mp(x,c));
    }
    dfs(0,0);
    printf("%d\n",dp[0][1]);
}
/*
5 5
1 1 1 2 2
1 2 100
2 3 100
3 4 1
4 5 1
5 1 100
3
1 3 1 0
1 3 2 0
1 3 1 1

200
102
102
*/