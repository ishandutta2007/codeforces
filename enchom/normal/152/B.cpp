#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long Int;

int main()
{
    Int n,m,k;
    Int cx,cy;
    Int i,j;
    Int dx,dy;
    Int l,r,mid;
    Int steps;
    Int totalsteps=0;
    Int rx,ry;
    
    scanf("%I64d %I64d",&n,&m);
    scanf("%I64d %I64d",&cx,&cy);
    scanf("%I64d",&k);
    
    for (i=1;i<=k;i++)
    {
        scanf("%I64d %I64d",&dx,&dy);
        
        l=0;
        r=1000000000;
        steps=0;
        while(l<=r)
        {
            mid=(l+r)/2;
            rx=cx+dx*mid;
            ry=cy+dy*mid;
            
            if (rx>n || ry>m || rx<1 || ry<1)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
                steps=mid;
            }
        }
        totalsteps=totalsteps+steps;
        cx=cx+dx*steps;
        cy=cy+dy*steps;
    }
    printf("%I64d\n",totalsteps);
    return 0;
}