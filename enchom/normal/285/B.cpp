#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int p[100001];
bool TFO[100001];

int main()
{
    Int n,s,t;
    Int i;
    Int curpos;
    Int moves=0;

    for (i=0;i<=100000;i++)
    {
        TFO[i]=false;
    }

    scanf("%I64d %I64d %I64d",&n,&s,&t);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&p[i]);
    }

    curpos=s;

    while(!TFO[curpos] && curpos!=t)
    {
        moves++;
        TFO[curpos]=true;
        curpos=p[curpos];
    }

    if (TFO[curpos])
    {
        printf("-1\n");
    }
    else
    {
        printf("%I64d\n",moves);
    }
    return 0;
}