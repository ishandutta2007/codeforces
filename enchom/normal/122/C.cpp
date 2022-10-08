#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long Int;

Int LuckyNums[10000001];
Int LNL=0;

void GenLuckyNum(Int digitsleft,Int num)
{
    if (digitsleft==0)
    {
        LNL++;
        LuckyNums[LNL]=num;
        return;
    }
    else
    {
        GenLuckyNum(digitsleft-1,num*10+4);
        GenLuckyNum(digitsleft-1,num*10+7);
    }
}

int main()
{
    Int i,j;
    Int l,r;
    Int reached;
    Int sum=0;
    
    for (i=1;i<=9;i++)
    {
        GenLuckyNum(i,0);
    }
    LNL++;
    LuckyNums[LNL]=4444444444;
    scanf("%I64d %I64d",&l,&r);
    reached=l;
    for (i=1;i<=LNL;i++)
    {
        if (reached<=LuckyNums[i])
        {
            if (LuckyNums[i]<r)
            {
                sum=sum+(LuckyNums[i]-reached+1)*LuckyNums[i];
                reached=LuckyNums[i]+1;
            }
            else
            {
                sum=sum+(r-reached+1)*LuckyNums[i];
                break;
            }
        }
    }
    printf("%I64d\n",sum);
    return 0;
}