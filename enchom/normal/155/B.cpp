#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long Int;

Int arr[1001];
Int aL=0;

int main()
{
    Int n;
    Int i;
    Int a,b;
    Int cardstouse=1;
    Int points=0;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d %I64d",&a,&b);
        if (b==0)
        {
            aL++;
            arr[aL]=a;
        }
        else
        {
            cardstouse=cardstouse+(b-1);
            points=points+a;
        }
    }
    sort(arr+1,arr+1+aL);
    for (i=aL;i>=aL-cardstouse+1 && i>=1;i--)
    {
        points=points+arr[i];
    }
    printf("%I64d\n",points);
    return 0;
}