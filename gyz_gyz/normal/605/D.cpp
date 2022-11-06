#include<stdio.h>
#include<map>
#include<set>
#include<algorithm>
#define lowbit(o) o&-o
#define N 200005
using namespace std;
struct node1 {
    int x,y,xx,yy;
}a[N];
struct lhy {
    int id,v;
};
struct syf {
    bool operator()(const lhy &a,const lhy &b)  {
        if (a.v!=b.v)
        return a.v<b.v;
        return a.id<b.id;
    }
};
set<lhy,syf>f[N*2];
set<lhy,syf>::iterator gt;
int last[N],q[N*2],r,i,dis[N],j,k,l,s,n,m,Q[N],S,tot;
map<int,int>ma;
inline void change(int o,int p) {
    lhy gtw;
    gtw.v=a[p].y; gtw.id=p;
    for (;o<=tot;o+=lowbit(o)) f[o].insert(gtw);
}
inline void ask(int o,int p) {
    for (;o;o-=lowbit(o)) {
        for (gt=f[o].begin();gt!=f[o].end();gt++) {
            if ((*gt).v<=p) Q[++S]=(*gt).id;
            else break;
        }
    }
}
inline void del(int o,int p) {
    lhy gtw;
    gtw.v=a[p].y; gtw.id=p;
    for (;o<=tot;o+=lowbit(o)) f[o].erase(gtw);
}
int main() {
    scanf("%d",&n);
    for (i=1;i<=n;i++) scanf("%d%d%d%d",&a[i].x,&a[i].y,&a[i].xx,&a[i].yy),q[++r]=a[i].x,q[++r]=a[i].xx;
    q[++r]=0;
    sort(q+1,q+1+r);
    q[0]=q[1]-1;
    for (i=1;i<=r;i++) if (q[i]!=q[i-1]) ma[q[i]]=++tot;
    for (i=1;i<=n;i++) a[i].x=ma[a[i].x],a[i].xx=ma[a[i].xx];
    for (i=1;i<=n;i++) change(a[i].x,i),dis[i]=-1;
    l=0,r=1; q[1]=0;
    a[0].xx=ma[0];
    while (l<r) {
        int k=q[++l];
        S=0;
        ask(a[k].xx,a[k].yy);
        for (int i=1;i<=S;i++) {
            dis[Q[i]]=dis[k]+1;
            last[Q[i]]=k;
            del(a[Q[i]].x,Q[i]);
            q[++r]=Q[i];
        }
    }
    printf("%d\n",dis[n]);
    if (dis[n]!=-1) {
        r=0;
        for (i=n;i;i=last[i]) q[++r]=i;
        for (i=r;i;i--) printf("%d ",q[i]);
    }
}