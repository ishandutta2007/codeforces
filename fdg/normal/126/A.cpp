#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <ctime>

#define ll long long

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    double t1,t2,x1,x2,t0;
    int y1=0,y2=0;
    cin >> t1 >> t2 >> x1 >> x2 >> t0;
    if (t1==t2&&t1==t0) y1=x1,y2=x2;
    double myt=-1,tt;
    if (t2!=t0)
    for(int y=0;y<=x1;y++)
    {
        int yy=floor(1.0*(t0-t1)/(t2-t0)*y);
        if (y+yy!=0)
        {
            tt=1.0*(t1*y+t2*yy)/(y+yy);
            if (tt>=t0&&yy>=0&&yy<=x2&&((myt>tt||myt==-1)||fabs(myt-tt)<1e-7&&(y+yy)>y1+y2)) y1=y,y2=yy,myt=tt;
        }
        yy++;
        tt=1.0*(t1*y+t2*yy)/(y+yy);
        if (tt>=t0&&yy>=0&&yy<=x2&&((myt>tt||myt==-1)||fabs(myt-tt)<1e-7&&(y+yy)>y1+y2)) y1=y,y2=yy,myt=tt;
    }
    if (t1!=t0)
    for(int y=0;y<=x2;y++)
    {
        int yy=floor(1.0*(t0-t2)/(t1-t0)*y);
        if (y+yy!=0)
        {
            tt=1.0*(t2*y+t1*yy)/(y+yy);
            if (tt>=t0&&yy>=0&&yy<=x1&&((myt>tt||myt==-1)||fabs(myt-tt)<1e-10&&(y+yy)>y1+y2)) y1=yy,y2=y,myt=tt;
        }
        yy++;
        tt=1.0*(t2*y+t1*yy)/(y+yy);
        if (tt>=t0&&yy>=0&&yy<=x1&&((myt>tt||myt==-1)||fabs(myt-tt)<1e-10&&(y+yy)>y1+y2)) y1=yy,y2=y,myt=tt;
    }
    cout << y1 << " " << y2 << endl;
    return 0;
}