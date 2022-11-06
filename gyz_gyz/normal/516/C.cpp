#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define Rep(i,x,y) for(int i=(x);i>=(y);i--)
#define max(x,y) (((x)>(y))?(x):(y))
#define mx 262144
using namespace std;
struct pp{long long a,b,c,d;}a[mx*2+1];int n,m,x,y;
pp q(int x,int l,int r,int ml,int mr){
    if((l==ml)&&(r==mr))return a[x];int mid=(ml+mr)/2;
    if(r<=mid)return(q(x*2,l,r,ml,mid));
    if(l>mid)return(q(x*2+1,l,r,mid+1,mr));
    pp px;pp pl=q(x*2,l,mid,ml,mid);
    pp pr=q(x*2+1,mid+1,r,mid+1,mr);
    px.b=max(pl.b,pr.b+pl.d);px.c=max(pr.c,pl.c+pr.d);
    px.d=pl.d+pr.d;px.a=max(pl.c+pr.b,max(pl.a,pr.a));
    return px;
}
int main(){
    scanf("%d%d",&n,&m);
    rep(i,1,n)scanf("%I64d",&a[mx+i-1].d);
    rep(i,1,n){
        scanf("%d",&x);
        a[mx+i-1].b=x*2;
        a[mx+i-1].c=a[mx+i-1].d+x*2;
    }
    rep(i,1,n)a[mx+i+n-1]=a[mx+i-1];
    Rep(i,mx-1,1){
        a[i].d=a[i*2].d+a[i*2+1].d;
        a[i].b=max(a[i*2].b,a[i*2+1].b+a[i*2].d);
        a[i].c=max(a[i*2+1].c,a[i*2].c+a[i*2+1].d);     
        a[i].a=max(a[i*2].c+a[i*2+1].b,max(a[i*2].a,a[i*2+1].a));
    }
    rep(i,1,m){
        scanf("%d%d",&x,&y);
        if(x>y)printf("%I64d\n",q(1,y+1,x-1,1,mx).a);
        else printf("%I64d\n",q(1,y+1,x+n-1,1,mx).a);
    }
}