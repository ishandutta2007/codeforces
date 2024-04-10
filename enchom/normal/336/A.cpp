#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

int main()
{
    Int x,y;
    Int l,r;
    Int a;
    bool xwasminus=false,ywasminus=false;

    scanf("%I64d %I64d",&x,&y);

    if (x<0)
    {
        x*=-1;
        xwasminus=true;
    }

    if (y<0)
    {
        y*=-1;
        ywasminus=true;
    }

    a=x+y;

    if (!ywasminus && !xwasminus)
    {
        printf("0 %I64d %I64d 0\n",a,a);
    }
    else if (xwasminus && ywasminus)
    {
        printf("%I64d 0 0 %I64d\n",0-a,0-a);
    }
    else if (xwasminus)
    {
        printf("%I64d 0 0 %I64d\n",0-a,a);
    }
    else
    {
        printf("0 %I64d %I64d 0\n",0-a,a);
    }

    return 0;
}