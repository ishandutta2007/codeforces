#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;
typedef long double Double;

struct point
{
    Int x,y;
};

point pts[301];
Int n;

Int D(Int x1,Int y1,Int x2,Int y2)
{
    return x1*y2-x2*y1;
}

int main()
{
    Int i,j,in;
    Int TheMin,TheMax;
    Int curd;
    Double Area;
    Double MaxArea=0.0;

    scanf("%I64d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d %I64d",&pts[i].x,&pts[i].y);
    }

    for (i=1;i<=n;i++)
    {
        for (j=i+1;j<=n;j++)
        {
            TheMin=0;
            TheMax=0;
            for (in=1;in<=n;in++)
            {
                if (in==i || in==j)
                continue;

                curd=D(pts[i].x-pts[in].x,pts[i].y-pts[in].y,pts[j].x-pts[in].x,pts[j].y-pts[in].y);

                if (curd<TheMin)
                TheMin=curd;
                if (curd>TheMax)
                TheMax=curd;
            }

            if (TheMin<0 && TheMax>0)
            {
                Area=(Double)(TheMin*-1) + (Double)TheMax;
                Area=Area/2.0;

                if (Area>MaxArea)
                MaxArea=Area;
            }
        }
    }

    printf("%.9f\n",(double)MaxArea);

    return 0;
}