#include<bits/stdc++.h>

using namespace std;
int c[1<<22],pre[1<<22],a[1<<22],n,m,ans[25],d[25],r,t;

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++)
    {
        int u,v; scanf("%d%d",&u,&v);
        u--; v--;
        d[u]|=(1<<v); d[v]|=(1<<u);
    }
    if (m==n*(n-1)/2){cout << 0 <<endl; return 0;}
    memset(a,-1,sizeof(a));
    memset(pre,-1,sizeof(pre));
    for (int i=0;i<n;i++) a[1<<i]=0;
    for (int i=0;i<(1<<n);i++)
    {
        if (a[i]==-1) continue;
        for (int j=0;j<n;j++)
            if (i&(1<<j)){
                r=i|d[j];
                if (a[r]==-1||a[r]>a[i]+1) a[r]=a[i]+1,pre[r]=j,c[r]=i;
            }
    }
    t=(1<<n)-1; r=0;
    while (pre[t]!=-1) ans[++r]=pre[t],t=c[t];
    cout << r << endl;
    for (int i=r;i;i--) printf("%d ",ans[i]+1); printf("\n");
    return 0;
}