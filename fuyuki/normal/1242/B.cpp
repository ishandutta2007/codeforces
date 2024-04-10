#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
    rnt _s=0;re char _ch=gc;
    while(!isnum(_ch))_ch=gc;
    while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
    return _s;
}
const int N=1e5+1,logN=200,INF=0x3f3f3f3f;
int n,m,tot,ans,rt[N];
struct ele{
    int ls,rs,minn;
}t[N*logN];
#define lc t[p].ls
#define rc t[p].rs
#define lson lc,L,mid
#define rson rc,mid+1,R
I min(const int&x,const int&y){return x<y?x:y;}
V update(rnt p){t[p].minn=min(t[lc].minn,t[rc].minn);}
V ins(int&p,rnt L,rnt R,rnt x,rnt w){
    if(!p)p=++tot;
    if(L==R)return t[p].minn=w,void();
    rnt mid=L+R>>1;
    if(x<=mid)ins(lson,x,w);
    else ins(rson,x,w);
    update(p);
}
V input(){
    n=getint(),m=getint();rnt x,y;
    while(m--)x=getint(),y=getint(),ins(rt[x],1,n,y,1),ins(rt[y],1,n,x,1);
}
V init(){FOR(i,1,n)ins(rt[i],1,n,i,INF);}
I merge(rnt x,rnt y,rnt L,rnt R){
    if(!x||!y)return x|y;
    if(L==R)return t[x].minn+=t[y].minn,x;
    rnt mid=L+R>>1;
    t[x].ls=merge(t[x].ls,t[y].ls,L,mid);
    t[x].rs=merge(t[x].rs,t[y].rs,mid+1,R);
    return update(x),x;
}
I ask(rnt p,rnt L,rnt R,rnt lim){
    if(L==R)return L;
    rnt mid=L+R>>1;
    if(t[lc].minn<lim)return ask(lson,lim);
    return ask(rson,lim);
}
int tag[N],fa[N],siz[N];
I find(rnt x){return x==fa[x]?x:fa[x]=find(fa[x]);}
V work(){
    ans=n-1;
    FOR(i,1,n)fa[i]=i,siz[i]=1;
    FOR(i,1,n)if(find(i)==i){
        while(t[rt[i]].minn<siz[i]){
            rnt p=find(ask(rt[i],1,n,siz[i]));
            rt[i]=merge(rt[i],rt[p],1,n),fa[p]=i,ans--,siz[i]+=siz[p];
        }
    }
    cout<<ans;
}
int main(){
    input();
    init();
    work();
    return 0;
}