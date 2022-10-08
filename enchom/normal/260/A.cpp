#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

bool flag=false;
Int addeddigits[100001],a,b,n;

void Generator(Int curreminder,Int digitadd)
{
    Int i;
    
    if (flag)
    return;
    
    if (digitadd==n+1)
    {
        
        flag=true;
        return;
    }
    
    for (i=0;i<=9;i++)
    {
        if ( (curreminder*10+i)%b==0 )
        {
            addeddigits[digitadd]=i;
            Generator( 0,digitadd+1 );
            if (flag)
            return;
        }
    }
    
}

int main()
{
    Int i;
    
    scanf("%I64d %I64d %I64d",&a,&b,&n);
    
    Generator(a%b,1);
    
    if (!flag)
    {
        printf("-1\n");
        return 0;
    }
    
    printf("%I64d",a);
    for (i=1;i<=n;i++)
    {
        printf("%I64d",addeddigits[i]);
    }
    printf("\n");
    return 0;
}