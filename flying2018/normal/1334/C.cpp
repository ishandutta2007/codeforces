#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define N 300010
using namespace std;
ll a[N],b[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        int n;
        ll s=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%lld%lld",&a[i],&b[i]),s+=a[i];
        for(int i=1;i<=n;i++)
        if(b[i]>a[i%n+1]) b[i]=a[i%n+1];
        ll mn=1e18;
        for(int i=1;i<=n;i++) mn=min(mn,b[i]),s-=b[i];
        printf("%lld\n",s+mn);
    }
    return 0;
}