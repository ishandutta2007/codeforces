#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long Int;

int main()
{
    Int k,l;
    Int importance=0;
    Int org;
    bool partof=false;
    
    scanf("%I64d %I64d",&k,&l);
    org=k;
    while(k<=l)
    {
        if (k==l)
        {
            partof=true;
            break;
        }
        else
        {
            k=k*org;
            importance++;
        }
    }
    if (partof)
    {
        printf("YES\n");
        printf("%I64d\n",importance);
        return 0;
    }
    else
    {
        printf("NO\n");
        return 0;
    }
}