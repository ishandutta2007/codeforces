#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t,n,k;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n==1)
        {
            puts("9");
            continue;
        }
        if(n==2)
        {
            puts("98");
            continue;
        }
        printf("989");
        k=0;
        for(register int i=4;i<=n;++i)
        {
            printf("%d",k);
            ++k;
            if(k>9)
                k=0;
        }
        puts("");
    }
    return 0;
}