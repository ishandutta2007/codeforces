#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
typedef long long Int;

char password[81];
char encryption[10][11];

bool Equal(Int startchar,Int digit)
{
    Int i;
    
    for (i=startchar;i<=startchar+9;i++)
    {
        if (password[i]!=encryption[digit][i-startchar+1])
        return false;
    }
    return true;
}

int main()
{
    Int i,j;
    Int thenum;
    Int num=0;
    
    for (i=1;i<=80;i++)
    {
        cin>>password[i];
    }
    for (i=0;i<=9;i++)
    {
        for (j=1;j<=10;j++)
        {
            cin>>encryption[i][j];
        }
    }
    
    for (i=1;i<=71;i+=10)
    {
        for (j=0;j<=9;j++)
        {
            if ( Equal(i,j) )
            {
                thenum=j;
                break;
            }
        }
        printf("%I64d",thenum);
    }
    printf("\n");
    return 0;
}