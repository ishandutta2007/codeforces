#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int a;
    int i;
    int cp;

    scanf("%d", &a);
    cp = a;

    for (i=2;i<=a;i++)
    {
        if (a % i == 0)
        {
            printf("%d%d\n",i,a/i);
            return 0;
        }
    }

    return 0;
}