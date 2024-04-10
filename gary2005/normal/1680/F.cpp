/**
 *    author:  gary
 *    created: 13.05.2022 22:32:27
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=1e6+10;
int n,m;
vector<int> g[MAXN];
SRAND;
vector<int> tree[MAXN];
int depth[MAXN];
vector<mp> x;
int pre[MAXN];
int cnt[MAXN];
int cnt2[MAXN];
void dfs(int now,int fa,int dep){
    depth[now]=dep;
    pre[now]=fa;
    for(auto it:g[now]) if(it!=fa){
        if(depth[it]){
            if(depth[it]<depth[now]){
                x.PB(II(it,now));
            }
        }
        else{
            tree[now].PB(it);
            dfs(it,now,dep+1);
        }
    }
}
void dfs2(int now){
    for(auto it:tree[now]) dfs2(it),cnt[now]+=cnt[it],cnt2[now]^=cnt2[it];
}
int U,V;
bool vis[MAXN];
int col[MAXN];
bool checkx(int now,int c){
    if(vis[now]) return col[now]==c;
    vis[now]=1;
    col[now]=c;
    for(auto it:g[now]) if(II(it,now)!=II(U,V)&&II(it,now)!=II(V,U)&&!checkx(it,c^1)) return 0;
    return 1;
}
bool check(int u,int v){
    U=u,V=v;
    rb(i,1,n) vis[i]=0;
    if(!checkx(1,0)) return false;
    if(u&&!col[u]&&!col[v]){
        rb(i,1,n) col[i]^=1;
    }
    puts("YES");
    rb(i,1,n) putchar('0'+col[i]);
    putchar('\n');
    return 1;
}
void solve(){
    scanf("%d%d",&n,&m);
    x.clear();
    rb(i,1,n) g[i].clear(),tree[i].clear(),depth[i]=0,cnt[i]=0,cnt2[i]=0;
    rb(i,1,m){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].PB(v);
        g[v].PB(u);
    }
    dfs(1,0,1);
    int tot=0;
    vector<mp> y;
    for(auto it:x){
        if(depth[it.first]%2==depth[it.second]%2) y.PB(it);
        else cnt[it.first]--,cnt[it.second]++;
    }
    if(y.size()==0){
        assert(check(0,0));
        return ;
    }
    if(y.size()==1){
        // cout<<y[0].first<<" "<<y[0].second<<endl;
        assert(check(y[0].first,y[0].second));
        return ;
    }
    for(auto it:y){
        int tmp=random(INF);
        tot^=tmp;
        cnt2[it.first]^=tmp,cnt2[it.second]^=tmp;
    }
    dfs2(1);
    rb(i,2,n){
        if(cnt2[i]==tot&&!cnt[i]){
            if(check(i,pre[i])){
                return;
            }
        }
    }
    puts("NO");
}
int main(){
    int t;
    scanf("%d",&t);
    while (t--)
    {
        solve();
    }
    return 0;
}