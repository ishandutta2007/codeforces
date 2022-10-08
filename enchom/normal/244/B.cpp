#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int n;
Int ctr=0;
Int i,j;

void Generator(Int num,bool usi,bool usj)
{
    if (num<=n)
    {
        if (usi && usj)
        ctr++;
        
        Generator(num*10+i,true,usj);
        Generator(num*10+j,usi,true);
    }
}

int main()
{
    Int k;
    
    scanf("%I64d",&n);
    
    for (i=0;i<=9;i++)
    {
        for (j=i;j<=9;j++)
        {
            if (i==j)
            {
                if (i==0)
                continue;
                
                k=i;
                while(k<=n)
                {
                    ctr++;
                    k=k*10+i;
                }
                continue;
            }
            
            if (i!=0)
            Generator(i,true,false);
            if (j!=0)
            Generator(j,false,true);
        }
    }
    printf("%I64d\n",ctr);
    return 0;
}