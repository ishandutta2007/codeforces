#include<bits/stdc++.h>
#define maxn 503000

using namespace std;
const int inf=10000000;
int n,a[maxn],c[maxn],x[maxn],y[maxn],d[maxn],l,r,mid,ans,m;

int main()
{

    scanf("%d%d",&m,&n);
    for (int i=0;i<m;i++)
    {
        int u,v;scanf("%d%d",&u,&v);
        c[u]++; c[v+1]--;
    }
    for (int i=1;i<=n;i++) a[i]=a[i-1]+c[i];

    //scanf("%d",&n); for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    d[0]=0; for (int i=1;i<=n;i++) d[i]=inf;
    for (int i=1;i<=n;i++)
    {
        l=0; r=n;
        while (r-l>1)
        {
            mid=(l+r)>>1;
            if (a[i]<d[mid]) r=mid; else l=mid;
        }
        x[i]=l; d[l+1]=min(d[l+1],a[i]);
    }
    d[0]=0; for (int i=1;i<=n;i++) d[i]=inf;
    for (int i=n;i;i--)
    {
        l=0; r=n;
        while (r-l>1)
        {
            mid=(l+r)>>1;
            if (a[i]<d[mid]) r=mid; else l=mid;
        }
        y[i]=l; d[l+1]=min(d[l+1],a[i]);
    }
    for (int i=1;i<=n;i++) ans=max(ans,x[i]+y[i]);
    //for (int i=1;i<=n;i++) printf("%d ",x[i]); printf("\n");
    //for (int i=1;i<=n;i++) printf("%d ",y[i]); printf("\n");
    cout << ans+1 << endl;
}