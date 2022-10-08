#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

typedef long long Int;

int main()
{
    Int n;
    Int i;
    Int inp;
    Int themin,themax;
    Int amazing=0;
    bool amaz;
    
    scanf("%I64d",&n);
    
    scanf("%I64d",&inp);
    themin=inp;
    themax=inp;
    
    for (i=2;i<=n;i++)
    {
        scanf("%I64d",&inp);
        
        amaz=false;
        if (inp>themax)
        {
            themax=inp;
            amaz=true;
        }
        if (inp<themin)
        {
            themin=inp;
            amaz=true;
        }
        
        if (amaz)
        amazing++;
    }
    printf("%I64d\n",amazing);
    return 0;
}