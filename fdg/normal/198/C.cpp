#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <memory.h>
#include <string>
#include <map>

using namespace std;

double xp,yp,vp,x,y,v,r,R;

double Pi=3.14159265358979323846264,eps=1e-8;

double get(double tm) {
    double ang=vp*tm/R,nx=xp*cos(ang)-yp*sin(ang),ny=xp*sin(ang)+yp*cos(ang);
    double A=ny-y,B=x-nx,C=-x*A-y*B,ans=0,z=sqrt(A*A+B*B);
    A/=z; B/=z; C/=z;
    double mx=-A*C,my=-B*C;
    if (fabs(C)+eps<r&&(sqrt((x-mx)*(x-mx)+(y-my)*(y-my))+sqrt((nx-mx)*(nx-mx)+(ny-my)*(ny-my))<sqrt((x-nx)*(x-nx)+(y-ny)*(y-ny))+eps)) {
        double d1=sqrt(x*x+y*y),d2=sqrt(nx*nx+ny*ny);
        ans=sqrt(fabs(d1*d1-r*r))+sqrt(fabs(d2*d2-r*r));
        double alpha=fabs(atan2(y,x)-atan2(ny,nx));
        if (alpha>=Pi) alpha=2*Pi-alpha;
        alpha-=acos(r/d1)+acos(r/d2);
        ans+=alpha*r;
    } else ans=sqrt((x-nx)*(x-nx)+(y-ny)*(y-ny));
    return ans/v;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    cin >> xp >> yp >> vp >> x >> y >> v >> r;
    R=sqrt(fabs(xp*xp+yp*yp));
    double l=0,r=1e+9;
    for(int t=0;t<200;++t) {
        double m=(l+r)/2;
        if (get(m)-1e-8<m) r=m;
        else l=m;
    }
    printf("%.7lf\n",r);
    return 0;
}