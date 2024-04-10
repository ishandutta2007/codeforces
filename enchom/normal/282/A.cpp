#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

char inp[11];

int main()
{
    Int n;
    Int i;
    Int x=0;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        scanf("%s",inp);
        
        if (inp[0]=='-' && inp[1]=='-')
        {
            x--;
        }
        else if (inp[1]=='-' && inp[2]=='-')
        {
            x--;
        }
        else if (inp[0]=='+' && inp[1]=='+')
        {
            x++;
        }
        else
        {
            x++;
        }
    }
    
    printf("%I64d\n",x);
    
    return 0;
}