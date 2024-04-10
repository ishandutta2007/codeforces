#include <iostream>
#include <cstdio>

using namespace std;

int main(void)
{
    int n, i;
    double b, a[100], mx = 0;
    cin >> n >> b;
    for (i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] > mx)
            mx = a[i];
    }
    for (i = 0; i < n; ++i)
        b -= (a[i] = mx - a[i]);
    if (b > -0.000001)
    {
        cout.precision(10);
        for (i = 0; i < n; ++i)
            printf("%.6lf\n", a[i] + b / (double)n);
    }
    else
        cout << -1;
    return 0;
}