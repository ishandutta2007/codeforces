#include<bits/stdc++.h>
using namespace std;
#define N 100005
int q[N],a[N],b[N],n,m,G[N];
int main() {
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) scanf("%d",&b[i]);
    b[0]=0;
    int s=0,r=0;
    for (int i=1;i<=n;i++) if (b[G[a[i]]]<b[i]) G[a[i]]=i;
    for (int i=1;i<=n;i++) if (G[a[i]]!=i) q[++r]=b[i];

    for (int i=1;i<=m;i++) s+=(!G[i]);
    sort(q+1,q+1+r);
    long long ans=0;
    for (int i=1;i<=s;i++) ans+=q[i];
    printf("%lld\n",ans);

}