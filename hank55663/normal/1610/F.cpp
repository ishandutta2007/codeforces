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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
vector<pii> v[300005];
int degree[300005];
vector<pii> v2[300005];
pii edge[300005];
int vis[300005];
int d[300005];
int val[300005];
int match[300005];
vector<int> matcha[300005];
vector<int> ans;
int dfs(int x){
    while(v[x].size()&&vis[v[x].back().y])v[x].pop_back();
    if(v[x].size()){
        pii p=v[x].back();
        ans.pb(p.y);
        if(edge[p.y].x==x)d[p.y]=1;
        else d[p.y]=2;
        vis[p.y]=1;
        v[x].pop_back();
        return dfs(p.x);
    }
    else{
      //  val[x]=-1;
        return x;
    }
}
int dfs2(int x,int inv=0){
    while(v2[x].size()&&vis[v2[x].back().y])v2[x].pop_back();
    if(v2[x].size()){
        pii p=v2[x].back();
       // ans.pb(p.y);
        if(edge[p.y].x==x)d[p.y]=1;
        else d[p.y]=2;
        if(inv)d[p.y]=3-d[p.y];
        vis[p.y]=1;
        v2[x].pop_back();
        return dfs2(p.x,inv);
    }
    else{
       // val[x]=-1;
        return x;
    }
}
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i<m;i++){
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        if(w==1){
            v[x].pb(mp(y,i));
            v[y].pb(mp(x,i));
        }
        else{
            v2[x].pb(mp(y,i));
            v2[y].pb(mp(x,i));
        }
        edge[i]=mp(x,y);
    }
    for(int i = 1;i<=n;i++){
        degree[i]=v[i].size();
    }
    int tot=0;
    for(int i =1;i<=n;i++){
        if(degree[i]%2==1&&val[i]==0){
            tot+=2;
            ans.clear();
            int x=dfs(i);
            val[x]=-1;
            val[i]=1;
            match[x]=i;
            match[i]=x;
            matcha[x]=matcha[i]=ans;
          //  for(auto it:ans)printf("%d %d\n",it,d[it]);
          //  printf("%d %d\n",i,x);
        }
    }
    for(int i = 1;i<=n;i++){
        degree[i]=v2[i].size();
    }
    for(int i = 1;i<=n;i++){
        if(degree[i]%2==1){
            degree[i]=0;
            int x=dfs2(i);
            degree[x]=0;
            //if(val[i]==0&&val[x]==0);
            while(x!=i&&val[x]){
                int x2=match[x];
            //    printf("%d %d\n",x,val[x]);
                if(val[x]==-1){
                    for(auto it:matcha[x]){
                        d[it]=3-d[it];
                    }
                    val[x]=1;
                    val[x2]=-1;
                }
                if(degree[x2]%2==1){
                    degree[x2]=0;
                    x=dfs2(x2);
                    degree[x]=0;
                }
                else{
                    break;
                }
            }
            int y=i;
            while(val[y]){
                int y2=match[y];
                if(val[y]==1){
                    for(auto it:matcha[y]){
                        d[it]=3-d[it];
                    }
                    val[y]=-1;
                    val[y2]=1;
                }
                if(degree[y2]%2==1){
                    degree[y2]=0;
                    y=dfs2(y2,1);
                    degree[y]=0;
                }
                else{
                    break;
                }
            }
        }
    }
    for(int i = 1;i<=n;i++){
        while(v[i].size()){
            dfs(i);
        }
        while(v2[i].size()){
            dfs2(i);
        }
    }
    printf("%d\n",tot);
    for(int i = 0;i<m;i++)printf("%d",d[i]);
    printf("\n");
}

int main(){

    int t=1;0000;
    //scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/