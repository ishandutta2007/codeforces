// Codeforces Beta Round #8
// Problem D -- Two Friends
#include <cstdio>
#include <complex>
#include <algorithm>

#define point complex<double>

using namespace std;

const double eps = 1e-7;

double t_1, t_2;
point c, h, s;

void input(point &z)
{
    double x, y;
    scanf("%lf%lf", &x, &y);
    z = point(x, y);
}

bool inter(point a, double r_a, point b, double r_b, point c, double r_c)
{
    if(abs(c - a) <= r_a && abs(c - b) <= r_b)
        return true;
    b -= a, c -= a;
    point r = point(b.real() / abs(b), b.imag() / abs(b));
    b /= r, c /= r;
    double d = (r_a * r_a - r_b * r_b + abs(b) * abs(b)) / (2 * abs(b)),
           h = sqrt(max(r_a * r_a - d * d, 0.0));
    if(abs(h * h + (d - abs(b)) * (d - abs(b)) - r_b * r_b) > eps)
        return false;
    if(abs(point(d, h) - c) <= r_c)
        return true;
    if(abs(point(d, -h) - c) <= r_c)
        return true;
    return false;
}

bool check(point a, double r_a, point b, double r_b, point c, double r_c)
{
    if(r_a <= -eps || r_b <= -eps || r_c <= -eps)
        return false;
    r_a = max(r_a, 0.0), r_b = max(r_b, 0.0), r_c = max(r_c, 0.0);
    if(inter(a, r_a, b, r_b, c, r_c))
        return true;
    if(inter(b, r_b, c, r_c, a, r_a))
        return true;
    if(inter(c, r_c, a, r_a, b, r_b))
        return true;
    return false;
}

int main()
{
    scanf("%lf%lf", &t_1, &t_2);
    input(c), input(h), input(s);
    if(abs(s - c) + abs(h - s) <= abs(h - c) + t_2)
        printf("%.5lf\n", min(abs(s - c) + abs(h - s) + t_1, abs(h - c) + t_2));
    else
    {
        double low = 0, upp = min(abs(s - c) + abs(h - s) + t_1, abs(h - c) + t_2);
        while(eps < abs(upp - low))
        {            
            double mid = (low + upp) / 2;
            if(check(c, mid, s, abs(s - c) + t_1 - mid, h, abs(h - c) + t_2 - mid))
                low = mid;
            else
                upp = mid;
        }
        printf("%.5lf\n", upp);
    }
    return 0;
}