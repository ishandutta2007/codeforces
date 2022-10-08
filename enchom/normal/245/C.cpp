#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int coins[101];
Int n;
Int counter=0;

void Do(Int x)
{
    if (coins[x]>0)
    coins[x]--;
    if (coins[2*x]>0)
    coins[2*x]--;
    if (coins[2*x+1]>0)
    coins[2*x+1]--;
    
    counter++;
    
    return;
}

int main()
{
    Int i;
    Int x;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&coins[i]);
    }
    for (i=n;i>=1;i--)
    {
        while (coins[i]>0)
        {
            x=i/2;
            if (x>=1 && x*2+1<=n)
            {
                Do(x);
            }
            else
            {
                x=i;
                if (x*2+1<=n)
                {
                    Do(x);
                }
                else
                {
                    printf("-1\n");
                    return 0;
                }
            }
        }
    }
    printf("%I64d\n",counter);
    return 0;
}