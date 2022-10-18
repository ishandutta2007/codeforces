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
        if(n==36)
        {
            puts("YES");
            puts("5 6 10 15");
            continue;
        }
        if(n==40)
        {
            puts("YES");
            puts("6 9 10 15");
            continue;
        }
        if(n==44)
        {
            puts("YES");
            puts("6 10 13 15");
            continue;
        }
        puts(n>=31? "YES":"NO");
        if(n>=31)
            printf("6 10 14 %d\n",n-30);
    }
    return 0;
}