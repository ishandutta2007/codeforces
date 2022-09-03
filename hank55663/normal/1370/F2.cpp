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
vector<int> v[1005];
int cnt=0;
pii query(vector<int> q){
    assert(q.size());
    if(cnt==14)assert(0);
    cnt++;
    printf("? %d ",q.size());
    for(auto it:q){
        printf("%d ",it);
    }
    printf("\n");
    fflush(stdout);
    int x,d;
    scanf("%d %d",&x,&d);
    return mp(x,d);
}
vector<int> dis[1005];
int pa[1005];
int dfs(int x,int f,int d){
    dis[d].pb(x);
    pa[x]=f;
    int res=d;
    for(auto it:v[x]){
        if(it!=f){
            res=max(res,dfs(it,x,d+1));
        }
    }
    return res;
}
int vis[1005];
void dfs2(int x,int f,int t){
    vis[x]=1;
    for(auto it:v[x]){
        if(it!=f&&it!=t){
            dfs2(it,x,t);
        }
    }
}
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<=n;i++){
        v[i].clear();
        vis[i]=0;
        dis[i].clear();
        pa[i]=0;
    }
    cnt=0;
    for(int i =1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    vector<int> qu;
    for(int i = 1;i<=n;i++){
        qu.pb(i);
    }
    pii p =query(qu);
    int root=p.x;
    int Max=min(dfs(root,0,0),p.y),Min=(p.y+1)/2;
    int ans=-1;
    while(Max>Min){
        int mid=(Max+Min+1)/2;
        pii qq=query(dis[mid]);
        if(qq.y==p.y){
            Min=mid;
            ans=qq.x;
        }
        else{
            Max=mid-1;
        }
    }
    if(ans==-1){
        pii qq=query(dis[Min]);
        ans=qq.x;
    }
    qu.clear();
    dfs2(ans,0,root);
    for(auto it:dis[p.y-Min]){
        if(!vis[it])
            qu.pb(it);
    }
    if(qu.empty()){
        printf("! %d %d\n",ans,p.x);
    }
    else{
        pii p2=query(qu);
        while(p2.y>p.y){
            p2.x=pa[p2.x];
            p2.y-=2;
        }
         printf("! %d %d\n",ans,p2.x);
    }
   
    fflush(stdout);
    char c[1005];
    scanf("%s",c);
    assert(c[0]=='C');
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