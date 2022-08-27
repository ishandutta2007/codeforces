#include<bits/stdc++.h>
#define maxn 200005

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;

double ans;
int a[maxn],n,k,l,r;

int main()
{
    scanf("%d%d",&n,&k); ans=-1.0;
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    r=0;
    for (int i=0;i<n;i++)
    {
        while (r+1<n&&a[r+1]-a[i]<=k) r++;
        if (r-i>1) ans=max(ans,1.0*(a[r]-a[i+1])/(a[r]-a[i]));
    }
    if (ans>0) printf("%.10f\n",ans); else printf("-1\n");
    return 0;
}