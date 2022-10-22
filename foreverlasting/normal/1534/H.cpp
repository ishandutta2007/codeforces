//2021.9.6 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
//#pragma GCC optimize(2)
//#pragma GCC optimize(3)
//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
//#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
#define res register int
#define LL long long
#define sup 0x7fffffff
#define inf 0x80000000
#define INF 0x3f3f3f3f3f3f3f
//#define unl __int128
#define eps 1e-5
#define RG register
#define db double
#define pc(x) __builtin_popcount(x)
//#define ctz(x) __builtin_ctz(x)
//#define pc(x) __builtin_popcountll(x)
typedef pair<int,int> Pair;
//#define poly vector<int>
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1.0)
#define pb push_back
#define ull unsigned LL
#define lowbit(x) (x&-x)
#define gc getchar
//template <class T>using Tree=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//inline char gc() {
//    static char buf[100000],*p1,*p2;
//    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
//}
//inline int read() {
//    res s=0,ch=gc();
//    while(ch<'0'||ch>'9')ch=gc();
//    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
//    return s;
//}
//char sr[1<<21],z[20];
//int C=-1,Z=0;
//inline void Ot(){fwrite(sr,1,C+1,stdout),C=-1;}
//inline void print(RG LL x){
//    if(C>1<<20)Ot();if(x<0)sr[++C]='-',x=-x;
//    while(z[++Z]=x%10+48,x/=10);
//    while(sr[++C]=z[Z],--Z);
//}
inline int read() {
    res s=0,ch=gc(),laz=1;
    while(ch<'0'||ch>'9'){if(ch=='-')laz=-1;ch=gc();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s*laz;
}
inline LL Read() {
    RG LL s=0;
    res ch=gc();
    while(ch<'0'||ch>'9')ch=gc();
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s;
}
//inline LL Read() {
//    RG LL s=0;
//    res ch=gc(),laz=1;
//    while(ch<'0'||ch>'9'){if(ch=='-')laz=-1;ch=gc();}
//    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
//    return s*laz;
//}
//inline void write(RG unl x){
//    if(x>10)write(x/10);
//    putchar(int(x%10)+'0');
//}
inline void swap(res &x,res &y) {
    x^=y^=x^=y;
}
const int kcz=998244353;
const int G=3,GI=332748118;
inline void add(res &x,const res &y){
    x+=y,x>=kcz?x-=kcz:1;
}
inline int Add(const res &x,const res &y){
    return x+y>=kcz?x+y-kcz:x+y;
}
inline int mul(const res &x,const res &y){
    return int(1ll*x*y%kcz);
}
//#define add(x,y) x+=y,x>=limcz?x-=limcz:1
//#define Add(x,y) (x+y>=limcz?x+y-limcz:x+y)
//#define mul(x,y) int(1ll*x*y%limcz)
//#define Mul(x,y,d) int(1LL*x*y/d%limcz)
inline int qpow(res x,res y=kcz-2){
    res ret=1;
    while(y){
        if(y&1)ret=mul(ret,x);
        x=mul(x,x),y>>=1;
    }
    return ret;
}
inline int Qpow(res x,res y,const res &ljc){
    res ret=1;
    while(y){
        if(y&1)ret=int(1ll*ret*x%ljc);
        x=int(1ll*x*x%ljc),y>>=1;
    }
    return ret;
}
mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());
//cloclim_t start=cloclim();
//inline void clim(){
//    if(1.0*(cloclim()-start)/CLOCKS_PER_SEC>0.1)exit(0);
//}
//2021.9.6 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
const int N=1e5+10;
namespace MAIN{
    int n;
    vector<int> G[N];
    int f[N];
    struct Treap{
        int mx,son[2],val,laz,sz,va,pri;
    }tr[N*3];
    int rt[N],tot,st[N*3],top;
    inline int newnode(const res &va,const res &val){
        res cur=0;
        if(top)cur=st[top--];
        else cur=++tot;
        tr[cur].va=va,tr[cur].mx=tr[cur].val=val,tr[cur].sz=1,tr[cur].pri=rng(),tr[cur].son[0]=tr[cur].son[1]=tr[cur].laz=0;
        return cur;
    }
    inline void change(const res &x,const res &v){
        if(!x)return;
        tr[x].mx+=v,tr[x].val+=v,tr[x].laz+=v;
    }
    inline void pushdown(const res &x){
        if(!tr[x].laz||!x)return;
        change(tr[x].son[0],tr[x].laz),change(tr[x].son[1],tr[x].laz),tr[x].laz=0;
    }
    inline void pushup(const res &x){
        tr[x].mx=max({tr[tr[x].son[0]].mx,tr[tr[x].son[1]].mx,tr[x].val});
        tr[x].sz=tr[tr[x].son[0]].sz+tr[tr[x].son[1]].sz+1;
    }
    int merge(res x,res y){
        if(!x||!y)return x|y;
        pushdown(x),pushdown(y);
        if(tr[x].pri<tr[y].pri){
            tr[x].son[1]=merge(tr[x].son[1],y);
            pushup(x);
            return x;
        }
        else {
            tr[y].son[0]=merge(x,tr[y].son[0]);
            pushup(y);
            return y;
        }
    }
    void split(res now,res k,res &x,res &y){
        if(!now){x=y=0;return;}
        pushdown(now);
        if(tr[now].va<=k)x=now,split(tr[now].son[1],k,tr[now].son[1],y);
        else y=now,split(tr[now].son[0],k,x,tr[now].son[0]);
        pushup(now);
    }
    void split_sz(res now,res k,res &x,res &y){
//        printf("%d %d %d %d\n",now,k,x,y);
        if(!now){x=y=0;return;}
        pushdown(now);
        if(tr[tr[now].son[0]].sz<k)x=now,split_sz(tr[now].son[1],k-tr[tr[now].son[0]].sz-1,tr[now].son[1],y);
        else y=now,split_sz(tr[now].son[0],k,x,tr[now].son[0]);
        pushup(now);
    }
    inline void insert(res &RT,const res &v){
        res a,b;
        split(RT,v,a,b),change(a,1),RT=merge(merge(a,newnode(v,v+tr[b].sz)),b);
    }
    void dfs(res x,res fax){
        rt[x]=0;
        for(auto tox:G[x]){
            if(tox==fax)continue;
            dfs(tox,x),insert(rt[x],f[tox]);
        }
        f[x]=max(1,tr[rt[x]].mx);
//        printf("%d %d\n",x,f[x]);
    }
    int g[N];
    inline void erase(res &RT,const res &v){
        res a,b,c,d;
//        printf("%d %d\n",RT,tr[RT].sz);
        split(RT,v,a,b),/*printf("%d %d\n",a,b),*/split_sz(a,tr[a].sz-1,c,d);/*printf("%d %d\n",c,d)*///printf("%d %d %d\n",b,tr[b].son[0],tr[b].son[1]);
        if(d)st[++top]=d;
        change(c,-1),/*printf("%d %d\n",tr[d].son[0],tr[d].son[1]),*/RT=merge(c,b);
    }
    inline int get(res &RT){
        res a,b,ret=0;
        split_sz(RT,tr[RT].sz-1,a,b),ret=tr[b].va-1+max(1,tr[a].mx);
        RT=merge(a,b);
        return ret;
    }
    void Dfs(res x,res fax){
        g[x]=get(rt[x]);
//        printf("%d %d\n",x,g[x]);
        for(auto tox:G[x]){
            if(tox==fax)continue;
            //printf("%d %d %d %d\n",x,rt[x],tox,rt[tox]);
            res F=f[x],G=f[tox];
            //puts("OK");
            erase(rt[x],f[tox]);/*puts("ok"),*/f[x]=max(1,tr[rt[x]].mx);
            insert(rt[tox],f[x]),f[tox]=max(1,tr[rt[tox]].mx);
            //puts("oK");
            Dfs(tox,x),f[x]=F,f[tox]=G,insert(rt[x],f[tox]);
        }
    }
    inline bool cmp(const res &x,const res &y){
        return f[x]>f[y];
    }
    int Ans[2],Ansx;
    inline int ask(const res &x){
        printf("? %d\n",x),fflush(stdout);
        return read();
    }
    int get(res x,res fax){
        sort(G[x].begin(),G[x].end(),cmp);
        res r=0;
        for(auto tox:G[x]){
            if(tox==fax)continue;
            res ret=get(tox,x);
            if(x!=ret)return ret;
            r=1;
        }
        if(!r)return ask(x);
        return x;
    }
    inline void MAIN(){
        n=read();
        for(res i=1;i<n;i++){
            res u=read(),v=read();
            G[u].pb(v),G[v].pb(u);
        }
        dfs(1,0),Dfs(1,0);
        res ans=0;
        for(res i=1;i<=n;i++)ans=max(ans,g[i]);
        printf("%d\n",ans),fflush(stdout),tot=top=0;
        res f=read();
        dfs(f,0),sort(G[f].begin(),G[f].end(),cmp);
        for(auto tox:G[f]){
            res tmp=get(tox,f);
            if(tmp==f)continue;
            Ans[Ansx++]=tmp;
            if(Ansx==2)break;
        }
        if(!Ans[0])Ans[0]=f;
        if(!Ans[1])Ans[1]=f;
        printf("! %d %d\n",Ans[0],Ans[1]),fflush(stdout);
    }
}
int main(){
    srand(19260817);
//    freopen("data.in","r",stdin);
//    freopen("1.out","w",stdout);
    MAIN::MAIN();
//    Ot();
    return 0;
}