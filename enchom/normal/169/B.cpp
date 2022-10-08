#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

typedef long long Int;

Int num1[100001];
Int n;
Int num2[100001];
Int m;

bool SortEm(Int a,Int b)
{
    return (a>b);
}

int main()
{
    Int i;
    string inp;
    Int uk;
    cin>>inp;
    n=inp.length();
    for (i=0;i<n;i++)
    {
        num1[i+1]=(int)( inp[i]-'0' );
    }
    cin>>inp;
    m=inp.length();
    for (i=0;i<m;i++)
    {
        num2[i+1]=(int)( inp[i]-'0' );
    }
    sort(num2+1,num2+1+m,SortEm);
    uk=1;
    for (i=1;i<=n;i++)
    {
        if (num2[uk]>num1[i])
        {
            num1[i]=num2[uk];
            uk++;
        }
        if (uk>m)
        break;
    }
    for (i=1;i<=n;i++)
    {
        printf("%I64d",num1[i]);
    }
    printf("\n");
    return 0;
}