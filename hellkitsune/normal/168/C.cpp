#include <iostream>
#include <stdio.h>

using namespace std;

int n;
double a, d, t, v, cur = 0, c;

double gett(double d, double a, double v)
{
    double t = v / a;
    if (a * t * t / 2> d)
    {
        double r = t, l = 0, m;
        for (int i = 0; i < 100; ++i)
        {
            m = (l + r) / 2;
            if (a * m * m / 2 > d)
                r = m;
            else
                l = m;
        }
        return m;
    }
    d -= a * t * t / 2;
    return t + d / v;
}

int main(void)
{
    int i;
    cin >> n >> a >> d;
    for (i = 0; i < n; ++i)
    {
        cin >> t >> v;
        c = t + gett(d, a, v);
        if (c < cur)
            printf("%.10lf\n", cur);
        else
        {
            printf("%.10lf\n", c);
            cur = c;
        }
    }
    return 0;
}