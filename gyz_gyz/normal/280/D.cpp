#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 131072
using namespace std;
int L[N*2],R[N*2],lz[N*2],l1[30],r1[30],n,m,l,r,x,y,ty;
struct pr{int a,b0,b1,c0,c1,d0,d1,l0,l1,r0,r1,L0,L1,R0,R1;
    pr operator +(const pr &b){pr x;x.a=a+b.a;
        if(a+b.b0>b0)x.b0=a+b.b0,x.L0=b.L0;else x.b0=b0,x.L0=L0;
        if(a+b.b1<b1)x.b1=a+b.b1,x.L1=b.L1;else x.b1=b1,x.L1=L1;
        if(c0+b.a>b.c0)x.c0=c0+b.a,x.R0=R0;else x.c0=b.c0,x.R0=b.R0;
        if(c1+b.a<b.c1)x.c1=c1+b.a,x.R1=R1;else x.c1=b.c1,x.R1=b.R1;
        if(d0>b.d0)x.d0=d0,x.l0=l0,x.r0=r0;else x.d0=b.d0,x.l0=b.l0,x.r0=b.r0;
        if(d1<b.d1)x.d1=d1,x.l1=l1,x.r1=r1;else x.d1=b.d1,x.l1=b.l1,x.r1=b.r1;
        if(c0+b.b0>x.d0)x.d0=c0+b.b0,x.l0=R0,x.r0=b.L0;
        if(c1+b.b1<x.d1)x.d1=c1+b.b1,x.l1=R1,x.r1=b.L1;return x;
    }
}pp,a[N*2];
inline void qf(int x){
    lz[x]^=1;a[x].a=-a[x].a;int tp;
    tp=-a[x].b0;a[x].b0=-a[x].b1;a[x].b1=tp;
    tp=-a[x].c0;a[x].c0=-a[x].c1;a[x].c1=tp;    
    tp=-a[x].d0;a[x].d0=-a[x].d1;a[x].d1=tp;
    tp=a[x].l0;a[x].l0=a[x].l1;a[x].l1=tp;
    tp=a[x].r0;a[x].r0=a[x].r1;a[x].r1=tp;
    tp=a[x].L0;a[x].L0=a[x].L1;a[x].L1=tp;
    tp=a[x].R0;a[x].R0=a[x].R1;a[x].R1=tp;
}
inline void dw(int x){if(lz[x]){lz[x]=0;qf(x*2);qf(x*2+1);}}
inline void up(int x){
    a[x]=a[x*2]+a[x*2+1];
}
void F(int x,int y,int z){
    if(y==L[x]&&y==R[x]){
        a[x].a=a[x].b0=a[x].b1=a[x].c0=a[x].c1=a[x].d0=a[x].d1=z;
        a[x].l0=a[x].l1=a[x].r0=a[x].r1=a[x].L0=a[x].L1=a[x].R0=a[x].R1=y;return;
    }
    dw(x);if(y<=R[x*2])F(x*2,y,z);else F(x*2+1,y,z);up(x);
}
void f(int x,int l,int r){
    if(l==L[x]&&r==R[x]){qf(x);return;}dw(x);
    if(r<=R[x*2]){f(x*2,l,r);up(x);return;}
    if(l>=L[x*2+1]){f(x*2+1,l,r);up(x);return;}
    f(x*2,l,R[x*2]);f(x*2+1,L[x*2+1],r);up(x);
}
pr q(int x,int l,int r){
    if(l==L[x]&&r==R[x])return a[x];dw(x);
    if(r<=R[x*2])return q(x*2,l,r);
    if(l>=L[x*2+1])return q(x*2+1,l,r);
    return q(x*2,l,R[x*2])+q(x*2+1,L[x*2+1],r);
}
int main(){
    scanf("%d",&n);
    rep(i,1,n){
        x=i+N-1;scanf("%d",&a[x].a);
        a[x].b0=a[x].b1=a[x].c0=a[x].c1=a[x].d0=a[x].d1=a[x].a;
    }
    rep(i,1,N){int x=i+N-1;
        a[x].l0=a[x].l1=a[x].r0=a[x].r1=a[x].L0=a[x].L1=a[x].R0=a[x].R1=i;
    }
    L[1]=1;R[1]=N;
    rep(i,1,N-1){
        L[i*2]=L[i];R[i*2]=(L[i]+R[i])/2;
        L[i*2+1]=R[i*2]+1;R[i*2+1]=R[i];
    }
    dep(i,N-1,1)up(i);
    scanf("%d",&m);
    rep(i,1,m){
        scanf("%d",&ty);
        if(ty){
            scanf("%d%d%d",&l,&r,&x);y=0;
            rep(j,1,x){
                pp=q(1,l,r);if(pp.d0<=0){x=j-1;break;}
                y+=pp.d0;l1[j]=pp.l0;r1[j]=pp.r0;f(1,l1[j],r1[j]);
            }
            rep(j,1,x)f(1,l1[j],r1[j]);
            printf("%d\n",y);
        }else{
            scanf("%d%d",&x,&y);F(1,x,y);
        }
    }
}