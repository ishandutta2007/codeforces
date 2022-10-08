#include <iostream>
#include <stdio.h>
using namespace std;

int n,m,a,b;

int main()
{
    int i;
    int cost=0;

    scanf("%d %d %d %d",&n,&m,&a,&b);

    if (a*m<=b)
    {
        printf("%d\n",n*a);
    }
    else
    {
        while(n>=m)
        {
            n-=m;
            cost+=b;
        }

        if (n*a<=b)
        cost+=n*a;
        else
        cost+=b;

        printf("%d\n",cost);
    }

    return 0;
}