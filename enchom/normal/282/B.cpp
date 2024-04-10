#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int price1[1000001],price2[1000001];

Int ABS(Int a)
{
    if (a<0)
    return a*-1;
    else
    return a;
}

int main()
{
    Int n;
    Int kid1=0,kid2=0;
    Int p1,p2;
    Int i;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d %I64d",&p1,&p2);
        
        if ( ABS(kid1+p1-kid2)>500 )
        {
            kid2+=p2;
            printf("G");
        }
        else
        {
            kid1+=p1;
            printf("A");
        }
    }
    printf("\n");
    return 0;
}