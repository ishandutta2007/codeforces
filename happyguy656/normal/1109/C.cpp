#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(register int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf a14=scanf
#define rint register int
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
int a14;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=1e5+3;
int n;
struct nod{
    nod*ls,*rs;ll sum,s2,v;int l,r,va;
    inline ll sd(){return v>=0?0:sd2();}
    inline ll sd2(){return (r-l)*v;}
    void up(){sum=ls->sum+rs->sum+sd2(); s2=min(min(ls->s2,ls->sum+sd()),ls->sum+sd2()+rs->s2);}
}*h,*T1,*T2;
struct QQQQQQQ{
    nod*rt,*cur;
    void init(){h=new nod[n+1];h->ls=h->rs=h,h->sum=h->s2=0;cur=rt=h;}
    nod*newd(){nod*x=++cur;*x=*h;x->va=rand();return x;}
    void split(nod*r,int b,nod*&x=T1,nod*&y=T2){
        if(r==h)return x=y=h,void();
        if(r->l<=b)x=r,split(r->rs,b,r->rs,y);
        else y=r,split(r->ls,b,x,r->ls);
        r->up();
    }
    nod*mer(nod*x,nod*y){
        if(x==h)return y;if(y==h)return x;
        if(x->va<y->va){x->rs=mer(x->rs,y);x->up();return x;}
        else {y->ls=mer(x,y->ls);y->up();return y;}
    }
    void ins(int l,int v){
        nod*d2=nxt(l),*x=newd();
        x->l=l,x->r=d2==h?1e9+3:d2->l; x->v=v;x->up();
        split(rt,l);rt=T1,cmax(l);
        rt=mer(T1,x),rt=mer(rt,T2);
    }
    void del(int l){
        split(rt,l-1);nod*t=T1;split(T2,l);
        rt=t;cmax(T1->r);
        rt=mer(t,T2);
    }
    nod*pre(int v){nod*x=rt,*r=h;while(x!=h){if(x->l<=v)r=x,x=x->rs;else x=x->ls;}return r;}
    nod*nxt(int v){nod*x=rt,*r=h;while(x!=h){if(x->l>=v)r=x,x=x->ls;else x=x->rs;}return r;}
    double ask(int l,int r,ll s){
        if(!s)return l;if(rt==h)return -1e100;
        split(rt,l-1);nod*tx=T1;split(T2,r);
        rt=T1;cmax(r);
        nod*x=rt;double res=-1e100;
        while(x!=h){
            if(x->ls!=h&&x->ls->s2+s<=0)x=x->ls;
            else{
                s+=x->ls->sum;if(s+x->sd()<=0){res=x->l+1.0*s/(-x->v);break;}
                else s+=x->sd2(),x=x->rs;
            }
        }
        cmax(r0);
        rt=mer(T1,T2),rt=mer(tx,rt);return res;
    }
    int r0;
    void cmax(int v){
        if(rt==h)return;
        static nod*xl[mxn];int xn=0;
        nod*x=rt;xl[++xn]=x;while(x->rs!=h)x=x->rs,xl[++xn]=x;
        r0=x->r,x->r=v;for(int i=xn;i;--i)xl[i]->up();
    }
}fh;
int main(){
    srand(time(0));
    scanf("%d",&n);fh.init();
    for(int T=1;T<=n;++T){
        int op,x,y,z;scanf("%d",&op);if(op==1)scanf("%d%d",&x,&y),fh.ins(x,y);
        else if(op==2)scanf("%d",&x),fh.del(x);
        else if(op==3){scanf("%d%d%d",&x,&y,&z);double r=fh.ask(x,y,z);if(r<-1e50)puts("-1");else printf("%.9f\n",r);}
    }
    return 0;
}