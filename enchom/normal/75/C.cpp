#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

Int DivisorsA[100001];
Int DivisorsB[100001];
Int Divisors[100001];
Int dL=0,daL=0,dbL=0;
Int Perfect[100001];
Int pL=0;

void GetDivisors(Int k)
{
    Int i;
    
    for (i=1;i*i<=k;i++)
    {
        if (k%i==0)
        {
            if (i*i!=k)
            {
                dL++;
                Divisors[dL]=i;
                dL++;
                Divisors[dL]=k/i;
            }
            else
            {
                dL++;
                Divisors[dL]=i;
            }
        }
    }
    return;
}

int main()
{
    Int a,b;
    Int uk1,uk2;
    Int l,r,mid;
    Int n;
    Int i;
    Int maxdude;
    Int high,low;
    
    scanf("%I64d %I64d",&a,&b);
    
    dL=0;
    GetDivisors(a);
    for (i=1;i<=dL;i++)
    {
        DivisorsA[i]=Divisors[i];
    }
    daL=dL;
    
    
    dL=0;
    GetDivisors(b);
    for (i=1;i<=dL;i++)
    {
        DivisorsB[i]=Divisors[i];
    }
    dbL=dL;
    
    sort(DivisorsA+1,DivisorsA+1+daL);
    sort(DivisorsB+1,DivisorsB+1+dbL);
    
    uk1=1;
    uk2=1;
    
    while(uk1<=daL && uk2<=dbL)
    {
        if (DivisorsA[uk1]==DivisorsB[uk2])
        {
            pL++;
            Perfect[pL]=DivisorsA[uk1];
            uk1++;
            uk2++;
        }
        else if (DivisorsA[uk1]>DivisorsB[uk2])
        {
            uk2++;
        }
        else
        {
            uk1++;
        }
    }
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d %I64d",&low,&high);
        
        maxdude=-1;
        l=1;
        r=pL;
        while(l<=r)
        {
            mid=(l+r)/2;
            
            if (Perfect[mid]>=low && Perfect[mid]<=high)
            {
                maxdude=Perfect[mid];
                l=mid+1;
            }
            else if (Perfect[mid]<low)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        printf("%I64d\n",maxdude);
    }
    return 0;
}