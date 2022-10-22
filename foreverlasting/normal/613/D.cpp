//2018.9.28 by ljz
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
const int N=3e5+10;
namespace MAIN{
    int n;
    namespace Tree{
        struct E{
            int next,to;
            E() {}
            E(res next,res to):next(next),to(to) {}
        }edge[N];
        int head[N],cnt;
        inline void init(){
            memset(head,-1,sizeof(head));
        }
        inline void addedge(const res &u,const res &v){
            edge[++cnt]=E(head[u],v),head[u]=cnt;
            edge[++cnt]=E(head[v],u),head[v]=cnt;
        }
        int dfn[N],idx,low[N],jump[N][21],dep[N],fa[N];
        void dfs(const res &x,const res &fax,const res &depx){
            dfn[x]=++idx,jump[x][0]=fax,dep[x]=depx,fa[x]=fax;
            for(res i=1;i<=20;i++)jump[x][i]=jump[jump[x][i-1]][i-1];
            for(res i=head[x];~i;i=edge[i].next){
                res tox=edge[i].to;
                if(tox==fax)continue;
                dfs(tox,x,depx+1);
            }
            low[x]=idx;
        }
        inline int get_lca(res x,res y){
            if(dep[x]<dep[y])_swap(x,y);
            res pos=dep[x]-dep[y];
            for(res i=20;~i;i--)if((1<<i)&pos)x=jump[x][i];
            if(x==y)return x;
            for(res i=20;~i;i--)if(jump[x][i]!=jump[y][i])x=jump[x][i],y=jump[y][i];
            return jump[y][0];
        }
    }
    int A[N],bol;
    namespace Vir{
        inline bool cmp(const res &x,const res &y){
            return Tree::dfn[x]<Tree::dfn[y];
        }
        struct E{
            int next,to;
            E() {}
            E(res next,res to):next(next),to(to) {}
        }edge[N];
        int head[N],cnt;
        inline void addedge(const res &u,const res &v){
            edge[++cnt]=E(head[u],v),head[u]=cnt;
        }
        int st[N],top,H[N],k,tot;
        bool vip[N],vis[N];
        inline void init(){
            cnt=bol=0;
            for(res i=1;i<=tot;i++)vis[H[i]]=vip[H[i]]=0,head[H[i]]=-1;
        }
        inline void Read(){
            init();
            k=read();
            for(res i=1;i<=k;i++)H[i]=read(),vis[H[i]]=vip[H[i]]=1;
        }
        inline void build(){
            Read();
            for(res i=1;i<=k;i++)if(vip[Tree::fa[H[i]]]){tot=k;puts("-1");bol=1;return;}
            tot=k,sort(H+1,H+tot+1,cmp);
            for(res i=1,x;i<tot;i++)if(!vis[x=Tree::get_lca(H[i],H[i+1])])vis[H[++k]=x]=1;
            tot=k,sort(H+1,H+tot+1,cmp);
            st[top=1]=H[1];
            for(res i=2;i<=tot;st[++top]=H[i++]){
                while(Tree::dfn[H[i]]<Tree::dfn[st[top]]||Tree::low[H[i]]>Tree::low[st[top]])top--;
                addedge(st[top],H[i]);
            }
        }
    }
    int DP(const res &x){
        res ans=0,sum=0;
        for(res i=Vir::head[x];~i;i=Vir::edge[i].next){
            res tox=Vir::edge[i].to;
            ans+=DP(tox),sum+=A[tox];
        }
        if(Vir::vip[x])A[x]=1,ans+=sum;
        else ans+=(sum>1),A[x]=(sum==1);
        return ans;
    }
    inline void solve(){
        Vir::build();
        if(bol)return;
        printf("%d\n",DP(Vir::H[1]));
    }
    inline void MAIN(){
        Tree::init();
        memset(Vir::head,-1,sizeof(Vir::head));
        n=read();
        for(res i=1;i<n;i++){
            res u=read(),v=read();
            Tree::addedge(u,v);
        }
        Tree::dfs(1,0,1);
        res Q=read();
        while(Q--)solve();
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}