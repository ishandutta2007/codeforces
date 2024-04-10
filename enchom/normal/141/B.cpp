#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

int main()
{
    Int a,x,y;
    Int hei=0;
    bool twice=false;
    Int sq1,sq2;
    bool one;
    Int line;
    
    scanf("%I64d %I64d %I64d",&a,&x,&y);
    
    hei=a;
    sq1=1;
    sq2=1;
    one=true;
    while(hei<y)
    {
        if (!twice)
        {
            sq1=sq2+1;
            hei=hei+a;
            twice=true;
            one=true;
        }
        else
        {
            sq1++;
            sq2=sq1+1;
            hei=hei+a;
            twice=false;
            one=false;
        }
    }
    if (y==0)
    {
        printf("-1\n");
        return 0;
    }
    if (one)
    {
        if (x==0)
        {
            if (y%a==0)
            {
                printf("-1\n");
                return 0;
            }
            else
            {
                printf("%I64d\n",sq1);
                return 0;
            }
        }
        if (y%a==0)
        {
            printf("-1\n");
            return 0;
        }
        if (a%2==0)
        {
            line=a/2;
            if (x>0)
            {
                if (x>=line)
                {
                    printf("-1\n");
                    return 0;
                }
                else
                {
                    printf("%I64d\n",sq1);
                    return 0;
                }
            }
            else
            {
                if (x<=line*-1)
                {
                    printf("-1\n");
                    return 0;
                }
                else
                {
                    printf("%I64d\n",sq1);
                    return 0;
                }
            }
        }
        else
        {
            line=a/2;
            if (x>0)
            {
                if (x>line)
                {
                    printf("-1\n");
                    return 0;
                }
                else
                {
                    printf("%I64d\n",sq1);
                    return 0;
                }
            }
            else
            {
                if (x<line*-1)
                {
                    printf("-1\n");
                    return 0;
                }
                else
                {
                    printf("%I64d\n",sq1);
                    return 0;
                }
            }
        }
    }
    else
    {
        if (y%a==0)
        {
            printf("-1\n");
            return 0;
        }
        if (x==0)
        {
            printf("-1\n");
            return 0;
        }
        if (x>0)
        {
            if (x>=a)
            {
                printf("-1\n");
                return 0;
            }
            else
            {
                printf("%I64d\n",sq2);
                return 0;
            }
        }
        else
        {
            if (x<=a*-1)
            {
                printf("-1\n");
                return 0;
            }
            else
            {
                printf("%I64d\n",sq1);
                return 0;
            }
        }
    }
    return 0;
}