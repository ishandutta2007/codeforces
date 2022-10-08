#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long Int;

int main()
{
    Int x,y,n;
    Int TWON;
    
    scanf("%I64d %I64d %I64d",&TWON,&x,&y);
    
    n=TWON/2;
    
    if (x==n && y==n)
    {
        printf("NO\n");
        return 0;
    }
    else if (x==n && y==n+1)
    {
        printf("NO\n");
        return 0;
    }
    else if (x==n+1 && y==n)
    {
        printf("NO\n");
        return 0;
    }
    else if (x==n+1 && y==n+1)
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    return 0;
}