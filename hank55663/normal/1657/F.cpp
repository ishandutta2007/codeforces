#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<__float128,__float128>
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
vector<int> v[400005];
int pr[20][400005];
int d[400005];
void dfs(int x,int f){
    pr[0][x]=f;
    d[x]=d[f]+1;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
        }
    }
}
void build(int n){
    for(int i = 1;i<20;i++){
        for(int j = 1;j<=n;j++){
            pr[i][j]=pr[i-1][pr[i-1][j]];
        }
    }
}
int lca(int a,int b){
    if(d[a]>d[b])swap(a,b);
    int x=d[b]-d[a];
    for(int i = 0;i<20;i++){
        if(x&(1<<i)){
            b=pr[i][b];
        }
    }
    if(a==b)return a;
    for(int i = 19;i>=0;i--){
        if(pr[i][a]!=pr[i][b]){
            a=pr[i][a];
            b=pr[i][b];
        }
    }
    return pr[0][a];
}
pair<vector<int>,string> p[400005];
vector<int> getv(int x,int y){
    int l=lca(x,y);
    vector<int> tmp1,tmp2;
    while(x!=l)tmp1.pb(x),x=pr[0][x];
    while(y!=l)tmp2.pb(y),y=pr[0][y];
    reverse(tmp2.begin(),tmp2.end());
    tmp1.pb(l);
    for(auto it:tmp2)tmp1.pb(it);
    return tmp1;
}
char ans[400005];
vector<pii> qq[400005];
int vis[400005];
vector<int> stk,stk2;
bool go(int x,int r){
    if(vis[x])return true;
    vis[x]=1;
    stk.pb(x);
    if(r)reverse(p[x].y.begin(),p[x].y.end());
    queue<int> q;
    for(int i = 0;i<p[x].x.size();i++){
        int a=p[x].x[i];
        char c=p[x].y[i];
        if(ans[a]==0){
            ans[a]=c;
            q.push(a);
            stk2.pb(a);
        }
        else{
            if(ans[a]!=c){
                if(r)reverse(p[x].y.begin(),p[x].y.end());
                return false;
            }
        }
    }
    if(r)reverse(p[x].y.begin(),p[x].y.end());
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto it:qq[x]){
            if(p[it.x].y[it.y]==ans[x]){
                if(!go(it.x,0))return false;
            }
            else{
                if(!go(it.x,1))return false;
            }
        }
    }
    return true;
}
void solve(){
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0);
    build(n);
    MEM(ans);
    for(int i = 0;i<q;i++){
        int x,y;
        char c[400005];
        scanf("%d %d %s",&x,&y,c);
        p[i]=mp(getv(x,y),string(c));
        for(int j=0;j<p[i].x.size();j++)qq[p[i].x[j]].pb(mp(i,j));
        int n=strlen(c);
        for(int j = 0;j<n;j++){
            if(c[j]==c[n-j-1]){
                ans[p[i].x[j]]=c[j];
                ans[p[i].x[n-j-1]]=c[j];
            }
        }
    }
    for(int i = 0;i<q;i++){
        if(!vis[i]){
             stk.clear();
            stk2.clear();
            if(go(i,0)){
                continue;
            }
            for(auto it:stk)vis[it]=0;
            for(auto it:stk2)ans[it]=0;
            stk.clear();
            stk2.clear();
            if(go(i,1)){
                continue;
            }
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
    for(int i = 1;i<=n;i++){
        if(ans[i]==0)ans[i]='a';
        printf("%c",ans[i]);
    }
    printf("\n");
}


int main(){
    int t=1;
  //scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*

*/