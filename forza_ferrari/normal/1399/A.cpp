#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,a[51];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(register int i=1;i<=n;++i)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        bool flag=1;
        for(register int i=2;i<=n;++i)
            if(a[i]-a[i-1]>1)
            {
                puts("NO");
                flag=0;
                break;
            }
        if(flag)
            puts("YES");
    }
    return 0;
}