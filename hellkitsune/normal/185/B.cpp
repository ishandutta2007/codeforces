#include <iostream>
#include <cstdio>

using namespace std;

const double eps = 1e-12;
double s;
int a[3];

/*void bs(void)
{
    double l = 0, r = s, m, res, cur;
    for (int t = 0; t < 200; ++t)
    {
        m = (l + r) / 2;
        res = 0;
        for (int i = 0; i < 3; ++i)
            if (a[i] != 0)
            {
                cur = m;
                for (int j = 1; j < a[i]; ++j)
                {
                    cur *= m;
                    if (cur > s + eps)
                        break;
                }
                res += cur;
                if (res > s + eps)
                    break;
            }
        if (res > s)
            r = m;
        else
            l = m;
    }
    for (int i = 0; i < 3; ++i)
    {
        if (a[i] == 0)
            printf("%d ", 0);
        else
        {
            cur = l;
            for (int j = 1; j < a[i]; ++j)
                cur *= l;
            printf("%.15lf ", cur);
        }
    }
}*/

int main(void)
{
    cin >> s >> a[0] >> a[1] >> a[2];
    cout.precision(10);
    if (!a[0] && !a[1] && !a[2])
    {
        printf("%.10lf %d %d\n", s, 0, 0);
        return 0;
    }
    double t = s / (a[0] + a[1] + a[2]);
    printf("%.15lf %.15lf %.15lf\n", t * a[0], t * a[1], t * a[2]);
    return 0;
}