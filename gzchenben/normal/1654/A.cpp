#include<cstdio>
#include<algorithm>
using namespace std;
int n,t,a[1005];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        printf("%d\n",a[n-1]+a[n]);
    }
}