#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

Int puzzles[51];
Int n,m;

int main()
{
    Int i;
    Int mindif=999999999;

    scanf("%I64d %I64d",&n,&m);

    for (i=1;i<=m;i++)
    {
        scanf("%I64d",&puzzles[i]);
    }

    sort(puzzles+1,puzzles+1+m);

    for (i=n;i<=m;i++)
    {
        if (puzzles[i]-puzzles[i-n+1]<mindif)
        {
            mindif=puzzles[i]-puzzles[i-n+1];
        }
    }

    printf("%I64d\n",mindif);

    return 0;
}