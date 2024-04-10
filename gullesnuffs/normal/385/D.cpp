#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cstdlib>
#include <complex>
#include <cassert>
#define PI 3.14159265358979
using namespace std;

double dp[1100000];
int x[25], y[25];
double a[25];

double getLen(double x, int d, double a){
    double b=atan(x/d);
    double c=a-b;
    if(c > PI/2)
        return 1000000;
    return x+(d*tan(c));
}

int main()
{
    int n, l, r;
    scanf("%d%d%d", &n, &l, &r);
    for(int i=0; i < n; ++i){
        scanf("%d%d%lf", x+i, y+i, a+i);
        x[i] -= l;
        a[i] *= PI/180.0;
    }
    r -= l;
    l -= l;
    for(int i=0; i < (1<<n); ++i)
        dp[0]=0;
    for(int i=0; i < (1<<n); ++i){
        for(int j=0; j < n; ++j){
            if(i&(1<<j))
                continue;
            double newPos=dp[i]+getLen(x[j]-dp[i], y[j], a[j]);
            if(newPos > r)
                newPos=r;
            dp[i|(1<<j)]=max(dp[i|(1<<j)], newPos);
        }
    }
    printf("%.6lf\n", dp[(1<<n)-1]);
    return 0;
}