#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
typedef long long Int;

struct point
{
    double x,y;
};

point signature[101];

double ABS(double a)
{
    if (a<0.0)
    return a*-1.0;
    else
    return a;
}

double Dist(double x1,double y1,double x2,double y2)
{
    double side1,side2;
    double distance;
    side1=ABS(x1-x2);
    side2=ABS(y1-y2);
    distance=sqrt(side1*side1+side2*side2);
    return distance;
}

int main()
{
    Int n,k;
    Int i,j;
    double totaltime=0.0;
    
    scanf("%I64d %I64d",&n,&k);
    
    for (i=1;i<=n;i++)
    {
        cin>>signature[i].x>>signature[i].y;
    }
    
    for (i=2;i<=n;i++)
    {
        totaltime=totaltime+Dist(signature[i-1].x,signature[i-1].y,signature[i].x,signature[i].y)*20.0;
    }
    totaltime=totaltime*k;
    totaltime=totaltime/1000;
    printf("%4.6f\n",totaltime);
    return 0;
}