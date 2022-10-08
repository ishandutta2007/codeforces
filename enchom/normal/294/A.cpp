#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int wires[201];
Int n;

int main()
{
    Int i;
    Int m,x,y;

    scanf("%I64d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&wires[i]);
    }

    scanf("%I64d",&m);

    for (i=1;i<=m;i++)
    {
        scanf("%I64d %I64d",&x,&y);

        wires[x-1]=wires[x-1] + (y-1);
        wires[x+1]=wires[x+1] + (wires[x]-y);
        wires[x]=0; ///poor birds ;(
    }

    for (i=1;i<=n;i++)
    {
        printf("%I64d\n",wires[i]);
    }

    return 0;
}