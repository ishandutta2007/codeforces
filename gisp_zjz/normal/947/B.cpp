#include<bits/stdc++.h>
#define maxn 240030
#define mod 1000000007

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
ll a[maxn],sum[maxn],l,r,mid,ans[maxn],b[maxn],c[maxn],n,k;

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) scanf("%d",&b[i]);
    for (int i=1;i<=n;i++) sum[i]=sum[i-1]+b[i];
    for (int i=1;i<=n;i++)
    {
        l=i-1; r=n+1;
        while (r-l>1)
        {
            mid=(l+r)>>1;
            if (sum[mid]-sum[i-1]<=a[i]) l=mid; else r=mid;
        }
        c[i]++; c[r]--;
        ans[r]+=a[i]-(sum[l]-sum[i-1]);
    }
    for (int i=1;i<=n;i++)
    {
        k+=c[i];
        printf("%lld ",ans[i]+b[i]*k);
    }
    printf("\n");
    return 0;
}