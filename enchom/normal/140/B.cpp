#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int n;
Int fpref[301][301];
Int pref[301];

Int ans[301];

int main()
{
    Int i,j;
    Int k;
    Int newcardpref,bestprefsofar,thecard;
    Int curpref;

    scanf("%I64d",&n);

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            scanf("%I64d",&k);
            fpref[i][k]=j;
        }
    }
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&k);
        pref[k]=i;
    }

    for (i=1;i<=n;i++)
    {
        bestprefsofar=999999;
        curpref=999999;
        thecard=-1;
        for (j=1;j<=n;j++)
        {
            newcardpref=pref[j];
            if (i==j)
            continue;

            if (newcardpref<curpref)
            {
                curpref=newcardpref;
                if (fpref[i][j]<bestprefsofar)
                {
                    bestprefsofar=fpref[i][j];
                    thecard=j;
                }
            }
        }
        ans[i]=thecard;
    }

    for (i=1;i<=n;i++)
    {
        printf("%I64d",ans[i]);

        if (i!=n)
        printf(" ");
    }
    printf("\n");

    return 0;
}