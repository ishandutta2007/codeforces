//2019.4.8 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-15
#define RG register
inline int read(){
    res s=0;
    bool w=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=1;ch=getchar();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return w?-s:s;
}
inline void swap(res &x,res &y){
    x^=y^=x^=y;
}
const int N=2e5+10;
namespace MAIN{
    int n,m;
    struct E{
        int u,v,w,id;
        E() {}
        E(res u,res v,res w,res id):u(u),v(v),w(w),id(id) {}
        inline bool operator < (const E &b) const {
            return w<b.w;
        }
    }edge[N];
    struct LCT{
        int son[2],sz,fa,mx;
        bool rev;
    }tr[N<<1];
    inline void pushup(res x){
        res ls=tr[x].son[0],rs=tr[x].son[1];
        tr[x].sz=tr[ls].sz+tr[rs].sz+1;
        tr[x].mx=x;
        if(tr[x].mx<=n||(tr[ls].mx>n&&edge[tr[ls].mx-n].w>edge[tr[x].mx-n].w))tr[x].mx=tr[ls].mx;
        if(tr[x].mx<=n||(tr[rs].mx>n&&edge[tr[rs].mx-n].w>edge[tr[x].mx-n].w))tr[x].mx=tr[rs].mx;
    }
    inline void reversed(res x){
        if(!x)return;
        swap(tr[x].son[0],tr[x].son[1]),tr[x].rev^=1;
    }
    inline void pushdown(res x){
        if(!x||!tr[x].rev)return;
        reversed(tr[x].son[0]),reversed(tr[x].son[1]),tr[x].rev=0;
    }
    inline bool nroot(res x){
        res fa=tr[x].fa;
        return tr[fa].son[0]==x||tr[fa].son[1]==x;
    }
    int st[N<<1];
    inline void rotate(res x){
        res y=tr[x].fa,z=tr[y].fa,k=tr[y].son[1]==x,w=tr[x].son[k^1];
        if(nroot(y))tr[z].son[tr[z].son[1]==y]=x;
        tr[x].son[k^1]=y,tr[y].son[k]=w;
        if(w)tr[w].fa=y;
        tr[y].fa=x,tr[x].fa=z;
        pushup(y);
    }
    inline void splay(res x){
        res i=x,s=0;
        st[++s]=x;
        while(nroot(i))st[++s]=i=tr[i].fa;
        while(s)pushdown(st[s--]);
        while(nroot(x)){
            res y=tr[x].fa,z=tr[y].fa;
            if(nroot(y))rotate((tr[y].son[0]==x)^(tr[z].son[0]==y)?x:y);
            rotate(x);
        }
        pushup(x);
    }
    inline void access(res x){
        for(res y=0;x;x=tr[y=x].fa)splay(x),tr[x].son[1]=y,pushup(x);
    }
    inline void makeroot(res x){
        access(x),splay(x),reversed(x);
    }
    inline void split(res x,res y){
        makeroot(x),access(y),splay(y);
    }
    inline int findroot(res x){
        access(x),splay(x);
        while(tr[x].son[0])pushdown(x),x=tr[x].son[0];
        splay(x);
        return x;
    }
    inline void link(res x,res y){
        makeroot(x);
        if(x==findroot(y))return;
        tr[x].fa=y;
    }
    LL sum,ans[N];
    bool fl[N];
    inline void MAIN(){
        n=read(),m=read();
        for(res i=1;i<=m;i++){
            res u=read(),v=read(),w=read();
            edge[i]=E(u,v,w,i);
        }
        sort(edge+1,edge+m+1);
        for(res i=1,cnt=0;i<=m;i++){
            res u=edge[i].u,v=edge[i].v;
            if(findroot(u)==findroot(v))continue;
            link(u,i+n),link(v,i+n),cnt++,sum+=edge[i].w,fl[i]=1;
            if(cnt==n-1)break;
        }
        for(res i=1;i<=m;i++){
            if(fl[i])ans[edge[i].id]=sum;
            else {
                res u=edge[i].u,v=edge[i].v;
                split(u,v);
                ans[edge[i].id]=sum-edge[tr[v].mx-n].w+edge[i].w;
            }
        }
        for(res i=1;i<=m;i++)printf("%lld\n",ans[i]);
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}