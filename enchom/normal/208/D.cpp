#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long Int;

Int bars[51];

int main()
{
    Int n;
    Int i;
    Int a,b,c,d,e;
    Int points=0;
    Int first=0,second=0,third=0,fourth=0,fifth=0;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&bars[i]);
    }
    
    scanf("%I64d %I64d %I64d %I64d %I64d",&a,&b,&c,&d,&e);
    
    for (i=1;i<=n;i++)
    {
        points=points+bars[i];
        
        fifth=fifth+points/e;
        points=points%e;
        
        fourth=fourth+points/d;
        points=points%d;
        
        third=third+points/c;
        points=points%c;
        
        second=second+points/b;
        points=points%b;
        
        first=first+points/a;
        points=points%a;
    }
    printf("%I64d %I64d %I64d %I64d %I64d\n",first,second,third,fourth,fifth);
    printf("%I64d\n",points);
    return 0;
}