#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int F[1000001];

int main()
{
    Int i;
    Int n;
    Int cp;
    Int dig;
    bool first;

    F[0]=0;

    scanf("%I64d",&n);

    for (i=1;i<=n;i++)
    {
        cp=i;

        first=true;
        while(cp>0)
        {
            dig=cp%10;
            cp/=10;

            if (dig==0)
            continue;

            if (F[i]>F[i-dig]+1 || first)
            {
                first=false;
                F[i]=F[i-dig]+1;
            }
        }
    }

    printf("%I64d\n",F[n]);

    return 0;
}