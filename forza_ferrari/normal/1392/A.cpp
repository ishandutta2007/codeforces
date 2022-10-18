#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a[200001];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        bool flag=1;
        for(register int i=1;i<=n;++i)
        {
            scanf("%d",&a[i]);
            if(i>1&&a[i]!=a[i-1])
                flag=0;
        }
        printf("%d\n",flag? n:1);
    }
    return 0;
}