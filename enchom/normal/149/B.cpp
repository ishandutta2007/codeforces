#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long Int;

Int hour[10],minute[10];
Int hL,mL;
Int possible[1000],pL=0;

Int POWER(Int k,Int p)
{
    Int i;
    Int ans=1;
    
    for (i=1;i<=p;i++)
    ans=ans*k;
    
    return ans;
}

Int DecimalHours(Int base)
{
    Int i,onpower=0;
    Int num=0;
    
    for (i=hL;i>=1;i--)
    {
        num=num+hour[i]*POWER(base,onpower);
        onpower++;
    }
    return num;
}

Int DecimalMins(Int base)
{
    Int i,onpower=0;
    Int num=0;
    
    for (i=mL;i>=1;i--)
    {
        num=num+minute[i]*POWER(base,onpower);
        onpower++;
    }
    return num;
}

int main()
{
    string a;
    Int decimalh,decimalm;
    Int i;
    bool passed=false;
    Int largest=-1;
    
    cin>>a;
    
    for (i=0;i<a.length();i++)
    {
        if (a[i]==':')
        {
            passed=true;
        }
        else if (!passed)
        {
            hL++;
            if (a[i]<='9' && a[i]>='0')
            hour[hL]=a[i]-'0';
            else
            hour[hL]=(a[i]-'A')+10;
            
            if (hour[hL]>largest)
            largest=hour[hL];
        }
        else
        {
            mL++;
            if (a[i]<='9' && a[i]>='0')
            minute[mL]=a[i]-'0';
            else
            minute[mL]=(a[i]-'A')+10;
            
            if (minute[mL]>largest)
            largest=minute[mL];
        }
    }
    
    largest++;
    
    for (i=largest;i<=400;i++)
    {
        decimalm=DecimalMins(i);
        if (decimalm<0 || decimalm>59)
        continue;
        
        decimalh=DecimalHours(i);
        if (decimalh<0 || decimalh>23)
        continue;
        
        pL++;
        possible[pL]=i;
    }
    if (pL>300)
    {
        printf("-1\n");
        return 0;
    }
    
    for (i=1;i<=pL;i++)
    {
        printf("%I64d",possible[i]);
        if (i==pL)
        printf("\n");
        else
        printf(" ");
    }
    if (pL==0)
    printf("0\n");
    return 0;
}