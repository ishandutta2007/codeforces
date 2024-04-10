#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

Int groups[5];

int main()
{
    Int n;
    Int i;
    Int a;
    Int taxis=0;
    
    scanf("%I64d",&n);
    
    groups[1]=0;
    groups[2]=0;
    groups[3]=0;
    groups[4]=0;
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&a);
        groups[a]++;
    }
    ///Groups of 4
    taxis=taxis+groups[4];
    groups[4]=0;
    ///Groups of 3
    taxis=taxis+groups[3];
    groups[1]=groups[1]-groups[3];
    if (groups[1]<0)
    groups[1]=0;
    groups[3]=0;
    ///Groups of 2
    taxis=taxis+(groups[2]/2);
    groups[2]=groups[2]%2;
    if (groups[2]==1)
    {
        taxis++;
        groups[1]=groups[1]-2;
        if (groups[1]<0)
        groups[1]=0;
    }
    groups[2]=0;
    ///Groups of 1
    taxis=taxis+(groups[1]/4);
    groups[1]=groups[1]%4;
    if (groups[1]>0)
    taxis++;
    groups[1]=0;
    ///End
    printf("%I64d",taxis);
    return 0;
}