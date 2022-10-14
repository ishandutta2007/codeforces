#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define lc ch[x][0]
#define rc ch[x][1]
#define re register
#define I inline int
#define V inline void
#define B inline bool
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define REP(u) for(rnt _=h[u],v;v=e[_].t,_;_=e[_].n)if(v^fa[u])
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
    rnt _s=0;re char _ch=gc;
    while(!isnum(_ch))_ch=gc;
    while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
    return _s;
}
const int N=2e5+1,mod=998244353;
I Pow(ll t,rnt x){
    ll s=1;
    for(;x;x>>=1,t=t*t%mod)if(x&1)s=s*t%mod;
    return s;
}
V check(int&x){x-=mod,x+=x>>31&mod;}
int n,m,tot;
int h[N],siz[N],nxt[N];
int fa[N],ch[N][2],val[N],a[N],w[N];
struct edge{int t,n;}e[N<<1];
V add_edge(rnt x,rnt y){
    e[++tot]=(edge){y,h[x]},h[x]=tot;
    e[++tot]=(edge){x,h[y]},h[y]=tot;
}
V input(){
    n=getint(),m=getint();rnt x,y;
    FOR(i,2,n)x=getint(),y=getint(),add_edge(x,y);
}
V dfs(rnt u){siz[u]=1;REP(u)fa[v]=u,dfs(v),siz[u]+=siz[v];}
V init(){dfs(1);}
I id(rnt x){return x==ch[fa[x]][1];}
B nrt(rnt x){return x==ch[fa[x]][id(x)];}
V update(rnt x){
    check(w[x]=w[lc]+w[rc]),check(w[x]+=a[x]);
    check(w[x]+=1ll*val[x]*siz[nxt[x]]%mod);
}
V rot(rnt x){
    rnt y=fa[x],z=fa[y],k=id(x);
    if(nrt(y))ch[z][id(y)]=x;
    ch[y][k]=ch[x][!k],ch[x][!k]=y;
    if(ch[y][k])fa[ch[y][k]]=y;
    fa[x]=z,fa[y]=x,update(y),update(x);
}
V splay(rnt x){
    if(x)for(rnt p;nrt(x);rot(x))
        if(nrt(p=fa[x]))
            rot(id(x)==id(p)?p:x);
}
I root(rnt x){return lc?root(lc):x;}
V access(rnt x){
    for(rnt y=0,p=x;p;p=fa[y=p])
        splay(p),splay(nxt[p]=root(y)),ch[p][1]=nxt[p],update(p);
    splay(x);
}
V work(){
    rnt opt,x,d,now,sum=0,inv=Pow(n,mod-2);
    while(m--){
        opt=getint(),x=getint();
        if(opt==1){
            d=getint();
            access(x);
            check(val[x]+=d),check(sum+=d);
            d=1ll*(n-siz[x])*d%mod;
            check(sum+=1ll*(mod-d)*inv%mod),check(a[x]+=mod-d);
        }
        else access(x),cout<<(sum+mod-1ll*w[x]*inv%mod)%mod<<'\n';
    }
}
int main(){
    input();
    init();
    work();
    return 0;
}