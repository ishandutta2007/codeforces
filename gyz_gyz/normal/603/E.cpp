#include<cstdio>
#include<set>
#include<algorithm>
#define N 500000
#define inf 1000000000
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
using namespace std;
int a[N][2],mi[N],s[N],lz[N],sz[N],fz[N],f[N];
int n,m,x,y,z,w,od;
struct pr{int x,y,w;
    bool operator < (const pr&a)const{
        if(w!=a.w)return w>a.w;
        if(x!=a.x)return x<a.x;return y<a.y;
    }
}pp;
set<pr>mts;
inline void up(int x){
    int l=a[x][0],r=a[x][1];mi[x]=x;lz[x]=sz[x];
    if(l){lz[x]+=lz[l];if(s[mi[l]]>s[mi[x]])mi[x]=mi[l];}
    if(r){lz[x]+=lz[r];if(s[mi[r]]>s[mi[x]])mi[x]=mi[r];}
}
inline void dw(int x){
    if(!fz[x])return;fz[x]=0;
    fz[a[x][0]]^=1;fz[a[x][1]]^=1;
    swap(a[x][0],a[x][1]);
}
inline bool rt(int x){
    return a[f[x]][0]!=x&&a[f[x]][1]!=x;
}
inline void ro(int x){
    int y=f[x],z=f[y],l,r;
    l=(a[y][1]==x);r=l^1;
    if(!rt(y))a[z][a[z][1]==y]=x;
    f[x]=z;f[y]=x;f[a[x][r]]=y;
    a[y][l]=a[x][r];a[x][r]=y;up(y);up(x);
}
inline void sp(int x){dw(x);up(x);
    while(!rt(x)){int y=f[x];dw(f[y]);dw(y);dw(x);
        if(!rt(y)){if((a[y][0]==x)^(a[f[y]][0]==y))ro(x);
        else ro(y);}ro(x);
    }
}
inline void ac(int x){
    for(int y=0;x;x=f[x]){
        sp(x);dw(a[x][0]);sz[x]+=lz[a[x][0]];
        a[x][0]=y;up(a[x][0]);sz[x]-=lz[a[x][0]];y=x;
    }
}
inline void hg(int x){ac(x);sp(x);fz[x]^=1;}
inline int ff(int x){
    ac(x);if(!a[x][1])return f[x];x=a[x][1];
    for(dw(x);a[x][0];dw(x))x=a[x][0];return x;
}
inline int so(int x){
    sp(x);x=a[x][0];
    for(dw(x);a[x][1];dw(x))x=a[x][1];return x;
}
inline void link(int x,int y){
    hg(x);ac(y);sp(y);sp(x);sz[y]+=lz[x];f[x]=y;
}
inline void lk(int x,int y,int w,int id){s[id]=w;
    link(x,id);link(id,y);pp.x=x;pp.y=y;pp.w=w;
    if(pp.x>pp.y)swap(pp.x,pp.y);mts.insert(pp);
}
inline void cut(int x){int y=ff(x);
    hg(y);ac(x);sp(x);a[x][1]=f[y]=0;sp(y);
}
inline void ct(int x){
    int y=ff(x);pp.w=s[y];pp.x=x;pp.y=ff(y);
    if(pp.x>pp.y)swap(pp.x,pp.y);
    cut(y);cut(x);mts.erase(pp);
}
inline int top(int x){while(f[x])x=f[x];return x;}
int main(){
    scanf("%d%d",&n,&m);od=n;
    rep(i,1,n)sz[i]=1,lz[i]=1;
    rep(i,1,n+m)mi[i]=i;
    rep(i,1,m){
        scanf("%d%d%d",&x,&y,&w);
        hg(x);ac(y);sp(x);
        if(top(y)!=x){sp(y);
            if(lz[x]%2==1&&lz[y]%2==1)od-=2;lk(x,y,w,i+n);
        }else{z=mi[x];
            if(s[z]>w){ct(so(z));lk(x,y,w,i+n);}
        }
        if(od){printf("-1\n");continue;}
        for(;;){pp=*mts.begin();
            x=pp.x;y=pp.y;w=pp.w;
            hg(x);ac(y);sp(y);
            if((lz[y]-lz[a[y][1]])%2==0)ct(y);else break;
        }
        printf("%d\n",w);
    }
}