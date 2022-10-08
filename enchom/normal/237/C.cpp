#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

bool Prime[2000001];
Int IntervalPrimes[2000001];
Int ipL=0;

int main()
{
    Int uk1,uk2;
    Int a,b,k;
    Int i,j;
    Int primenums;
    Int biggestdif;
    Int bad;
    
    scanf("%I64d %I64d %I64d",&a,&b,&k);
    
    for (i=1;i<=1000000;i++)
    {
        Prime[i]=true;
    }
    Prime[1]=false;
    
    for (i=2;i<=1000000;i++)
    {
        if (Prime[i])
        {
            for (j=i+i;j<=1000000;j=j+i)
            {
                Prime[j]=false;
            }
        }
    }
    
    for (i=a;i<=b;i++)
    {
        if (Prime[i])
        {
            ipL++;
            IntervalPrimes[ipL]=i;
        }
    }
    
    if (k>ipL)
    {
        printf("-1\n");
        return 0;
    }
    
    bad=b-IntervalPrimes[ipL-k+1]+1;
    ///cout<<bad<<endl;
    
    uk1=a;
    uk2=a;
    if (Prime[a])
    primenums=1;
    else
    primenums=0;
    
    biggestdif=1;
    
    while(1)
    {
        if (primenums<k)
        {
            if (uk2==b)
            {
                break;
            }
            uk2++;
            if (Prime[uk2])
            primenums++;
            
            if (uk2-uk1+1>biggestdif)
            biggestdif=uk2-uk1+1;
        }
        else
        {
            if (uk1==uk2)
            {
                uk1++;
                uk2++;
                
                if (uk1>b)
                break;
                
                if (Prime[uk1])
                primenums=1;
                else
                primenums=0;
            }
            else
            {
                if (Prime[uk1])
                primenums--;
                uk1++;
            }
        }
    }
    if (biggestdif<bad)
    biggestdif=bad;
    printf("%I64d\n",biggestdif);
    return 0;
}