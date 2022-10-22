//2018.10.25 by ljz
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
inline void _swap(res &x,res &y){
    x^=y^=x^=y;
}
inline int _abs(const res &x){
    return x>0?x:-x;
}
inline int _max(const res &x,const res &y){
    return x>y?x:y;
}
inline int _min(const res &x,const res &y){
    return x<y?x:y;
}
const int N=1e5+10;
namespace MAIN{
    int n;
    int c[N];
    struct E{
        int next,to;
        E() {}
        E(res next,res to):next(next),to(to) {}
    }edge[N<<1];
    int head[N],cnt;
    inline void addedge(const res &u,const res &v){
        edge[++cnt]=E(head[u],v),head[u]=cnt;
        edge[++cnt]=E(head[v],u),head[v]=cnt;
    }
    int siz[N],son[N],fa[N];
    void Dfs(const res &x,const res &fax){
        siz[x]=1,fa[x]=fax;
        for(res i=head[x];~i;i=edge[i].next){
            res tox=edge[i].to;
            if(tox==fax)continue;
            Dfs(tox,x);
            siz[x]+=siz[tox];
            if(siz[son[x]]<siz[tox])son[x]=tox;
        }
    }
    bool vis[N];
    LL ans[N],sum[N];
    int Max,tot[N],num[N];
    void update(const res &x,const res &va){
        res &s=tot[c[x]];
        num[s]--,sum[s]-=c[x],s+=va,num[s]++,sum[s]+=c[x];
        if(va>0)Max=_max(Max,s);
        else if(!num[Max])Max--;
        for(res i=head[x];~i;i=edge[i].next){
            res tox=edge[i].to;
            if(tox==fa[x]||vis[tox])continue;
            update(tox,va);
        }
    }
    void dfs(const res &x,const res &flag){
        for(res i=head[x];~i;i=edge[i].next){
            res tox=edge[i].to;
            if(tox==fa[x]||tox==son[x])continue;
            dfs(tox,0);
        }
        if(son[x])dfs(son[x],1),vis[son[x]]=1;
        update(x,1),ans[x]=sum[Max],vis[son[x]]=0;
        if(!flag)update(x,-1);
    }
    inline void MAIN(){
        memset(head,-1,sizeof(head));
        n=read();
        for(res i=1;i<=n;i++)c[i]=read();
        for(res i=1;i<n;i++){
            res u=read(),v=read();
            addedge(u,v);
        }
        Dfs(1,0),dfs(1,0);
        for(res i=1;i<=n;i++)printf("%lld ",ans[i]);
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}