#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <functional>
#include <stack>
#include <sstream>

#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)
#define dforn(i,n) for(int i=(n)-1;i>=0; i--)
#define dforsn(i,s,n) for(int i=(n)-1;i>=(int)(s); i--)

#define esta(x,c) ((c).find(x) != (c).end())

using namespace std;

typedef long long tint;

const int MAX = 1000010;

double px[MAX];
double py[MAX];

int main() 
{
    #ifdef ACMTUYO
        if (!freopen("a.in" ,"r",stdin)) return 1;
    #endif
    int _sc = 0;
    int N,ix, iy;
    while (scanf("%d%d%d", &N, &ix, &iy) != EOF)
    {
        const double x = ix;
        const double y = iy;
        double maxDist = 0.0;
        forn(i,N)
        {
            _sc = scanf("%d%d", &ix, &iy);
            px[i] = ix;
            py[i] = iy;
            maxDist = max(maxDist, hypot(px[i] - x, py[i] - y));
        }
        px[N] = px[0];
        py[N] = py[0];
        double minDist = maxDist;
        forn(i,N)
        {
            minDist = min(minDist, hypot(px[i] - x, py[i] - y));
            double vx = px[i+1] - px[i];
            double vy = py[i+1] - py[i];
            const double vnorm = hypot(vx, vy);
            vx /= vnorm;
            vy /= vnorm;
            const double dx = x - px[i];
            const double dy = y - py[i];
            double pi = dx * vx + dy * vy;
            if (0.0 <= pi && pi <= vnorm)
            {
                double hyp = hypot(dx, dy);
                minDist = min(minDist, sqrt(hyp*hyp - pi*pi));
            }
        }
        const double PI = 4.0 * atan(1.0);
        double area = PI * (maxDist + minDist) * (maxDist - minDist);
        printf("%.15lf\n", area);
    }
    if (_sc) return 0;
    return 0;
}