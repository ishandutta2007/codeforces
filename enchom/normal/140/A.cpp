#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
typedef long long Int;

const double PI=4.0*atan(1.0);

double FABS(double a)
{
    if (a<0.0)
    return a*(-1.0);
    else
    return a;
}

double Equal(double a,double b)
{
    double c=FABS(a-b);

    if (c<0.00000001)
    return true;
    else
    return false;
}

int main()
{
    Int r,R,n,a;
    double d;
    double plates;
    Int p;

    scanf("%I64d %I64d %I64d",&n,&R,&r);

    a=R-r;

    if (a<0)
    {
        printf("NO\n");
        return 0;
    }
    if (r*2>R)
    {
        if (n==1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        return 0;
    }

    d=(double)r/(double)a;
    d=asin(d)*2;

    d=d*180 / PI;

    plates=360.0 / d;

    if ( Equal(plates,ceil(plates)) )
    {
        plates=ceil(plates);
    }
    else
    {
        plates=floor(plates);
    }

    p=(Int)plates;

    if (p>=n)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}