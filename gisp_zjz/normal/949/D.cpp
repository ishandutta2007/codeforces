#include<bits/stdc++.h>
#define maxn 203000

using namespace std;
int n,d,k,a[maxn],b[maxn],l,r,mid,x[maxn],y[maxn],o,p;

bool c(int u,int v)
{
    int j=1;
    for (int i=1;i<=n;i++) b[i]=a[i];
    for (int i=u;i<=v;i++)
    {
        o=k;
        while (j<=n&&o) {
            if (i>=x[j]&&i<=y[j]) p=min(b[j],o),o-=p,b[j]-=p; else p=0;
            if (!b[j]||!p) j++;
        }
        if (o) return false;
    }
    return true;
}

int main()
{
    scanf("%d%d%d",&n,&d,&k);d++;
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) x[i]=(i-1)/d+1,y[i]=n-(n-i)/d;
    l=0; r=(n+1)/2;
    while (r-l>1){
        mid=(l+r)/2;
        if (c(mid,n+1-mid)) r=mid; else l=mid;
    }
    cout << r-1 << endl;
}