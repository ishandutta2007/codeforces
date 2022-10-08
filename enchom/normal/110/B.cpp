#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
typedef long long Int;

int main()
{
    Int letter=0;
    Int i;
    Int n;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        printf("%c",(char)(letter+(int)'a'));
        letter++;
        if (letter==4)
        letter=0;
    }
    printf("\n");
    return 0;
}