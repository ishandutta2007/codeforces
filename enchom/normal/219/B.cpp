#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
typedef long long Int;

int main()
{
    Int p,d;
    Int i;
    Int nines=0;
    Int mustsub;
    
    scanf("%I64d %I64d",&p,&d);
    
    i=1;
    while(i<=1000000000000000000)
    {
        if (p%10==9)
        {
            mustsub=0;
        }
        else
        {
            mustsub=(10+(p%10))-9;
        }
        if (mustsub*i<=d)
        {
            d=d-(mustsub*i);
            nines++;
            p=p-mustsub;
            p=p/10;
        }
        else
        {
            break;
        }
        i*=10;
    }
    if (p!=0)
    printf("%I64d",p);
    for (i=1;i<=nines;i++)
    {
        printf("9");
    }
    printf("\n");
    return 0;
}