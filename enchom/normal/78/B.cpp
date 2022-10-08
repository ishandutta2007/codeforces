#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int colors[101];
Int n;

char Color(Int k)
{
    switch (k)
    {
        case 1:
        return 'R';
        break;
        
        case 2:
        return 'O';
        break;
        
        case 3:
        return 'Y';
        break;
        
        case 4:
        return 'G';
        break;
        
        case 5:
        return 'B';
        break;
        
        case 6:
        return 'I';
        break;
        
        case 7:
        return 'V';
        break;
    }
}

Int Fix(Int k)
{
    if (k>n)
    return k-n;
    if (k<1)
    return k+n;
    return k;
}

int main()
{
    Int i,j;
    scanf("%I64d",&n);
    
    for (i=0;i<=100;i++)
    colors[i]=-1;
    
    for (i=1;i<=7;i++)
    colors[i]=i;
    
    for (j=8;j<=n;j++)
    for (i=1;i<=7;i++)
    {
        if (colors[Fix(j-1)]!=i && colors[Fix(j-2)]!=i)
        {
            if (colors[Fix(j+1)]!=i && colors[Fix(j-3)]!=i)
            {
                if (colors[Fix(j+2)]!=i && colors[Fix(j+3)]!=i)
                {
                    colors[j]=i;
                }
            }
        }
    }
    for (i=1;i<=n;i++)
    {
        printf("%c",Color(colors[i]));
    }
    printf("\n");
    return 0;
}