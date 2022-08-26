#include<bits/stdc++.h>
using namespace std;
#define N 100005
int tot,f[N],k,last[N],to[N],Next[N],q[N],dis[505][505],a[N];
int n,m;
char c[N];
inline void add(int x,int y) {
    Next[++tot]=last[x]; last[x]=tot; to[tot]=y;
}
inline void bfs(int x) {
    int l=0,r=1; q[1]=x;
    dis[x][x]=0;
    while (l<r) {
        int k=q[++l];
        for (int i=last[k];i;i=Next[i]) {
            if (dis[x][to[i]]||to[i]==x) continue;
            dis[x][to[i]]=dis[x][k]+1;
            q[++r]=to[i];
        }
    }
}
int main() {
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++) {
        scanf("%d",&k);
        int L=0;
        for (int j=1;j<=k;j++) {
            int x;
            scanf("%d",&x);
            if (L) add(x,L),add(L,x);
            L=x;
        }
    }
    for (int i=1;i<=n;i++) bfs(i);

    for (int _i=1;_i<=n;_i++) {
        for (int i=1;i<=n;i++) a[i]=1;
        while (1) {
            for (int x=1;x<=n;x++) {
                f[x]=0;
                for (int j=last[x];j;j=Next[j]) {
                    int y=to[j];
                    int s=0;
                    for (int i=1;i<=n;i++) {
                        if (!a[i]) continue;
                        if (dis[i][x]>dis[i][y]) s++;
                    }
                    f[x]=max(f[x],s);
                }
            }
            int gt=n+1,x=0,y;
            for (int i=1;i<=n;i++) if (f[i]<gt) gt=f[x=i];
            printf("%d\n",x);
            fflush(stdout);
            scanf("%s",c);
            if (c[0]=='G') {
                scanf("%d",&y);
                for (int i=1;i<=n;i++) {
                    if (dis[i][x]<=dis[i][y]) a[i]=0;
                }
            }
            else break;
        }
    }
}