#include<iostream>
#include<cstdio>
using namespace std;
int t,n;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int p=(n+3)>>2;
        for(register int i=1;i<=n-p;++i)
            putchar('9');
        for(register int i=1;i<=p;++i)
            putchar('8');
        puts("");
    }
    return 0;
}