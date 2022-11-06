#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100010
#define ll long long
using namespace std;
int q[N],tn,a[N];
ll d[N],ans;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++) scanf("%d",&a[i]);
    d[n-1]=ans=1;tn=n+1;
    q[--tn]=n-1;
    for(int i=n-2;i;i--)
    {
        int p=*(upper_bound(q+tn,q+n+1,a[i])-1);
        d[i]=d[p]+p-i+(n-a[i]);
        ans+=d[i];
        for(;tn<=n && a[i]>=a[q[tn]];tn++);
        q[--tn]=i;
    }
    printf("%lld\n",ans);
    return 0;
}