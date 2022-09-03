#include<bits/stdc++.h>
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
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define last Last
#define MXN 200005
pii p[100005];
vector<int> v[100005];
LL dp[100005][2];
void dfs(int x,int f){
    dp[x][0]=dp[x][1]=0;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
            dp[x][0]+=max(dp[it][0]+abs(p[it].x-p[x].x),dp[it][1]+abs(p[it].y-p[x].x));
            dp[x][1]+=max(dp[it][0]+abs(p[it].x-p[x].y),dp[it][1]+abs(p[it].y-p[x].y));
        }
    }
}
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)v[i].clear();
    for(int i = 1;i<=n;i++){
        int l,r;
        scanf("%d %d",&l,&r);
        p[i]=mp(l,r);
    }   
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0);
    printf("%lld\n",max(dp[1][0],dp[1][1]));
}
int main(){
    int t=1;//000;
    scanf("%d",&t);
    while(t--)
        solve();
    /*int t=1;00000;
    scanf("%d",&t);
    while(t--){
        solve();
    }*/
}
/*
1 3 2 1
1 3 2 1
2 4 2 1
2 4 2 1
4 5 2 1
4 5 2 1
*/