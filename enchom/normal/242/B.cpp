#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

struct segment
{
    Int l,r;
};

segment segments[100001];
Int n;

int main()
{
    Int i;
    Int smallestbeg=999999999999,largestend=-1;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d %I64d",&segments[i].l,&segments[i].r);
        
        if (smallestbeg>segments[i].l)
        smallestbeg=segments[i].l;
        
        if (largestend<segments[i].r)
        largestend=segments[i].r;
    }
    for (i=1;i<=n;i++)
    {
        if (segments[i].l==smallestbeg && segments[i].r==largestend)
        {
            printf("%I64d\n",i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}