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
        if(n==1)
        {
            puts("a");
            continue;
        }
        if(n&1)
        {
            for(register int i=1;i<(n>>1);++i)
                putchar('a');
            putchar('b');
            putchar('c');
            for(register int i=1;i<=(n>>1);++i)
                putchar('a');
            puts("");
        }
        else
        {
            for(register int i=1;i<=(n>>1);++i)
                putchar('a');
            putchar('b');
            for(register int i=1;i<(n>>1);++i)
                putchar('a');
            puts("");
        }
    }
    return 0;
}