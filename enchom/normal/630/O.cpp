#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
using namespace std;
typedef long long Int;
typedef long double Double;

const Double PI=4.0*atan(1.0);
const Double SIN90=sin(PI/2.0),COS90=cos(PI/2.0);
const Double SIN180=sin(PI),COS180=cos(PI);
const Double SIN_90=sin(-PI/2.0),COS_90=cos(-PI/2.0);

void EnchomSolve()
{
    Double px,py,vx,vy,a,b,c,d;
    Double baselen;
    Double VX,VY,hX,hY;
    Double factor;
    Double x[9],y[9];
    int i;

    cin>>px>>py>>vx>>vy>>a>>b>>c>>d;
    /*px=8.0;
    py=8.0;
    vx=0.0;
    vy=2.0;
    a=8.0;
    b=3.0;
    c=4.0;
    d=5.0;*/

    baselen=sqrt(vx*vx+vy*vy);

    ///Point 1
    factor=b/baselen;
    VX=vx*factor;
    VY=vy*factor;
    x[1]=px+VX;
    y[1]=py+VY;

    ///Point 2
    factor=(a/2.0)/baselen;
    hX=vx*factor;
    hY=vy*factor;
    VX=COS90*hX - SIN90*hY;
    VY=SIN90*hX + COS90*hY;
    x[2]=px+VX;
    y[2]=py+VY;

    ///Point 3
    factor=(c/2.0)/baselen;
    hX=vx*factor;
    hY=vy*factor;
    VX=COS90*hX - SIN90*hY;
    VY=SIN90*hX + COS90*hY;
    x[3]=px+VX;
    y[3]=py+VY;

    ///Point 4
    factor=d/baselen;
    hX=vx*factor;
    hY=vy*factor;
    VX=COS180*hX - SIN180*hY;
    VY=SIN180*hX + COS180*hY;
    x[4]=x[3]+VX;
    y[4]=y[3]+VY;

    ///Point 6
    factor=(c/2.0)/baselen;
    hX=vx*factor;
    hY=vy*factor;
    VX=COS_90*hX - SIN_90*hY;
    VY=SIN_90*hX + COS_90*hY;
    x[6]=px+VX;
    y[6]=py+VY;

    ///Point 5
    factor=d/baselen;
    hX=vx*factor;
    hY=vy*factor;
    VX=COS180*hX - SIN180*hY;
    VY=SIN180*hX + COS180*hY;
    x[5]=x[6]+VX;
    y[5]=y[6]+VY;

    ///Point 7
    factor=(a/2.0)/baselen;
    hX=vx*factor;
    hY=vy*factor;
    VX=COS_90*hX - SIN_90*hY;
    VY=SIN_90*hX + COS_90*hY;
    x[7]=px+VX;
    y[7]=py+VY;

    for (i=1;i<=7;i++)
    {
        printf("%.10f %.10f\n",(double)x[i],(double)y[i]);
    }

    return;
}

int main()
{
    EnchomSolve();
    return 0;
}