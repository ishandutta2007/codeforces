#include <iostream>
#include <stdio.h>
using namespace std;

int b[7];
int c = 0;

void add(int v)
{
    c *= 2;
    c += v;
}

int main()
{
    int a;
    int i;

    scanf("%d",&a);

    for (i=1;i<=6;i++)
    {
        b[i] = (a>>(6-i))%2;
    }

    add(b[1]);
    add(b[6]);
    add(b[4]);
    add(b[3]);
    add(b[5]);
    add(b[2]);

    printf("%d\n",c);

    return 0;
}