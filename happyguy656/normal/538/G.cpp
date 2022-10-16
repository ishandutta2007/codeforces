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

const int mxn=2e5+3,mxm=2e6+3;
int n,m,r1,r2,a1[mxm],a2[mxm];struct thr{ll x,y,z;}b1[mxn*2],*p1[mxn],*p2[mxn];
bool cmp1(thr*x,thr*y){return x->y<y->y;}
ll qz1(ll x,ll y){if(x%y==0)return x/y;return x>=0?x/y:x/y-1;}
ll qz2(ll x,ll y){return x%y==0?x/y:qz1(x,y)+1;}
bool wk(){
    int k=0;
    for(int i=1;i<=n;++i){
        ll t,x,y;scanf("%lld%lld%lld",&t,&x,&y);x-=y,y=x+2*y;
        if((x-t)%2)return 0;
        b1[++k]=(thr){t/m,t%m,x},b1[++k]=(thr){t/m,t%m,y};
        p1[i]=b1+k-1,p2[i]=b1+k;
    }
    b1[++k]=(thr){-1,m,0};
    sort(p1+1,p1+n+1,cmp1),sort(p2+1,p2+n+1,cmp1);
    p1[0]=p2[0]=b1,p1[n+1]=p2[n+1]=b1+k;
    ll l=-m,r=m;thr t1,t2;
    for(int i=1;i<=n+1;++i){
        t1=*p1[i-1],t2=*p1[i];
        ll k=t2.x-t1.x,d=t2.y-t1.y,c=t2.z-t1.z;
        if(k==0){if(c<-d||c>d)return 0;}
        else{
            if(k<0)k=-k,c=-c;
            l=max(l,qz2(c-d,k)),r=min(r,qz1(c+d,k));
        }
    }
    if((l-m)%2)++l;if(l>r)return 0;
    for(int i=1;i<=n+1;++i){
        t1=*p1[i],t2=*p1[i-1];int x1=t2.y,x2=t1.y;
        a1[x2]=t1.z-t1.x*l;
        for(int j=x1+1;j<x2;++j){
            if(a1[j-1]>a1[x2])a1[j]=a1[j-1]-1;else a1[j]=a1[j-1]+1;
        }
    }
    
    l=-m,r=m;
    for(int i=1;i<=n+1;++i){
        t1=*p2[i-1],t2=*p2[i];
        ll k=t2.x-t1.x,d=t2.y-t1.y,c=t2.z-t1.z;
        if(k==0){if(c<-d||c>d)return 0;}
        else{
            if(k<0)k=-k,c=-c;
            l=max(l,qz2(c-d,k)),r=min(r,qz1(c+d,k));
        }
    }
    if((l-m)%2)++l;if(l>r)return 0;
    for(int i=1;i<=n+1;++i){
        t1=*p2[i],t2=*p2[i-1];int x1=t2.y,x2=t1.y;
        a2[x2]=t1.z-t1.x*l;
        for(int j=x1+1;j<x2;++j){
            if(a2[j-1]>a2[x2])a2[j]=a2[j-1]-1;else a2[j]=a2[j-1]+1;
        }
    }
    return 1;
}
int main(){
    scanf("%d%d",&n,&m);if(!wk())return puts("NO"),0;
    for(int i=m;i;--i)a1[i]-=a1[i-1],a2[i]-=a2[i-1];
    for(int i=1;i<=m;++i)if(a1[i]==1&&a2[i]==1)putchar('R');else if(a1[i]==-1&&a2[i]==-1)putchar('L');else if(a1[i]==-1&&a2[i]==1)putchar('U');else if(a1[i]==1&&a2[i]==-1)putchar('D');puts("");
    return 0;
}