#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a[1001];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(register int i=1;i<=n;++i)
            scanf("%d",&a[i]);
        for(register int i=1;;++i)
        {
            bool flag=1;
            for(register int j=1;j<n;++j)
                flag&=a[j]<a[j+1];
            if(flag)
            {
                printf("%d\n",i-1);
                break;
            }
            for(register int j=(((i&1)+1)&1)+1;j+1<=n;j+=2)
                if(a[j]>a[j+1])
                    a[j]^=a[j+1]^=a[j]^=a[j+1];
        }
    }
    return 0;
}