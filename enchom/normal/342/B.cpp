#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

struct watch
{
    Int t;
    Int l,r;
};

watch watchings[100001];
Int n,m;

int main()
{
    Int i;
    Int uk=1;
    Int curtime=1;
    Int s,t;
    Int add;
    Int nextspy;
    char toprint;

    scanf("%I64d %I64d %I64d %I64d",&n,&m,&s,&t);

    if (s<t)
    {
        toprint='R';
        add=1;
    }
    else
    {
        toprint='L';
        add=-1;
    }

    for (i=1;i<=m;i++)
    {
        scanf("%I64d %I64d %I64d",&watchings[i].t,&watchings[i].l,&watchings[i].r);
    }

    while(s!=t)
    {
        nextspy=s+add;

        if (watchings[uk].t==curtime)
        {
            if (nextspy>=watchings[uk].l && nextspy<=watchings[uk].r)
            {
                printf("X");
            }
            else if (s>=watchings[uk].l && s<=watchings[uk].r)
            {
                printf("X");
            }
            else
            {
                printf("%c",toprint);
                s=nextspy;
            }

            uk++;
        }
        else
        {
            printf("%c",toprint);
            s=nextspy;
        }

        curtime++;
    }

    printf("\n");

    return 0;
}