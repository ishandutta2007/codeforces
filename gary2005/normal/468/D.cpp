/**
 *    author:  gary
 *    created: 15.10.2021 23:13:01
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
const int MAXN=1e5+1;
int n;
vector<pair<int,int> > g[MAXN];
int siz[MAXN];
LL ans = 0;
void dfs(int now, int pre) {
    siz[now] = 1;
    for (auto it : g[now])
        if (it.FIR != pre)
            dfs(it.FIR, now), siz[now] += siz[it.FIR], ans += 2ll * it.SEC * min(siz[it.FIR], n - siz[it.FIR]);
}
int p[MAXN];
const int N=1<<17;
struct HLD{
    vector<int> g[MAXN];
    int tp[MAXN];
    int heavy[MAXN];
    int siz[MAXN];
    int dfn[MAXN];
    int fa[MAXN];
    int cnt;
    int root;
    HLD(){
        root=1;
        cnt=0;
        memset(fa,0,sizeof(fa));
        memset(tp,0,sizeof(tp));
        memset(heavy,0,sizeof(heavy));
        memset(siz,0,sizeof(siz));
        memset(dfn,0,sizeof(dfn));
    }
    struct SEG
    {
        int tree[N+N],tag[N+N];
        SEG(){memset(tree,0,sizeof(tree));memset(tag,0,sizeof(tag));}
        void pd(int now){
            tree[now]+=tag[now];
            if(now<N) tag[now<<1]+=tag[now],tag[now<<1|1]+=tag[now];
            tag[now]=0;
        }
        void add(int a,int b,int val,int now=1,int l=1,int r=N+1){
            pd(now);
            if(r<=a||l>=b) return ;
            if(r<=b&&l>=a) {
                tag[now]+=val;
                pd(now);
                return;
            }
            int mid=(l+r)>>1;
            add(a,b,val,now<<1,l,mid);
            add(a,b,val,now<<1|1,mid,r);
            tree[now]=min(tree[now<<1],tree[now<<1|1]);
        }
        int query(int a,int b,int now=1,int l=1,int r=N+1){
            pd(now);
            if(r<=a||l>=b) return INF;
            if(r<=b&&l>=a) return tree[now];
            int mid=(l+r)>>1;
            return min(query(a,b,now<<1,l,mid),query(a,b,now<<1|1,mid,r));
        }
    }sgt;
    bool in(int A,int B){
        // A  B 
        return dfn[A]<=dfn[B]+siz[B]-1&&dfn[A]>=dfn[B];
    }
    void addedge(int u,int v){
        g[u].PB(v);
        g[v].PB(u);
    }
    void dfs1(int now,int pre){
        fa[now]=pre;
        siz[now]=1;
        for(auto it:g[now]) if(it!=pre) {
            dfs1(it,now);
            siz[now]+=siz[it];
            if(siz[it]>siz[heavy[now]]) heavy[now]=it;
        }
    }
    void dfs2(int now,int pre){
        dfn[now]=++cnt;
        if(heavy[now]){
            tp[heavy[now]]=tp[now];
            dfs2(heavy[now],now);
        }
        for(auto it:g[now]) if(it!=pre&&it!=heavy[now]){
            tp[it]=it;
            dfs2(it,now);
        }
    }
    void init(){
        dfs1(root,0);
        tp[root]=root;
        dfs2(root,0);
    }
    int Query(){
        return sgt.query(1,1+cnt);
    }
    void Add(int x,int val){
        while (x)
        {
            sgt.add(dfn[tp[x]],dfn[x]+1,val);
            x=fa[tp[x]];
        }
    }
}hld;
mp find(int now,int pre){
    int mx=0;
    mp rest=II(INF,INF);
    for(auto it:g[now]) if(it.FIR!=pre){
        check_max(mx,siz[it.FIR]);
        check_min(rest,find(it.FIR,now));
    }
    check_max(mx,n-siz[now]);
    check_min(rest,II(mx,now));
    return rest;
}
bool vis[MAXN];
int belong[MAXN];
int cnt=0;
priority_queue<int,vector<int>,greater<int> > Qe[MAXN];
void paint(int now,int pre,int col){
    belong[now]=col;
    for(auto it:g[now]) if(it.FIR!=pre) paint(it.FIR,now,col);
}
int main(){
    scanf("%d",&n);
    if(n==1){
        cout<<0<<endl;
        cout<<1<<endl;
        return 0;
    }
    rb(i,1,n-1){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[u].PB({v,w});
        g[v].PB({u,w});
    }
    dfs(1,0);
    cout<<ans<<endl;
    rb(i,1,n) for(auto it:g[i]) if(it.FIR<i) hld.addedge(it.FIR,i);
    mp bst=find(1,0);
    hld.root=bst.SEC;
    hld.init();
    int root=bst.SEC;
    dfs(root,0);
    int now=1;
    for(auto it:g[root]) paint(it.FIR,root,++cnt);
    priority_queue<mp,vector<mp>,greater<mp> > Q;
    rb(i,1,n) Qe[belong[i]].push(i);
    rb(i,0,cnt) Q.push(II(Qe[i].top(),i)),Qe[i].pop();
    rb(i,1,n) hld.sgt.add(hld.dfn[i],hld.dfn[i]+1,n-2*siz[i]);
    hld.sgt.add(hld.dfn[root],hld.dfn[root]+1,INF);
    // cout<<root<<endl;
    // Q.push(II(root,cnt+1));
    while(now<=n){
        if(hld.Query()-now+1==0) break;
        int v;
        if(Q.top().SEC==belong[now]&&now!=root){
            auto Tmp=Q.top();
            Q.pop();
            v=Q.top().FIR;
            if(!Qe[Q.top().SEC].empty()) Q.push(II(Qe[Q.top().SEC].top(),Q.top().SEC)),Qe[Q.top().SEC].pop();
            Q.pop();
            Q.push(Tmp);
        }
        else{
            v=Q.top().FIR;
            if(!Qe[Q.top().SEC].empty()) Q.push(II(Qe[Q.top().SEC].top(),Q.top().SEC)),Qe[Q.top().SEC].pop();
            Q.pop();
        }
        vis[v]=1;
        hld.Add(now,1);
        hld.Add(v,1);
        p[now++]=v;
    }
    int T=-1;
    rb(i,1,n) if(hld.sgt.query(hld.dfn[i],hld.dfn[i]+1)-now+1==0){
        T=i;
        break;
    }
    assert(T!=-1);
    priority_queue<int,vector<int>,greater<int> > pq[2];
    rb(i,1,n) {
        if(hld.in(i,T)) belong[i]=0;
        else belong[i]=1;
        if(!vis[i]) pq[belong[i]].push(i);
    }
    while(now<=n){
        p[now]=pq[belong[now]^1].top();
        pq[belong[now]^1].pop();
        now++;
    }
    rb(i,1,n) printf("%d ",p[i]);
    return 0;
}