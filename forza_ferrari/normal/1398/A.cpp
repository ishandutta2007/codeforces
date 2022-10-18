#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a[50001];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(register int i=1;i<=n;++i)
            scanf("%d",&a[i]);
        if(a[1]+a[2]<=a[n])
            printf("1 2 %d\n",n);
        else
            puts("-1");
    }
    return 0;
}