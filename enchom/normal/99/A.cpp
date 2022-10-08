#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long Int;

Int integer[2048],floater[2048];
Int iL=0,fL=0;

int main()
{
    Int i;
    char ch;
    bool decimalpoint=false;
    
    while(1)
    {
        scanf("%c",&ch);
        
        if (ch==10)
        break;
        
        if (ch=='.')
        decimalpoint=true;
        else if (!decimalpoint)
        {
            iL++;
            integer[iL]=ch-'0';
        }
        else
        {
            fL++;
            floater[fL]=ch-'0';
        }
    }
    if (integer[iL]==9)
    {
        printf("GOTO Vasilisa.\n");
    }
    else
    {
        if (floater[1]<5)
        {
            for (i=1;i<=iL;i++)
            {
                printf("%I64d",integer[i]);
            }
            printf("\n");
        }
        else
        {
            integer[iL]++;
            for (i=1;i<=iL;i++)
            {
                printf("%I64d",integer[i]);
            }
            printf("\n");
        }
    }
    return 0;
}