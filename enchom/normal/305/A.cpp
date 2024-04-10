#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long Int;

Int amountoftype[5]; ///0=000 / 1=001 / 2=010 / 3=011 / 4=100
Int nums[101];
Int TheType[101];
vector<Int> result;

Int TypeOf(Int k)
{
    if (k==0)
    return 0;
    if (k==100)
    return 4;

    if (k<10)
    return 1;

    if (k%10!=0)
    return 3;

    return 2;
}

int main()
{
    Int n;
    Int i;
    Int total;
    Int L;
    Int a;

    scanf("%I64d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&a);
        nums[i]=a;

        TheType[i]=TypeOf(a);

        amountoftype[ TheType[i] ]++;
    }

    if (amountoftype[1]>0 && amountoftype[2]>0)
    {
        for (i=1;i<=n;i++)
        {
            if (TheType[i]==1)
            {
                result.push_back(nums[i]);
                break;
            }
        }
        for (i=1;i<=n;i++)
        {
            if (TheType[i]==2)
            {
                result.push_back(nums[i]);
                break;
            }
        }
    }
    else if (amountoftype[1]>0 || amountoftype[2]>0 || amountoftype[3]>0)
    {
        for (i=1;i<=n;i++)
        {
            if (TheType[i]==1 || TheType[i]==2 || TheType[i]==3)
            {
                result.push_back(nums[i]);
                break;
            }
        }
    }
    if (amountoftype[0]>0)
    {
        result.push_back(0);
    }
    if (amountoftype[4]>0)
    {
        result.push_back(100);
    }

    sort(result.begin(),result.end());

    L=result.size();

    printf("%I64d\n",L);

    for (i=0;i<L;i++)
    {
        printf("%I64d",result[i]);
        if (i!=L-1)
        {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}