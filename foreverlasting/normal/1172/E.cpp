//2019.6.11 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f
#define eps 1e-10
#define RG register
#define db double
#define pc(x) __builtin_popcount(x)
typedef pair<int,int> Pair;
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1.0)
//inline void add(res &x,const res &y,const res &kcz){
//    x+=y,x>=kcz?x-=kcz:(x<0?x+=kcz:1);
//}
//inline int Add(const res &x,const res &y,const res &kcz){
//    return x+y>=kcz?x+y-kcz:(x+y<0?x+y+kcz:x+y);
//}
//inline int mul(const res &x,const res &y,const res &kcz){
//    return int(1LL*x*y%kcz);
//}
//inline int qpow(res x,res y,const res &kcz){
//    res ret=1;
//    while(y){
//        if(y&1)ret=mul(ret,x,kcz);
//        y>>=1,x=mul(x,x,kcz);
//    }
//    return ret;
//}
#define gc getchar
//inline char gc() {
//    static char buf[100000],*p1,*p2;
//    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
//}
inline int read() {
    res s=0,ch=gc();
    while(ch<'0'||ch>'9')ch=gc();
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s;
}
//inline int read() {
//    res s=0,ch=gc(),w=1;
//    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=gc();}
//    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
//    return s*w;
//}
//inline LL Read() {
//    RG LL s=0;
//    res ch=gc();
//    while(ch<'0'||ch>'9')ch=gc();
//    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
//    return s;
//}
//inline LL Read() {
//    RG LL s=0;
//    res ch=gc(),w=1;
//    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=gc();}
//    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
//    return s*w;
//}
//inline void swap(res &x,res &y) {
//    x^=y^=x^=y;
//}
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=4e5+10;
namespace MAIN {
    struct LCT{
        int son[2],sz,fa,psz;
        LL psz2;
        bool rev;
        inline LL sz2(){
            return 1LL*sz*sz;
        }
    }tr[N];
    inline void pushup(const res &x){
        res ls=tr[x].son[0],rs=tr[x].son[1];
        tr[x].sz=tr[ls].sz+tr[rs].sz+tr[x].psz+1;
    }
    inline bool nroot(const res &x){
        res fa=tr[x].fa;
        return tr[fa].son[0]==x||tr[fa].son[1]==x;
    }
    inline void rotate(const res &x){
        res y=tr[x].fa,z=tr[y].fa,k=tr[y].son[1]==x,w=tr[x].son[k^1];
        if(nroot(y))tr[z].son[tr[z].son[1]==y]=x;
        tr[x].son[k^1]=y,tr[y].son[k]=w;
        if(w)tr[w].fa=y;
        tr[y].fa=x,tr[x].fa=z;
        pushup(y);
    }
    inline void splay(const res &x){
        while(nroot(x)){
            res y=tr[x].fa,z=tr[y].fa;
            if(nroot(y))rotate((tr[y].son[0]==x)^(tr[z].son[0]==y)?x:y);
            rotate(x);
        }
        pushup(x);
    }
    inline void access(res x){
        for(res y=0;x;x=tr[y=x].fa){
            splay(x);
            res &rs=tr[x].son[1];
            tr[x].psz+=tr[rs].sz-tr[y].sz,tr[x].psz2+=tr[rs].sz2()-tr[y].sz2(),rs=y,pushup(x);
        }
    }
    inline int findroot(res x){
        access(x),splay(x);
        while(tr[x].son[0])x=tr[x].son[0];
        splay(x);
        return x;
    }
    int fa[N];
    LL ans;
    inline void link(const res &x){
        res y=fa[x],z=findroot(y);
        splay(x),ans-=tr[x].psz2+tr[tr[x].son[1]].sz2(),access(x),splay(z),ans-=tr[tr[z].son[1]].sz2(),tr[x].fa=y,splay(y),tr[y].psz+=tr[x].sz,tr[y].psz2+=tr[x].sz2(),pushup(y),access(x),splay(z),ans+=tr[tr[z].son[1]].sz2();
    }
    inline void cut(const res &x){
        res y=fa[x],z=findroot(y);
        access(x),ans+=tr[x].psz2,access(x),splay(z),ans-=tr[tr[z].son[1]].sz2(),splay(x),tr[x].son[0]=tr[tr[x].son[0]].fa=0,pushup(x),splay(z),ans+=tr[tr[z].son[1]].sz2();
    }
    int n,m;
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
    void dfs(const res &x,const res &fax){
        fa[x]=fax,link(x);
        for(res i=head[x];~i;i=edge[i].next){
            res tox=edge[i].to;
            if(tox==fax)continue;
            dfs(tox,x);
        }
    }
    int col[N];
    bool fl[N];
    vector<Pair> mod[N];
#define pb push_back
    LL Ans[N];
    inline void MAIN(){
        n=read(),m=read();
        for(res i=1;i<=n;i++)head[i]=-1,col[i]=read(),mod[col[i]].pb(mp(i,0)),tr[i].sz=1;
        for(res i=1;i<n;i++)addedge(read(),read());
        dfs(1,n+1);
        for(res i=1;i<=m;i++){
            res u=read(),x=read();
            mod[col[u]].pb(mp(u,i)),col[u]=x,mod[x].pb(mp(u,i));
        }
        for(res i=1;i<=n;i++){
            if(!int(mod[i].size())){Ans[0]+=1LL*n*n;continue;}
            RG LL las=0;
            if(mod[i][0].se)Ans[0]+=1LL*n*n,las=1LL*n*n;
            res sz=int(mod[i].size())-1;
            for(res j=0;j<=sz;j++){
                res u=mod[i][j].fi;
                if(fl[u]^=1)cut(u);
                else link(u);
                if(j==sz||mod[i][j].se!=mod[i][j+1].se)Ans[mod[i][j].se]+=ans-las,las=ans;
            }
            for(res j=sz;~j;j--){
                res u=mod[i][j].fi;
                if(fl[u]^=1)cut(u);
                else link(u);
            }
        }
        ans=1LL*n*n*n;
        for(res i=0;i<=m;i++)ans-=Ans[i],printf("%lld\n",ans);
    }
}
int main() {
//    srand((unsigned)time(NULL));
    // freopen("zao.in","r",stdin);
    // freopen("std.out","w",stdout);
    MAIN::MAIN();
    return 0;
}