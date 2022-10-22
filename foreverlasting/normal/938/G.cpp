//2019.3.18 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-10
#define RG register
inline int read() {
    res s=0;
    bool w=0;
    char ch=getchar();
    while(ch<'0'||ch>'9') {
        if(ch=='-')w=1;
        ch=getchar();
    }
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
namespace MAIN {
    int n,m;
    struct LB{
        int p[31];
        inline void insert(res x){
            for(res i=30;~i;i--){
                if(x&(1<<i)){
                    if(!p[i]){p[i]=x;return;}
                    x^=p[i];
                }
            }
        }
        inline int calc(res x){
            for(res i=30;~i;i--)x=_min(x,x^p[i]);
            return x;
        }
    }A;
    typedef pair<int,int> Pair;
#define mp make_pair
#define fi first
#define se second
    map<Pair,int> M;
    struct MOD{
        int l,r,u,v,w;
        MOD() {}
        MOD(res l,res r,res u,res v,res w):l(l),r(r),u(u),v(v),w(w) {}
    }mod[N];
    int modx;
    struct Que{
        int u,v;
        Que() {}
        Que(res u,res v):u(u),v(v) {}
    }que[N];
    int quex;
    vector<int> tr[N<<2];
#define pb push_back
    void insertmod(const res &rt,const res &l,const res &r,const res &L,const res &R,const res &id){
        if(L<=l&&r<=R){tr[rt].pb(id);return;}
        res mid=(l+r)>>1;
        if(L<=mid)insertmod(rt<<1,l,mid,L,R,id);
        if(R>mid)insertmod(rt<<1|1,mid+1,r,L,R,id);
    }
    int fa[N],dis[N],sz[N];
    inline int find(res x){
        while(x!=fa[x])x=fa[x];
        return x;
    }
    inline int fdis(res x){
        res ret=0;
        while(x!=fa[x])ret^=dis[x],x=fa[x];
        return ret;
    }
    int top;
    struct U{
        int u,v,sz;
        U() {}
        U(res u,res v,res sz):u(u),v(v),sz(sz) {}
    }st[N];
    inline void merge(res u,res v,res du,res dv,const res &w){
        if(sz[u]>sz[v])_swap(u,v),_swap(du,dv);
        st[++top]=U(u,v,sz[v]);
        fa[u]=v,sz[v]+=sz[u],dis[u]=du^dv^w;
    }
    inline void remerge(const res &Top){
        while(top>Top){
            res u=st[top].u,v=st[top].v,SZ=st[top].sz;
            dis[u]=0,fa[u]=u,sz[v]=SZ,top--;
        }
    }
    void query(const res &rt,const res &l,const res &r,RG LB S){
        res Top=top;
        for(auto i:tr[rt]){
            res fu=find(mod[i].u),fv=find(mod[i].v),du=fdis(mod[i].u),dv=fdis(mod[i].v);
            if(fu==fv){S.insert(du^dv^mod[i].w);continue;}
            merge(fu,fv,du,dv,mod[i].w);
        }
        if(l==r){printf("%d\n",S.calc(fdis(que[l].u)^fdis(que[l].v))),remerge(Top);return;}
        res mid=(l+r)>>1;
        query(rt<<1,l,mid,S),query(rt<<1|1,mid+1,r,S);
        remerge(Top);
    }
    inline void MAIN(){
        n=read(),m=read();
        for(res i=1;i<=n;i++)fa[i]=i,sz[i]=1;
        for(res i=1;i<=m;i++){
            res u=read(),v=read(),w=read();
            if(u>v)_swap(u,v);
            mod[++modx]=MOD(quex+1,-1,u,v,w),M[mp(u,v)]=modx;
        }
        res Q=read();
        while(Q--){
            res opt=read(),u=read(),v=read();
            if(u>v)_swap(u,v);
            if(opt==1){
                res w=read();
                mod[++modx]=MOD(quex+1,-1,u,v,w),M[mp(u,v)]=modx;
            }
            else if(opt==2)mod[M[mp(u,v)]].r=quex,M.erase(mp(u,v));
            else que[++quex]=Que(u,v);
        }
        for(res i=1;i<=modx;i++){
            if(mod[i].r==-1)mod[i].r=quex;
            if(mod[i].l<=mod[i].r)insertmod(1,1,quex,mod[i].l,mod[i].r,i);
        }
        query(1,1,quex,A);
    }
}
int main() {
    MAIN::MAIN();
    return 0;
}