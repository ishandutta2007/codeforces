#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int a,b;
    int hours=0;
    int dead=0;

    scanf("%d %d",&a,&b);

    while(a>0)
    {
        hours++;
        a--;
        dead++;

        if (dead==b)
        {
            dead=0;
            a++;
        }
    }

    printf("%d\n",hours);

    return 0;
}