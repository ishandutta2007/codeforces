#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

struct rect
{
    Int x1,y1,x2,y2;
};

rect rects[6];

int main()
{
    Int i;
    Int n;
    Int minx=99999,miny=99999,maxx=-1,maxy=-1;
    Int sqarea,rarea=0;

    scanf("%I64d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d %I64d %I64d %I64d",&rects[i].x1,&rects[i].y1,&rects[i].x2,&rects[i].y2);

        if (rects[i].x1<minx)
        {
            minx=rects[i].x1;
        }
        if (rects[i].y1<miny)
        {
            miny=rects[i].y1;
        }

        if (rects[i].x2>maxx)
        {
            maxx=rects[i].x2;
        }
        if (rects[i].y2>maxy)
        {
            maxy=rects[i].y2;
        }

        rarea=rarea+(rects[i].x2-rects[i].x1)*(rects[i].y2-rects[i].y1);
    }

    sqarea=(maxx-minx)*(maxy-miny);

    if (sqarea!=rarea || maxx-minx!=maxy-miny)
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n");
    }

    return 0;
}