#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 524288
#define mo 1000000009
#define ll long long
using namespace std;
const int P=691504013,Q=308495997;
int n,m,x,l,r;ll a[N*2],b[N*2],c[N*2],L[N*2],R[N*2],p[N],q[N];
inline void up(int x){a[x]=a[x*2]+a[x*2+1]%mo;}
inline void dw(int x){int t=(R[x]-L[x]+1)/2;
    b[x*2]=(b[x*2]+b[x])%mo;b[x*2+1]=(b[x*2+1]+b[x]*p[t])%mo;
    c[x*2]=(c[x*2]+c[x])%mo;c[x*2+1]=(c[x*2+1]+c[x]*q[t])%mo;
    a[x*2+1]=(a[x*2+1]+(p[t]-1)*P%mo*b[x]%mo*p[t]+(q[t]-1)*Q%mo*c[x]%mo*q[t])%mo;
    a[x*2]=(a[x*2]+(p[t]-1)*P%mo*b[x]+(q[t]-1)*Q%mo*c[x])%mo;b[x]=0;c[x]=0;
}
void f1(int x,ll y,int l,int r){
    if(l==L[x]&&r==R[x]){b[x]=(b[x]+y)%mo;
        a[x]=(a[x]+(p[r-l+1]-1)*P%mo*y)%mo;return;
    }dw(x);
    if(r<=R[x*2]){f1(x*2,y,l,r);up(x);return;}
    if(l>=L[x*2+1]){f1(x*2+1,y,l,r);up(x);return;}
    f1(x*2,y,l,R[x*2]);f1(x*2+1,y*p[L[x*2+1]-l]%mo,L[x*2+1],r);up(x);
}
void f2(int x,ll y,int l,int r){
    if(l==L[x]&&r==R[x]){c[x]=(c[x]+y)%mo;
        a[x]=(a[x]+(q[r-l+1]-1)*Q%mo*y)%mo;return;
    }dw(x);
    if(r<=R[x*2]){f2(x*2,y,l,r);up(x);return;}
    if(l>=L[x*2+1]){f2(x*2+1,y,l,r);up(x);return;}
    f2(x*2,y,l,R[x*2]);f2(x*2+1,y*q[L[x*2+1]-l]%mo,L[x*2+1],r);up(x);
}
ll qs(int x,int l,int r){
    if(l==L[x]&&r==R[x])return a[x];dw(x);
    if(r<=R[x*2])return qs(x*2,l,r);
    if(l>=L[x*2+1])return qs(x*2+1,l,r);
    return (qs(x*2,l,R[x*2])+qs(x*2+1,L[x*2+1],r))%mo;
}
int main(){
    scanf("%d%d",&n,&m);p[0]=1;q[0]=1;
    rep(i,1,n)p[i]=p[i-1]*P%mo,q[i]=q[i-1]*Q%mo;
    p[0]=1;q[0]=1;L[1]=1;R[1]=N;
    rep(i,1,N-1){
        L[i*2]=L[i];R[i*2]=(L[i]+R[i])/2;
        L[i*2+1]=R[i*2]+1;R[i*2+1]=R[i];
    }
    rep(i,1,n)scanf("%I64d",&a[N+i-1]);
    dep(i,N-1,1)up(i);
    rep(i,1,m){
        scanf("%d%d%d",&x,&l,&r);
        if(x==1){
            f1(1,138300803,l,r);
            f2(1,861699207,l,r);
        }else printf("%I64d\n",qs(1,l,r));
    }
}