#include<bits/stdc++.h>
#pragma optimize(Ofast)
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
#define MXN 500005
vector<pii> v[200005];
int vis[200005];
int color[200005];
int cnt[2];
bool dfs(int x,int f){
    cnt[color[x]=f]++;
    vis[x]=1;
    for(auto it:v[x]){
        if(vis[it.x]){
            int c=f^it.y;
            if(color[it.x]!=c){
                return false;
            }
        }
        else{
            int c=f^it.y;
            if(!dfs(it.x,c)){
                return false;
            }
        }
    }
    return true;
}
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++){
        v[i].clear();
        vis[i]=0;
    }
    for(int i = 0;i<m;i++){
        int x,y;
        char c[1005];
        scanf("%d %d %s",&x,&y,c);
        if(c[0]=='i')v[x].pb(mp(y,1)),v[y].pb(mp(x,1));
        else v[x].pb(mp(y,0)),v[y].pb(mp(x,0));
    }
    int ans=0;
    for(int i = 1;i<=n;i++){
        if(!vis[i]){
                cnt[0]=cnt[1]=0;
            if(!dfs(i,0)){
                printf("-1\n");
                return;
            }
            ans+=max(cnt[0],cnt[1]);
        
        }
    }
    printf("%d\n",ans);
}
int main(){

    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        //cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
60.0 0.0 50.0 170.0 
3
40.0 0.0 0.0 0.0
5.0 20.0 5.0 170.0
95.0 0.0 95.0 80.0


0.0 1.0 4.0 1.0 
1
0.0 0.0 4.0 0.0
*/