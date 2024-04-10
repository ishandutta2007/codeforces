#include<bits/stdc++.h>
#define maxn 230402

using namespace std;
typedef long long ll;

ll n,a[maxn],t,ans;

int main()
{
    scanf("%I64d%I64d",&n,&t);
    for (int i=0;i<n;i++) scanf("%I64d",&a[i]);
    for (int i=1;i<n;i++) a[i]=min(a[i],a[i-1]*2);
    for (int i=n;i<31;i++) a[i]=a[i-1]*2;
    ans=0;
    for (int i=0;i<31;i++)
    {
        ans=min(ans,a[i]);
        if (t&(1<<i)) ans+=a[i];
    }
    for (int i=0;i<n;i++) if ((1<<i)>=t) ans=min(ans,a[i]);
    printf("%I64d\n",ans);
    return 0;
}