#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long Int;
typedef long double lf;

struct fpoint
{
    lf x,y;
};

struct segment
{
    lf x1,y1,x2,y2;
};

const lf PI=(lf)4.0 * (lf)atan(1.0);
fpoint pts[101];
fpoint dfix[101];
Int pL=0;
Int dL=0;
segment segments[21];
lf lowx,lowy;

lf FABS(lf a)
{
    if (a<(lf)0.0)
    return a*( (lf)-1.0 );
    else
    return a;
}

bool Equal(lf a,lf b)
{
    lf c=FABS(a-b);
    
    if (c<(lf)0.000000001)
    return true;
    else
    return false;
}

lf D(lf x1,lf y1,lf x2,lf y2)
{
    return (x1*y2-x2*y1);
}

bool SortAngle(fpoint a,fpoint b)
{
    lf crossproduct;
    
    crossproduct=D( a.x-lowx,a.y-lowy,b.x-lowx,b.y-lowy);
    
    if (Equal(crossproduct,(lf)0.0))
    {
        if (Equal(a.y,b.y))
        {
            return a.x<b.x;
        }
        else
        {
            return a.y<b.y;
        }
    }
    else
    {
        if (crossproduct>(lf)0.0)
        return true;
        else
        return false;
    }
}

bool Intersect(segment a,segment b)
{
    lf d1,d2;
    Int good=0;
    lf x1=a.x1,x2=a.x2,x3=b.x1,x4=b.x2;
    lf y1=a.y1,y2=a.y2,y3=b.y1,y4=b.y2;
        
    d1=D( x2-x1,y2-y1,x3-x1,y3-y1 );
    d2=D( x2-x1,y2-y1,x4-x1,y4-y1 );
    
    if ( Equal(d1,(lf)0.0) || Equal(d2,(lf)0.0) )
    {
        good++;
    }
    else if (d1<(lf)0.0 && d2>(lf)0.0)
    good++;
    else if (d1>(lf)0.0 && d2<(lf)0.0)
    good++;
    
    ////////////////////////////////////
    d1=D( x4-x3,y4-y3,x2-x3,y2-y3 );
    d2=D( x4-x3,y4-y3,x1-x3,y1-y3 );
    
    if ( Equal(d1,(lf)0.0) || Equal(d2,(lf)0.0) )
    {
        good++;
    }
    else if (d1<(lf)0.0 && d2>(lf)0.0)
    good++;
    else if (d1>(lf)0.0 && d2<(lf)0.0)
    good++;
    
    if (good==2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void GetIntersection(segment a,segment b)
{
    if (!Intersect(a,b))
    return;
    
    lf XCh,YCh,Znm;
    lf px,py;
    lf x1=a.x1,x2=a.x2,x3=b.x1,x4=b.x2;
    lf y1=a.y1,y2=a.y2,y3=b.y1,y4=b.y2;
    
    XCh=D( D(x1,y1,x2,y2),D(x1,(lf)1.0,x2,(lf)1.0),D(x3,y3,x4,y4),D(x3,(lf)1.0,x4,(lf)1.0) );
    YCh=D( D(x1,y1,x2,y2),D(y1,(lf)1.0,y2,(lf)1.0),D(x3,y3,x4,y4),D(y3,(lf)1.0,y4,(lf)1.0) );
    Znm=D( D(x1,(lf)1.0,x2,(lf)1.0),D(y1,1.0,y2,(lf)1.0),D(x3,(lf)1.0,x4,(lf)1.0),D(y3,(lf)1.0,y4,(lf)1.0) );
    
    if ( Equal(Znm,(lf)0.0) )
    {
        return;
    }
    
    px=XCh / Znm;
    py=YCh / Znm;
    
    pL++;
    pts[pL].x=px;
    pts[pL].y=py;
}

void Rotate(lf x,lf y,lf* rx,lf* ry,lf alpha)
{
    *rx = cos(alpha)*x - sin(alpha)*y;
    *ry = sin(alpha)*x + cos(alpha)*y;
    return;
}

int main()
{
    Int h,w,a;
    Int i,j;
    lf angle;
    lf x1,x2,x3,x4,y1,y2,y3,y4;
    lf rx1,rx2,rx3,rx4,ry1,ry2,ry3,ry4;
    lf area;
    
    scanf("%I64d %I64d %I64d",&w,&h,&a);
    
    if (a==0 || a==180)
    {
        printf("%I64d\n",w*h);
        return 0;
    }
    
    angle=( (lf)a * PI )/(lf)180.0;
    
    x1=(lf)0.0-(lf)w/(lf)2.0;
    y1=(lf)0.0-(lf)h/(lf)2.0;
    
    x2=(lf)w/(lf)2.0;
    y2=(lf)0.0-(lf)h/(lf)2.0;
    
    x3=(lf)w/(lf)2.0;
    y3=(lf)h/(lf)2.0;
    
    x4=(lf)0.0-(lf)w/(lf)2.0;
    y4=(lf)h/(lf)2.0;
    
    segments[1].x1=x1;
    segments[1].y1=y1;
    segments[1].x2=x2;
    segments[1].y2=y2;
    
    segments[2].x1=x2;
    segments[2].y1=y2;
    segments[2].x2=x3;
    segments[2].y2=y3;
    
    segments[3].x1=x3;
    segments[3].y1=y3;
    segments[3].x2=x4;
    segments[3].y2=y4;
    
    segments[4].x1=x4;
    segments[4].y1=y4;
    segments[4].x2=x1;
    segments[4].y2=y1;
    
    Rotate(x1,y1,&rx1,&ry1,angle);
    Rotate(x2,y2,&rx2,&ry2,angle);
    Rotate(x3,y3,&rx3,&ry3,angle);
    Rotate(x4,y4,&rx4,&ry4,angle);
    
    segments[5].x1=rx1;
    segments[5].y1=ry1;
    segments[5].x2=rx2;
    segments[5].y2=ry2;
    
    segments[6].x1=rx2;
    segments[6].y1=ry2;
    segments[6].x2=rx3;
    segments[6].y2=ry3;
    
    segments[7].x1=rx3;
    segments[7].y1=ry3;
    segments[7].x2=rx4;
    segments[7].y2=ry4;
    
    segments[8].x1=rx4;
    segments[8].y1=ry4;
    segments[8].x2=rx1;
    segments[8].y2=ry1;
    
    for (i=1;i<=4;i++)
    {
        for (j=5;j<=8;j++)
        {
            GetIntersection(segments[i],segments[j]);
        }
    }
    
    dL=1;
    dfix[1]=pts[1];
    for (i=2;i<=pL;i++)
    {
        if ( !( Equal(pts[i].x,pts[i-1].x) && Equal(pts[i].y,pts[i-1].y) ) )
        {
            dL++;
            dfix[dL]=pts[i];
        }
    }
    
    lowx=dfix[1].x;
    lowy=dfix[1].y;
    
    for (i=2;i<=dL;i++)
    {
        if (Equal(dfix[i].y,lowy))
        {
            if ( !Equal(dfix[i].x,lowx) && dfix[i].x<lowx )
            {
                lowx=dfix[i].x;
            }
        }
        else if (dfix[i].y<lowy)
        {
            lowy=dfix[i].y;
            lowx=dfix[i].x;
        }
    }
    
    sort(dfix+1,dfix+1+dL,SortAngle);
    
    area=(lf)0.0;
    for (i=1;i<=dL-1;i++)
    {
        area=area+D( dfix[i].x,dfix[i].y,dfix[i+1].x,dfix[i+1].y )/(lf)2.0;
    }
    area=area+D(dfix[dL].x,dfix[dL].y,dfix[1].x,dfix[1].y)/(lf)2.0;
    
    printf("%.6lf\n",(double)area);
    
    return 0;
}