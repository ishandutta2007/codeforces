#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

Int nums[20001];

int main()
{
    Int n;
    Int i,j;
    Int maxattr=0;
    Int vertex;
    Int attr;
    Int k;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&nums[i]);
        maxattr=maxattr+nums[i];
    }
    for (i=2;i<=n;i++)
    {
        if (n%i!=0)
        continue;
        
        for (k=1;k<=i;k++)
        {
            vertex=0;
            attr=0;
            for (j=k;j<=n;j=j+i)
            {
                vertex++;
                attr=attr+nums[j];
            }
            if (attr>maxattr && vertex>=3)
            maxattr=attr;
        }
    }
    cout<<maxattr<<endl;
    return 0;
}