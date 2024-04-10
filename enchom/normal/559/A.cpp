#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
typedef long double Double;

Double S,C;
Double PI=4.0*atan(1.0);

int a[7];
pair<Double,Double> pts[7];

Double CP(pair<Double,Double> A,pair<Double,Double> B)
{
    return A.first*B.second-A.second*B.first;
}

int main()
{
    int i,j;
    Double area=0.0;
    Double X,Y;
    Double triangle=sqrt(3.0)/4.0;
    int ans;

    S=sin( (60.0*PI)/180.0 );
    C=cos( (60.0*PI)/180.0 );

    for (i=1;i<=6;i++)
    {
        scanf("%d",&a[i]);
    }

    pts[1]=make_pair(0.0,0.0);

    for (i=2;i<=6;i++)
    {
        pts[i].first=pts[i-1].first+(Double)a[i];
        pts[i].second=0;
    }

    for (i=2;i<=5;i++)
    {
        for (j=i+1;j<=6;j++)
        {
            X=pts[j].first-pts[i].first;
            Y=pts[j].second-pts[i].second;

            pts[j].first=X*C-Y*S;
            pts[j].second=X*S+Y*C;

            pts[j].first+=pts[i].first;
            pts[j].second+=pts[i].second;
        }
    }

    for (i=1;i<=5;i++)
    {
        area=area+CP(pts[i],pts[i+1]);
    }
    area=area+CP(pts[6],pts[1]);

    if (area<0.0)
    area=-area;

    area/=2.0;

    ans=floor( area/triangle+0.5 );

    printf("%d\n",ans);

    return 0;
}