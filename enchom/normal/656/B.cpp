#include <iostream>
#include <stdio.h>
using namespace std;

int R[21];
int M[21];
int n;

int main()
{
    int i,j;
    int D;
    int iwash=0,hewash=0;
    bool nonzero=false;
    bool illwash;
    int v;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&M[i]);
    }

    for (i=1;i<=n;i++)
    {
        scanf("%d",&R[i]);
    }

    for (D=0;;D++)
    {
        nonzero=false;
        illwash=false;
        for (i=1;i<=n;i++)
        {
            v=D%M[i];

            if (v!=0)
            nonzero=true;
            if (v==R[i])
            illwash=true;
        }

        if (!nonzero && D!=0)
        break;

        if (illwash)
        iwash++;
        else
        hewash++;
    }

    printf("%.6f\n",(double)iwash/(double)(iwash+hewash));

    return 0;
}