#include<bits/stdc++.h>
#pragma optimize(Ofast)
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<LL,LL>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
const int mod=998244353;
vector<int> v[200005];
vector<int> val[2];
void dfs(int x,int f,int d){
    val[d].pb(x);
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x,d^1);
        }
    }
}
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)v[i].clear();
    val[0].clear();
    val[1].clear();
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0,0);
    if(val[0].size()>val[1].size())swap(val[0],val[1]);
    int vis[200005];
    fill(vis,vis+n+1,0);
    int now=0;
    int ans[200005];
    for(int i = 0;(1<<i)<n;i++){
        if(val[0].size()&(1<<i)){
            for(int j = (1<<i);j<((1<<(i+1)));j++){
                ans[val[0][now]]=j;
                now++;
                vis[j]=1;
            }
        }
    }
    now=0;
    for(int i = 1;i<=n;i++){
        if(!vis[i]){
            ans[val[1][now]]=i;
            now++;
        }
    }
    for(int i = 1;i<=n;i++)printf("%d ",ans[i]);
    printf("\n");
}
int main(){

    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
       // cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/