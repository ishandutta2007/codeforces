/**
 *    author:  gary
 *    created: 31.01.2022 22:33:10
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
#define ff fflush(stdin),fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int N=1<<18;
const int MAXN=N+233;
int n;
vector<mp> g[MAXN];
bool act[MAXN];
int val[MAXN],heavy[MAXN],siz[MAXN],tp[MAXN],cnt,dfn[MAXN],fa[MAXN];
void init(int now,int pre){
    siz[now]=1;
    fa[now]=pre;
    heavy[now]=0;
    for(auto it:g[now]) if(it.first!=pre) init(it.first,now),siz[now]+=siz[it.first],val[it.first]=it.second;
    for(auto it:g[now]) if(it.first!=pre&&siz[it.first]>siz[heavy[now]]) heavy[now]=it.first;
}
void init2(int now,int pre){
    dfn[now]=++cnt;
    if(heavy[now]) tp[heavy[now]]=tp[now],init2(heavy[now],now);
    for(auto it:g[now]) if(it.first!=pre&&it.first!=heavy[now]) tp[it.first]=it.first,init2(it.first,now);
}
struct segment_tree{
    struct node{
        bool tag;
        LL sum[2];
        int cnt[2];
        node(){tag=false;sum[0]=sum[1]=0;cnt[0]=cnt[1]=0;}
    };
    node tree[N+N];
    void pd(int now){
        if(tree[now].tag){
            if(now<N){
                swap(tree[now<<1].sum[0],tree[now<<1].sum[1]);
                swap(tree[now<<1].cnt[0],tree[now<<1].cnt[1]);
                swap(tree[now<<1|1].sum[0],tree[now<<1|1].sum[1]);
                swap(tree[now<<1|1].cnt[0],tree[now<<1|1].cnt[1]);
                tree[now<<1].tag^=1;
                tree[now<<1|1].tag^=1;
            }
            tree[now].tag=0;
        }
    }
    void pu(int now){
        tree[now].cnt[0]=tree[now<<1].cnt[0]+tree[now<<1|1].cnt[0];
        tree[now].cnt[1]=tree[now<<1].cnt[1]+tree[now<<1|1].cnt[1];
        tree[now].sum[0]=tree[now<<1].sum[0]+tree[now<<1|1].sum[0];
        tree[now].sum[1]=tree[now<<1].sum[1]+tree[now<<1|1].sum[1];
    }
    void flip(int a,int b,int now=1,int l=1,int r=N+1){
        if(r<=a||l>=b) return ;
        if(r<=b&&l>=a){
            tree[now].tag^=1;
            swap(tree[now].sum[0],tree[now].sum[1]);
            swap(tree[now].cnt[0],tree[now].cnt[1]);
            return;
        }
        pd(now);
        int mid=(l+r)>>1;
        flip(a,b,now<<1,l,mid);
        flip(a,b,now<<1|1,mid,r);
        pu(now);
    }
    void build(){
        rb(i,1,N) tree[i+N-1].cnt[0]=1,tree[dfn[i]+N-1].sum[0]=val[i];
        rl(i,N-1,1) pu(i);
    }
}t;
vector<int> e;
bool bf(int now=1,int pre=0){
    bool ok=false;
    for(auto it:g[now]){
        if(it.first!=pre&&act[it.first]){
            if(bf(it.first,now)){
                assert(!ok);
                ok=true;
                e.PB(it.second);
            }
        }
    }
    return !ok;
}
void fli(int x){
    while(x){
        int p=tp[x];
        t.flip(dfn[p],dfn[x]+1);
        x=fa[p];
    }
}
int main(){
    // int ti=clock();
    // freopen("f.in","r",stdin);
    // freopen("f.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    scanf("%d",&n);
    rb(i,1,n-1){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].PB(II(v,i));
        g[v].PB(II(u,i));
    }
    init(1,0);
    tp[1]=1;
    init2(1,0);
    act[1]=1;
    t.build();
    LL preans=0;
    int cnt_act=1;
    fli(1);
    while(true){
        int ty;
        scanf("%d",&ty);
        if(ty==0) return 0;
        if(ty==1){
            int x;
            scanf("%d",&x);
            act[x]=1;
            cnt_act++;
            fli(x);
            preans=0;
            auto tmp=t.tree[1];
            if(tmp.cnt[1]*2==cnt_act) preans=tmp.sum[1];
            printf("%lld\n",preans);
        }
        if(ty==2){
            if(preans==0) printf("0\n");
            else{
                e.clear();
                bf();
                sort(ALL(e));
                printf("%d ",e.size());
                for(auto it:e) printf("%d ",it);
                printf("\n");
            }
        }
        if(ty==3){ff; return 0;}
        ff;
    }
    return 0;
}