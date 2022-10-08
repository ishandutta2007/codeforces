#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
using namespace std;
typedef long long Int;
typedef long double Double;

const Double PI=4.0*atan(1.0);

void EnchomSolve()
{
    int l;
    Double L;
    Double ans=0.0;
    Double area;
    Double height;
    Double help,help2;

    scanf("%d",&l);
    L=(Double)l;

    help=L/sqrt(3.0);
    height=sqrt(L*L-help*help);
    help=(sqrt(3.0)/2.0)*L;
    area=(help*L)/2.0;

    ans+=area*height/3.0;

    ///

    scanf("%d",&l);
    L=(Double)l;

    help=(sqrt(2.0)/2.0)*L;
    height=sqrt(L*L-help*help);
    area=L*L;

    ans+=area*height/3.0;

    ///

    scanf("%d",&l);
    L=(Double)l;

    help=L/( sqrt( 2.0-2.0*cos( 72.0*PI/180.0 ) ) );
    height=sqrt(L*L-help*help);
    help2=sqrt( help*help - (L/2.0)*(L/2.0) );
    area=L*help2/2.0;
    area*=5.0;

    ans+=area*height/3.0;

    printf("%.10f\n",(double)ans);

    return;
}

int main()
{
    EnchomSolve();
    return 0;
}