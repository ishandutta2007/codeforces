#include<bits/stdc++.h>
#define maxn 234000
using namespace std;
typedef long long ll;
ll a[maxn],sum[maxn],n,m,s,l,r,mid,k;

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for (int i=1;i<=m;i++)
    {
        scanf("%lld",&k); s+=k;
        l=0; r=n+1;
        while (r-l>1){
            mid=(l+r)/2;
            if (sum[mid]<=s) l=mid; else r=mid;
        }
        if (l==n) {
            cout << n << endl;
            s=0;
        }
        else cout << n-l << endl;
    }
    return 0;
}