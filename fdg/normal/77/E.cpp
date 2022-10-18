#include <iostream>
#include <cmath>

#define ll long long

using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        double R,r,k;
        scanf("%lf%lf%lf",&R,&r,&k);
        double x1=0.5/R,x2=0.5/r,rr=fabs(x1-x2)/2;
        double x=(x1+x2)/2,y=2*k*rr;
        double res=sqrt(x*x+y*y);
        printf("%.9lf\n",(1/(res-rr)-1/(res+rr))/2);
    }
    return 0;
}