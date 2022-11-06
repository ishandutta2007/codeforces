#include<cstdio>
#include<cstring>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define mx 100001
#define mc 8193
#define lb(x) ((x)&(-(x)))
using namespace std;
int n,m,s,q,dir,j,a[mc][mc];
int qs[mx],dr[mx],x[mx],y[mx],l[mx],ans[mx];
struct pr{int x,y,l;}p[mx],t[mx];
inline bool cmp0(pr x,pr y){
    return x.x+x.y>y.x+y.y;
}
inline bool cmp1(pr x,pr y){
    return x.x+x.y+x.l>y.x+y.y+y.l;
}
inline void ins(int x,int y){
    for(int i=x;i<mc;i+=lb(i))
        for(int j=y;j<mc;j+=lb(j))a[i][j]++;
}
inline void del(int x,int y){
    for(int i=x;i<mc;i+=lb(i))
        for(int j=y;j<mc;j+=lb(j))a[i][j]--;
}
inline int f(int x,int y){int s=0;
    for(int i=x;i;i-=lb(i))
        for(int j=y;j;j-=lb(j))s+=a[i][j];
    return s;
}
inline void cal(){
    sort(t+1,t+s+1,cmp0);
    sort(p+1,p+m+1,cmp1);j=1;
    rep(i,1,s){
        for(;j<=m&&p[j].x+p[j].y+p[j].l>=t[i].x+t[i].y;j++)ins(p[j].x,p[j].y);
        ans[t[i].l]+=f(t[i].x,t[i].y);
    }
    rep(i,1,j-1)del(p[i].x,p[i].y);
}   
void sol(int L,int R){
    if(L==R)return;int mid=(L+R)/2;
    sol(L,mid);sol(mid+1,R);
    s=0;rep(i,mid+1,R)if(qs[i]==2){
        t[++s].x=x[i];t[s].y=y[i];t[s].l=i;
    }
    m=0;rep(i,L,mid)if(qs[i]==1&&dr[i]==1){
        p[++m].x=x[i];p[m].y=y[i];p[m].l=l[i];
    }cal();
    rep(i,1,s)t[i].y=mc-t[i].y;
    m=0;rep(i,L,mid)if(qs[i]==1&&dr[i]==2){
        p[++m].x=x[i];p[m].y=mc-y[i];p[m].l=l[i];
    }cal();
    rep(i,1,s)t[i].x=mc-t[i].x;
    m=0;rep(i,L,mid)if(qs[i]==1&&dr[i]==4){
        p[++m].x=mc-x[i];p[m].y=mc-y[i];p[m].l=l[i];
    }cal();
    rep(i,1,s)t[i].y=mc-t[i].y;
    m=0;rep(i,L,mid)if(qs[i]==1&&dr[i]==3){
        p[++m].x=mc-x[i];p[m].y=y[i];p[m].l=l[i];
    }cal();
}
int main(){
    scanf("%d%d",&n,&q);
    rep(i,1,q){
        scanf("%d",&qs[i]);
        if(qs[i]==2)scanf("%d%d",&x[i],&y[i]);
        else scanf("%d%d%d%d",&dr[i],&x[i],&y[i],&l[i]);
    }
    sol(1,q);rep(i,1,q)if(qs[i]==2)printf("%d\n",ans[i]);
}