#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

struct line
{
    Int a,b;
};

Int n;
Int x[1001];
line lines[1001];

bool Intersect(Int i1,Int i2)
{
    if (lines[i1].b<=lines[i2].a || lines[i1].a>=lines[i2].b)
    {
        return false;
    }
    else if (lines[i1].a>=lines[i2].a && lines[i1].b<=lines[i2].b)
    {
        return false;
    }
    else if (lines[i2].b<=lines[i1].a || lines[i2].a>=lines[i1].b)
    {
        return false;
    }
    else if (lines[i2].a>=lines[i1].a && lines[i2].b<=lines[i1].b)
    {
        return false;
    }
    else
    return true;
}

int main()
{
    Int i,j;
    Int r;

    scanf("%I64d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&x[i]);
    }

    for (i=1;i<=n-1;i++)
    {
        lines[i].a=x[i];
        lines[i].b=x[i+1];

        if (lines[i].a>lines[i].b)
        {
            r=lines[i].a;
            lines[i].a=lines[i].b;
            lines[i].b=r;
        }
    }

    for (i=1;i<=n-1;i++)
    {
        for (j=i+1;j<=n-1;j++)
        {
            if (Intersect(i,j))
            {
                printf("yes\n");
                return 0;
            }
        }
    }

    printf("no\n");

    return 0;
}