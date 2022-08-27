#include<bits/stdc++.h>
#define maxn 2097153
#define eps 1e-6

using namespace std;

int main()
{
    int n,k,x,a[105];
    scanf("%d%d%d",&n,&k,&x);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    for (int i=n-1;i>=n-k;i--) a[i]=min(a[i],x);
    int sum=0;
    for (int i=0;i<n;i++) sum+=a[i];
    printf("%d\n",sum);
    return 0;
}