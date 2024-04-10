#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
typedef long long Int;


Int squares[1000001];
bool TFO[1000001];
Int sL=0;
Int primes[1000001];
Int pL=0;

bool Prime(Int k)
{
    Int z=sqrt(k);
    Int i;
    
    for (i=2;i<=z;i++)
    {
        if (k%i==0)
        return false;
    }
    return true;
}

int main()
{
    Int i,j;
    Int n;
    Int a,l,r,mid;
    bool exist=false;
    
    for (i=0;i<=1000000;i++)
    {
        primes[i]=false;
        TFO[i]=false;
    }
    for (i=2;i<=1000000;i++)
    {
        if (!TFO[i])
        {
            for (j=i+i;j<=1000000;j+=i)
            {
                TFO[j]=true;
            }
        }
    }
    for (i=2;i<=1000000;i++)
    {
        if ( !TFO[i] )
        {
            sL++;
            squares[sL]=i*i;
        }
    }
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&a);
        l=1;
        r=sL;
        
        if (a==1)
        {
            printf("NO\n");
            continue;
        }
        
        exist=false;
        
        while(l<=r)
        {
            mid=(l+r)/2;
            
            if (squares[mid]==a)
            {
                exist=true;
                break;
            }
            else if (squares[mid]>a)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        if (exist)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}