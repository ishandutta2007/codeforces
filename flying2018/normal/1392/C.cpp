#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200010
#define ll long long
using namespace std;
int a[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        int n;
        scanf("%d",&n);
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(i>1 && a[i]<a[i-1]) ans+=a[i-1]-a[i];
        }
        printf("%lld\n",ans);
    }
    
    return 0;
}