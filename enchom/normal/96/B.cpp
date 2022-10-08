#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int LuckyNums[100001];
Int LNL=0;

bool SuperLucky(Int k)
{
    Int four=0,seven=0;
    while(k>0)
    {
        if (k%10==4)
        four++;
        else if (k%10==7)
        seven++;
        
        k=k/10;
    }
    if (four==seven)
    return true;
    else
    return false;
}

void GenLucky(Int digitsleft,Int num)
{
    if (digitsleft==0)
    {
        if (SuperLucky(num))
        {
            LNL++;
            LuckyNums[LNL]=num;
        }
        return;
    }
    else
    {
        GenLucky(digitsleft-1,num*10+4);
        GenLucky(digitsleft-1,num*10+7);
    }
    return;
}

int main()
{
    Int i;
    Int n;
    Int closest=-1;
    Int l,r,mid;
    
    cin>>n;
    
    if (n>77774444)
    {
        printf("4444477777");
        return 0;
    }
    
    for (i=1;i<=9;i++)
    {
        GenLucky(i,0);
    }
    
    l=1;
    r=LNL;
    
    while(l<=r)
    {
        mid=(l+r)/2;
        
        if (LuckyNums[mid]>=n)
        {
            closest=LuckyNums[mid];
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    printf("%I64d\n",closest);
    return 0;
}