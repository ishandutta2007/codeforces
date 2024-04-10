#include<bits/stdc++.h>
#define maxn 1000020

using namespace std;
typedef long long ll;

ll a[maxn],x[maxn],y[maxn],n,t,ans,l,r,p;
bool v[maxn];

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) x[i]=i,y[i]=i;
    for (int i=1;i<=n;i++)
    {
        while (x[i]>1&&a[x[i]-1]<a[i]&&(a[x[i]-1]&a[i])==a[x[i]-1]) x[i]--;
        while (y[i]<n&&a[y[i]+1]<a[i]&&(a[y[i]+1]&a[i])==a[y[i]+1]) y[i]++;
        if (x[i]>1&&a[x[i]-1]==a[i]) x[i]--;
        if (y[i]<n&&a[y[i]+1]==a[i]) y[i]++;
    }
    memset(v,true,sizeof(v));
    ans=n*(n-1)/2;
    for (int i=1;i<=n;i++)
    if (v[i]){
        p=0;
        v[i]=true;l=x[i];p+=(i-x[i]-1)*(i-x[i])/2;r=i;
        while (y[r]!=r&&a[y[r]]==a[i]) p+=(y[r]-r-2)*(y[r]-r-1)/2,r=y[r],v[r]=false;
        p+=(y[r]-r-1)*(y[r]-r)/2;r=y[r];
        p-=(r-l)*(r-l+1)/2;
        ans+=p;
    }
    printf("%I64d\n",ans);
    return 0;
}