/**
 *    author:  gary
 *    created: 01.10.2021 09:07:37
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
const int MAXN=5e5+1;
int n,w[MAXN];
vector<mp> g[MAXN];
vector<mp> ng[MAXN];
int depth[MAXN];
int is[MAXN];
void addedge(int u,int v,int w){
    ng[u].PB(II(v,w));
    ng[v].PB(II(u,w));
}
void link(int r,vector<mp> c){
    if(c.size()==1){
        addedge(r,c[0].FIR,c[0].SEC);
        return ;
    }
    int mid=c.size()/2;
    vector<mp> lp,rp;
    rep(i,mid) lp.PB(c[i]);
    rb(i,mid,c.size()-1) rp.PB(c[i]);
    ++n;
    is[n]=is[r];
    addedge(r,n,0);
    link(n,lp);
    ++n;
    is[n]=is[r];
    addedge(r,n,0);
    link(n,rp);
}
void dfs(int now,int pre){
    vector<mp> ch;
    for(auto it:g[now]) 
    if(it.FIR!=pre) ch.PB(it),dfs(it.FIR,now);
    if(ch.size())
    link(now,ch);
}
set<mp> ban;
void dfs2(int now,int pre){
    for(auto it:g[now]) if(it.FIR!=pre) depth[it.FIR]=depth[now]+it.SEC,dfs2(it.FIR,now);
}
double calc(int now){
    depth[now]=0;
    dfs2(now,0);
    double rest=0;
    rb(i,1,n){
        rest+=pow(depth[i],1.5)*w[i];
    }
    return rest;
}
LL siz[MAXN];
void dfs3(int now,int pre){
    siz[now]=w[now];
    for(auto it:g[now]) if(it.FIR!=pre&&ban.find(II(it.FIR,now))==ban.end()){
        dfs3(it.FIR,now);
        siz[now]+=siz[it.FIR];
    }
}
int R;
pair<LL,mp> bst;
void dfs4(int now,int pre){
    if(pre)
    check_min(bst,II(max(siz[R]-siz[now],siz[now]),II(now,pre)));
    for(auto it:g[now]) if(it.FIR!=pre&&ban.find(II(it.FIR,now))==ban.end()){
        dfs4(it.FIR,now);
    }
}
int Pre=-1,cnt=0;
int solve(int root){
    if(root!=Pre){
        Pre=root;
        cnt=1;
    }
    else{
        cnt++;
    }
    if(cnt==30) return root;
    dfs3(root,0);
    if(siz[root]==w[root]){
        return root;
    }
    R=root;
    bst=II(1e18,II(INF,INF));
    dfs4(root,0);
    double A,B;
    ban.insert(II(bst.SEC.FIR,bst.SEC.SEC));
    ban.insert(II(bst.SEC.SEC,bst.SEC.FIR));
    A=calc(bst.SEC.FIR);
    B=calc(bst.SEC.SEC);
    if(A<B){
        return solve(bst.SEC.FIR);
    }
    else{
        return solve(bst.SEC.SEC);
    }
}
int main(){
    scanf("%d",&n);
    rb(i,1,n) scanf("%d",&w[i]),is[i]=i;
    rb(i,1,n-1){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[u].PB(II(v,w));
        g[v].PB(II(u,w));
    }
    // dfs(1,0);
    // rb(i,1,n) g[i]=ng[i];
    // rb(i,1,n) cout<<i<<":"<<llround(calc(i))<<endl;
    int f=solve(1);
    printf("%d %.10f\n",is[f],calc(f));
    return 0;
}