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
vector<int> v[400005];
int ans[400005];
int val[400005];
void dfs(int x){
    ans[x]=-1;
    for(auto it:v[x]){
        if(ans[it]==0)dfs(it);
    }
}
int degree[400005];
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++)v[i].clear(),degree[i]=0,val[i]=0,ans[i]=0;
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
    }
    dfs(1);
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(ans[i]==-1){
            for(auto it:v[i])degree[it]++;
        }
    }
    for(int i =1;i<=n;i++){
        if(ans[i]==-1&&degree[i]==0)q.push(i);
    }
    val[1]=1;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        ans[x]=val[x];
        //if(ans[x]==-1)ans[x]=1;
        for(auto it:v[x]){
            val[it]+=val[x];
            val[it]=min(val[it],2);
            if(--degree[it]==0)q.push(it);
        } 
    }
    for(int i = 1;i<=n;i++)printf("%d ",ans[i]);
    printf("\n");
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}