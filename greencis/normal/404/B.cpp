#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <deque>
using namespace std;

long double a,d,x=0,y=0,p;
int n;

int main()
{
    //ios_base::sync_with_stdio(0);
    cin >> a >> d >> n;
    p=4.*a;

    for (int i = 0; i < n; ++i) {
        x += d;
        long long circles = (long long)(x / p);
        long double cur = x - p*circles;
        if (cur >= 0. && cur <= a) {
            printf("%.6lf %.6lf\n",(double)cur,0.);
        } else if (cur >= a && cur <= 2.*a) {
            printf("%.6lf %.6lf\n",(double)a,(double)(cur-a));
        } else if (cur >= 2.*a && cur <= 3.*a) {
            printf("%.6lf %.6lf\n",(double)(3*a-cur),(double)a);
        } else if (cur >= 3.*a && cur <= 4.*a) {
            printf("%.6lf %.6lf\n",0.,(double)(4*a-cur));
        }
    }

    return 0;
}