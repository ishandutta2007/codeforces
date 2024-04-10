#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <ctime>
#include <memory.h>
#include <string>
#include <sstream>
#include <map>

#define ll long long

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,a,d;
    scanf("%d%d%d",&n,&a,&d);
    double last=0,t,v,eps=1e-6;
    for(int i=0;i<n;++i) {
        scanf("%lf%lf",&t,&v);
        double tm=sqrt(2.0*d/a);//(-v+sqrt(v*v+4*d-2*a))/a;
        if (tm-eps<v/a) {}
        else {
            tm=v/a;
            tm+=(d-(a*tm*tm/2))/v;
        }
        last=max(last,tm+t);
        printf("%.6lf\n",last);
    }
    return 0;
}