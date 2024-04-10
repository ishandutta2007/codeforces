#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define N 131072
#define ll long long
using namespace std;
int n,m,x,l,r,b[N*2],L[N*2],R[N*2];ll a[N*2],c[N*2];
inline ll abs(int x){if(x<0)return -x;else return x;}
inline void up(int x){
    a[x]=a[x*2]+a[x*2+1];
    if(b[x*2]==b[x*2+1])b[x]=b[x*2];else b[x]=0;
}
inline void dw(int x){
    int t=(R[x]-L[x]+1)/2;
    a[x*2]+=c[x]*t;a[x*2+1]+=c[x]*t;
    c[x*2]+=c[x];c[x*2+1]+=c[x];c[x]=0;
    if(b[x])b[x*2]=b[x*2+1]=b[x];
}
void f(int x,int y,int l,int r){
    if(l==L[x]&&r==R[x]&&b[x]){
        a[x]+=abs(b[x]-y)*(r-l+1);
        c[x]+=abs(b[x]-y);b[x]=y;return;
    }dw(x);
    if(r<=R[x*2]){f(x*2,y,l,r);up(x);return;}
    if(l>=L[x*2+1]){f(x*2+1,y,l,r);up(x);return;}
    f(x*2,y,l,R[x*2]);f(x*2+1,y,L[x*2+1],r);up(x);
}
ll q(int x,int l,int r){
    if(l==L[x]&&r==R[x])return a[x];dw(x);
    if(r<=R[x*2])return q(x*2,l,r);
    if(l>=L[x*2+1])return q(x*2+1,l,r);
    return q(x*2,l,R[x*2])+q(x*2+1,L[x*2+1],r);
}
int main(){
    scanf("%d%d",&n,&m);
    L[1]=1;R[1]=N;
    rep(i,1,N-1){
        L[i*2]=L[i];R[i*2]=(L[i]+R[i])/2;
        L[i*2+1]=R[i*2]+1;R[i*2+1]=R[i];
    }
    rep(i,1,n)b[N+i-1]=i;
    rep(i,1,m){
        scanf("%d%d%d",&x,&l,&r);
        if(x==1){scanf("%d",&x);f(1,x,l,r);}
        else printf("%I64d\n",q(1,l,r));
    }
}