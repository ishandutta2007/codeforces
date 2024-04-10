#include<bits/stdc++.h>
#define maxn 502000

using namespace std;
typedef long long ll;

ll n,ans,a[maxn],k,r;

int main()
{
    scanf("%I64d%I64d",&n,&k);
    for (int i=1;i<=k;i++) scanf("%I64d",&a[i]);
    ans=-1; r=0;
    for (int i=1;i<=k;i++) if (n/a[i]*a[i]>ans) ans=n/a[i]*a[i],r=i;
    printf("%I64d %I64d\n",r,n/a[r]);
    return 0;
}