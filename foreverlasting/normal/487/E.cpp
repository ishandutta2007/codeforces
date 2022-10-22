//2018.1.3 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-15
inline int read(){
    res s=0;
    bool w=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=1;ch=getchar();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return w?-s:s;
}
inline void _swap(res &x,res &y) {
    x^=y^=x^=y;
}
inline int _abs(const res &x) {
    return x>0?x:-x;
}
inline int _max(const res &x,const res &y) {
    return x>y?x:y;
}
inline int _min(const res &x,const res &y) {
    return x<y?x:y;
}
const int N=4e5+10;
namespace MAIN{
    int n,m,q;
    int val[N];
    struct TU{
        struct E{
            int next,to;
            E() {}
            E(res next,res to):next(next),to(to) {}
        }edge[N];
        int head[N],cnt;
        inline void addedge(const res &u,const res &v){
            edge[++cnt]=E(head[u],v),head[u]=cnt;
            edge[++cnt]=E(head[v],u),head[v]=cnt;
        }
        TU() {memset(head,-1,sizeof(head));}
    }E1,E2;
    int tot;
    int dfn[N],low[N],idx,st[N],Top;
    void tarjan(const res &x){
        dfn[x]=low[x]=++idx;
        st[++Top]=x;
        for(res i=E1.head[x];~i;i=E1.edge[i].next){
            res tox=E1.edge[i].to;
            if(!dfn[tox]){
                tarjan(tox),low[x]=_min(low[x],low[tox]);
                if(low[tox]>=dfn[x]){
                    tot++,E2.addedge(tot,x);
                    res u=0;
                    do{
                        u=st[Top--],E2.addedge(tot,u);
                    }while(u!=tox);
                }
            }
            else low[x]=_min(low[x],dfn[tox]);
        }
    }
    struct Heap{
        priority_queue<int,vector<int>,greater<int> >Q1,Q2;
        inline void insert(const res &x){
            Q1.push(x);
        }
        inline void del(const res &x){
            Q2.push(x);
        }
        inline int top(){
            while(!Q2.empty()&&Q1.top()==Q2.top()) Q1.pop(),Q2.pop();
            return Q1.top();
        }
    }Q[N];
    int fa[N],dep[N],siz[N],son[N],top[N];
    void dfs1(const res &x,const res &fax,const res &depx){
        fa[x]=fax,dep[x]=depx,siz[x]=1;
        if(x<=n&&fax)Q[fax].insert(val[x]);
        for(res i=E2.head[x];~i;i=E2.edge[i].next){
            res tox=E2.edge[i].to;
            if(tox==fax)continue;
            dfs1(tox,x,depx+1);
            siz[x]+=siz[tox];
            if(siz[son[x]]<siz[tox])son[x]=tox;
        }
    }
    void dfs2(const res &x,const res &topx){
        top[x]=topx,dfn[x]=++idx;
        if(son[x])dfs2(son[x],topx);
        for(res i=E2.head[x];~i;i=E2.edge[i].next){
            res tox=E2.edge[i].to;
            if(tox==fa[x]||tox==son[x])continue;
            dfs2(tox,tox);
        }
    }
    int mn[N<<2];
    inline void pushup(const res &rt){
        mn[rt]=_min(mn[rt<<1],mn[rt<<1|1]);
    }
    void modify(const res &rt,const res &l,const res &r,const res &p,const res &val){
        if(l==r){mn[rt]=val;return;}
        res mid=(l+r)>>1;
        if(p<=mid)modify(rt<<1,l,mid,p,val);
        else modify(rt<<1|1,mid+1,r,p,val);
        pushup(rt);
    }
    int query(const res &rt,const res &l,const res &r,const res &L,const res &R){
        if(L<=l&&r<=R)return mn[rt];
        res mid=(l+r)>>1,ret=inf;
        if(L<=mid)ret=_min(ret,query(rt<<1,l,mid,L,R));
        if(R>mid)ret=_min(ret,query(rt<<1|1,mid+1,r,L,R));
        return ret;
    }
    inline void modify(const res &x,const res &va){
        if(fa[x])Q[fa[x]].del(val[x]),Q[fa[x]].insert(va),modify(1,1,tot,dfn[fa[x]],Q[fa[x]].top());
        val[x]=va,modify(1,1,tot,dfn[x],va);
    }
    inline int query(res u,res v){
        res ret=inf;
        while(top[u]!=top[v]){
            if(dep[top[u]]<dep[top[v]])_swap(u,v);
            ret=_min(ret,query(1,1,tot,dfn[top[u]],dfn[u]));
            u=fa[top[u]];
        }
        if(dep[u]>dep[v])_swap(u,v);
        ret=_min(ret,query(1,1,tot,dfn[u],dfn[v]));
        if(u>n)ret=_min(ret,val[fa[u]]);
        return ret;
    }
    inline void MAIN(){
        memset(mn,inf,sizeof(mn));
        tot=n=read(),m=read(),q=read();
        for(res i=1;i<=n;i++)val[i]=read();
        for(res i=1;i<=m;i++){
            res u=read(),v=read();
            E1.addedge(u,v);
        }
        for(res i=1;i<=n;i++)if(!dfn[i])tarjan(i);
        memset(dfn,0,sizeof(dfn)),idx=0;
        dfs1(1,0,1),dfs2(1,1);
        for(res i=1;i<=n;i++)modify(1,1,tot,dfn[i],val[i]);
        for(res i=n+1;i<=tot;i++)modify(1,1,tot,dfn[i],Q[i].top());
        while(q--){
            char str[2];
            scanf("%s",str);
            res u=read(),v=read();
            if(str[0]=='C')modify(u,v);
            else printf("%d\n",query(u,v));
        }
    }
}
int main() {
    MAIN::MAIN();
    return 0;
}