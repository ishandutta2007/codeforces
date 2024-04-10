#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long Int;

#define PI 3.14159265

struct point
{
    Int x,y;
};

point mans[100001];

Int CrossProduct(point a,point b)
{
    Int result=a.x*b.y-a.y*b.x;
    return result;
}

double Distance(point a)
{
    return sqrt( (double)(a.x*a.x+a.y*a.y) );
}

double GetAngle(point a,point b)
{
    double coliniarmultiplication=(double)(a.x*b.x+a.y*b.y)/(double)(Distance(a)*Distance(b));
    double radians=acos(coliniarmultiplication);
    double degrees=(180.0*radians)/PI;
    if (CrossProduct(a,b)<0)
    {
        degrees=360.0-degrees;
    }
    return degrees;
}

bool SortAngles(point a,point b)
{
    if (a.x==0 && b.x==0 && a.y<0 && b.y<0)
    {
        return (a.y<b.y);
    }
    else if (a.x==0 && a.y<0)
    {
        return true;
    }
    else if (b.x==0 && b.y<0)
    {
        return false;
    }
    if (a.x>0 && b.x<0)
    return true;
    if (a.x<0 && b.x>0)
    return false;
    
    Int crossproduct=CrossProduct(a,b);
    
    if (crossproduct<0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    Int n;
    Int i;
    double angle;
    double maxangle=0.0;
    double answer;
    bool exception=true;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d %I64d",&mans[i].x,&mans[i].y);
    }
    for (i=1;i<=n-1;i++)
    {
        if (CrossProduct(mans[i],mans[i+1])!=0)
        {
            exception=false;
            break;
        }
    }
    if (exception)
    {
        printf("0.000000\n");
        return 0;
    }
    
    
    sort(mans+1,mans+1+n,SortAngles);
    
    for (i=1;i<=n;i++)
    {
        if (i==n)
        {
            angle=GetAngle(mans[n],mans[1]);
        }
        else
        {
            angle=GetAngle(mans[i],mans[i+1]);
        }
        if (angle>maxangle)
        maxangle=angle;
    }
    answer=360.0-maxangle;
    printf("%4.6f\n",answer);
    return 0;
}
/*
25
229 -788
-457 -615
403 994
301 -902
-326 -45
981 176
-684 741
617 899
713 681
-144 -729
245 875
414 -749
888 -170
-644 697
-817 -113
604 -827
-362 -548
21 -235
-184 -550
70 12
-797 -383
465 -280
-705 333
-793 14

*/