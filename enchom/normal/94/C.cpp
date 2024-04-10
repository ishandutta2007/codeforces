#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

int main()
{
    Int a,b,n,m;
    Int moves=3;
    
    scanf("%I64d %I64d %I64d %I64d",&n,&m,&a,&b);
    
    if (m==1)
    {
        printf("1\n");
        return 0;
    }
    if ( ((a-1)%m)+1==((b-1)%m)+2 )
    {
        printf("2\n");
        return 0;
    }
    
    if ( (a-1)/m==(b-1)/m )
    {
        printf("1\n");
        return 0;
    }
    else
    {
        if ( ((a-1)/m)+1==(b-1)/m )
        {
            if (a%m==1 && (b%m==0||b==n) )
            {
                printf("1\n");
            }
            else
            {
                printf("2\n");
            }
            return 0;
        }
        if (a%m==1)
        moves--;
        if (b%m==0 || b==n)
        moves--;
        
        printf("%I64d\n",moves);
    }
    return 0;
}