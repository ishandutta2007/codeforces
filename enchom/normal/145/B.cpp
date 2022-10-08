#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long Int;

int main()
{
    Int a1,a2,a3,a4;
    Int i,j;
    Int left7;
    
    scanf("%I64d %I64d %I64d %I64d",&a1,&a2,&a3,&a4);
    
    if (a3>a4)
    {
        if (a3-a4>1)
        {
            printf("-1\n");
            return 0;
        }
    }
    if (a4>a3)
    {
        if (a4-a3>1)
        {
            printf("-1\n");
            return 0;
        }
    }
    
    if (a4==a3)
    {
        if ( a1>a3 && a2>=a3 )
        {
            for (i=a1;i>=a3+1;i--)
            {
                printf("4");
            }
            printf("7");
            left7=a2-1;
            for (i=1;i<=a3-1;i++)
            {
                printf("47");
                left7--;
            }
            for (i=1;i<=left7;i++)
            printf("7");
            
            printf("4\n");
            return 0;
        }
        else if (a2>a3 && a1>=a3)
        {
            printf("7");
            for (i=a1;i>=a3;i--)
            {
                printf("4");
            }
            
            left7=a2-1;
            for (i=1;i<=a3-1;i++)
            {
                printf("74");
                left7--;
            }
            for (i=1;i<=left7;i++)
            {
                printf("7");
            }
            printf("\n");
            return 0;
        }
        else
        {
            printf("-1\n");
            return 0;
        }
    }
    else 
    {
        if (a3>a4)
        {
            if (a1>=a3 && a2>=a3)
            {
                for (i=a1;i>=a3;i--)
                {
                    printf("4");
                }
                printf("7");
                left7=a2-1;
                for (i=1;i<=a3-1;i++)
                {
                    printf("47");
                    left7--;
                }
                for (i=1;i<=left7;i++)
                {
                    printf("7");
                }
                printf("\n");
                return 0;
            }
            else
            {
                printf("-1\n");
                return 0;
            }
        }
        else if (a4>a3)
        {
            if (a1>=a4 && a2>=a4)
            {
                printf("7");
                for (i=a1;i>=a4;i--)
                {
                    printf("4");
                }
                left7=a2-1;
                
                for (i=1;i<=a4-2;i++)
                {
                    printf("74");
                    left7--;
                }
                for (i=1;i<=left7;i++)
                printf("7");
                
                printf("4\n");
                return 0;
            }
            else
            {
                printf("-1\n");
                return 0;
            }
        }
    }
    return 0;
}