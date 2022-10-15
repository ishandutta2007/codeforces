#include <iostream>
#include <algorithm>
#include <iomanip>
#define ar(a) a[300000] = {}

using namespace std;

int n;
long double ar(a), ar(b), ar(p), ar(l), ar(h);

long double val(long double x)
{
    long double _min, _max;
    for (int i = 0; i < n; i++) b[i] = p[i] - x * (i + 1);
    _max = b[0]; _min = b[0];
    l[0] = min((long double)0, b[0]);
    h[0] = max((long double)0, b[0]);
    for (int i = 1; i < n; i++)
    {
        h[i] = max(h[i - 1], b[i]);
        l[i] = min(l[i - 1], b[i]);
        _max = max(_max, b[i] - l[i - 1]);
        _min = min(_min, b[i] - h[i - 1]);
    }
    return max(-_min, _max);
}

long double calc(long double l, long double r)
{
    for (int i = 0; i < 128; i++)
    {
        long double m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
        if (val(m1) > val(m2)) l = m1; else r = m2;
    }
    return l;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    p[0] = a[0];
    for (int i = 1; i < n; i++) p[i] = p[i - 1] + a[i];
    long double v = calc(-1e9, 1e9);
    cout << setprecision(10) << val(v);
}