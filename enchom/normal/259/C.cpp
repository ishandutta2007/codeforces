#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long Int;

char str[100001];
Int L=0;

int main()
{
    char ch;
    Int i;
    Int killed=0;
    
    while(1)
    {
        scanf("%c",&ch);
        
        if (ch==10)
        break;
        
        L++;
        str[L]=ch;
    }
    for (i=1;i<=L;i++)
    {
        if (str[i]=='0')
        {
            killed=i;
            break;
        }
    }
    if (killed==0)
    killed=L;
    
    for (i=1;i<=L;i++)
    {
        if (i!=killed)
        printf("%c",str[i]);
    }
    printf("\n");
    return 0;
}