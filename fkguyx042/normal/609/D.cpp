#include<stdio.h>
#include<algorithm>
using namespace std;
#define N 200005
int ans1,i,j,k,l,s,n,m,xx,y,x[N],X[N],a[N],b[N],R,r,ans,S;
long long e[N],E[N];
struct node {
    long long v;
    int id;
}q[N],Q[N];
inline bool cmp(const node &x,const node &y) {
    return x.v<y.v;
}
inline bool check(int o,int x,int y) {
    if (x>r||y>R) return false;
    if (E[y]>S||e[x]>S) return false;
    long long s=1ll*a[o]*e[x]+1ll*b[o]*E[y];
    if (s>S) return false;
    return true;
}
int main() {
    scanf("%d%d%d%d",&n,&m,&k,&S);
    a[0]=b[0]=1000000000;
    for (i=1;i<=n;i++) scanf("%d",&x[i]),a[i]=min(a[i-1],x[i]);
    for (i=1;i<=n;i++) scanf("%d",&X[i]),b[i]=min(b[i-1],X[i]);
    for (i=1;i<=m;i++) {
        scanf("%d%d",&xx,&y);
        if (xx==1) q[++r].v=y,q[r].id=i;
        else Q[++R].v=y,Q[R].id=i;
    }
    sort(q+1,q+1+r,cmp); sort(Q+1,Q+1+R,cmp);
    for (i=1;i<=r;i++) e[i]=e[i-1]+q[i].v;
    for (i=1;i<=R;i++) E[i]=E[i-1]+Q[i].v;
    ans=n+1;
    for (i=0;i<=k;i++) {
        int l=1,r=ans-1;
        while (l<=r) {
            int mid=(l+r)>>1;
            if (check(mid,i,k-i)) r=mid-1,ans=mid,ans1=i;
            else l=mid+1;
        }
    }
    if (ans>n) return printf("-1\n"),0;
    printf("%d\n",ans);
    int gt=0,gtw=0;
    for (i=1;i<=n;i++) if (x[i]==a[ans]) {
        gt=i; break;
    }
    for (i=1;i<=n;i++) if (X[i]==b[ans]) {
        gtw=i; break;
    }
    if (gt<gtw) {
        for (i=1;i<=ans1;i++) printf("%d %d\n",q[i].id,gt);
        for (i=1;i<=k-ans1;i++) printf("%d %d\n",Q[i].id,gtw);
    }
    else {
        
        for (i=1;i<=k-ans1;i++) printf("%d %d\n",Q[i].id,gtw);
        for (i=1;i<=ans1;i++) printf("%d %d\n",q[i].id,gt);
    }
}