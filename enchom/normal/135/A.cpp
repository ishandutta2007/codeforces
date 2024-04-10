#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

struct arr
{
    Int val,orgind;
};

arr array[100001];
Int answer[100001];

bool SortEm(arr a,arr b)
{
    return (a.val<b.val);
}

int main()
{
    Int n;
    Int i;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&array[i].val);
        array[i].orgind=i;
    }
    sort(array+1,array+1+n,SortEm);
    for (i=1;i<=n;i++)
    {
        if (array[i].val==1)
        {
            if (i!=n)
            answer[ i ]=1;
            else
            answer[ i ]=2;
        }
        else
        {
            if (i!=1)
            answer[ i ]=array[i-1].val;
            else
            answer[ i ]=1;
        }
    }
    for (i=1;i<=n;i++)
    {
        printf("%I64d",answer[i]);
        if (i==n)
        printf("\n");
        else
        printf(" ");
    }
    return 0;
}