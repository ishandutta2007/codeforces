/**
 *    author:  gary
 *    created: 07.03.2022 17:58:56
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
const int MAXN=1e5+10;
long long lastans=0;
int n,q;
vector<mp> g[MAXN];
struct Tree{
    int root;
    long long dep[MAXN];
    int to[MAXN];
    int from[MAXN];
    int jump[MAXN][17];
    int rnk[MAXN];
    long long prefix[MAXN];
    vector<int> leaf;
    void dfs(int now,int pre){
        jump[now][0]=pre;
        rb(j,1,16) jump[now][j]=jump[jump[now][j-1]][j-1];
        vector<mp> ch;
        for(auto it:g[now]) if(it.first!=pre) ch.PB(it);
        if(ch.empty()){
            to[now]=now;
            from[now]=now;
            leaf.PB(now);
        }
        else{
            pair<long long,int> mx=II(-1e18,0);
            for(auto it:ch){
                dep[it.first]=dep[now]+it.second;
                dfs(it.first,now);
                check_max(mx,II(dep[to[it.first]]-dep[now],it.first));
            }
            to[now]=to[mx.second];
            from[mx.second]=from[now]=now;
        }
    }
    void dfs2(int now,int pre){
        if(from[now]!=now) from[now]=from[from[now]];
        for(auto it:g[now]) if(it.first!=pre) dfs2(it.first,now);
    }
    int cnt;
    void init(){
        dep[0]=0;
        memset(jump,0,sizeof(jump));
        dep[root]=0;
        dfs(root,0);
        dfs2(root,0);
        vector<pair<long long,int> > zz;
        for(auto it:leaf) zz.PB(II(dep[it]-dep[jump[from[it]][0]],it));
        leaf.clear();
        sort(ALL(zz));
        reverse(ALL(zz));
        for(auto it:zz) leaf.PB(it.second);
        cnt=0;
        prefix[0]=0;
        for(auto it:leaf) rnk[it]=++cnt,prefix[cnt]=prefix[cnt-1]+dep[it]-dep[jump[from[it]][0]];
        // for(auto it:leaf) cout<<dep[it]<<" "<<jump[from[it]][0]<<endl;
    }
    int find_low(int x,int k){
        rl(j,16,0){
            if(jump[x][j]==0) continue;
            if(rnk[to[jump[x][j]]]>k){
                x=jump[x][j];
            }
        }
        return jump[x][0];
    }
    long long query(int x,int y){
        y=2*y-1;
        check_min(y,cnt);
        x=to[x];
        // cerr<<root<<" "<<x<<" "<<prefix[cnt]<<" "<<y<<" "<<cnt<<endl;
        if(rnk[x]<=y){
            return prefix[y];
        }
        if(y==1){
            return dep[x];
        }
        long long ans=prefix[y-1];
        long long addi=0;
        int f=find_low(x,y-1);
        addi=dep[x]-dep[f];
        long long addi2=prefix[y]-prefix[y-1];
        f=find_low(x,y);
        addi2+=dep[x]-dep[to[f]];
        return ans+max(addi,addi2);
    }
}t[2];
pair<long long,int> dfs(int now,int pre=0,long long d=0){
    auto tmp=II(d,now);
    for(auto it:g[now]) if(it.first!=pre){
        check_max(tmp,dfs(it.first,now,d+it.second));
    }
    return tmp;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    rb(i,1,n-1){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].PB(II(v,w));
        g[v].PB(II(u,w));
    }
    auto A=dfs(1);
    t[0].root=A.second;
    A=dfs(A.second);
    t[1].root=A.second;
    t[0].init();
    t[1].init();
    rb(i,1,q){
        int x,y;
        cin>>x>>y;
        x=(lastans+x-1+n)%n+1;
        y=(lastans+y-1+n)%n+1;
        lastans=max(t[0].query(x,y),t[1].query(x,y));
        cout<<lastans<<endl;
    }
    return 0;
}