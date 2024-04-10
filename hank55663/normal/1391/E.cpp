#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
vector<int> v[500005];
vector<int> dep[500005];
int n;
vector<int> stk;
int vis[500005];
bool dfs(int x,int f,int d=1){
    stk.pb(x);
    vis[x]=1;
    dep[d].pb(x);
    if(d==(n+1)/2)return true;
    for(auto it:v[x]){
        if(it!=f&&!vis[it]){
            if(dfs(it,x,d+1)){
                return true;
            }
        }
    }
    stk.pop_back();
    return false;
}
void solve(){
    int m;
    scanf("%d %d",&n,&m);
    stk.clear();
    for(int i = 1;i<=n;i++){
        v[i].clear();
        dep[i].clear();
        vis[i]=0;
    }
    for(int i = 1;i<=m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    if(dfs(1,0)){
        printf("PATH\n%d\n",stk.size());
        for(auto it:stk){
            printf("%d ",it);
        }
        printf("\n");
    }
    else{
        printf("PAIRING\n");
        printf("%d\n",((n+1)/2+1)/2);
        int tot=((n+1)/2+1)/2;
     //   int tot=0;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<dep[i].size()&&tot;j+=2){
                printf("%d %d\n",dep[i][j],dep[i][j-1]);
                tot--;
            }
        }
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/