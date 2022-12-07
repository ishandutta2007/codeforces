#include <stdio.h>

using namespace std;

const double eps = 0.0001;
int n, il, ir, m;
double L, v1, v2, l, r, rr;
double a[200001];
double answ[100001] = {0};

void answout()
{
    int i;
    for (i = 0; i <= n; ++i)
        printf("%.15lf\n", answ[i]);
}

int main(void)
{
    int i;
    scanf("%d%lf%lf%lf", &n, &L, &v1, &v2);
    for (i = 0; i < n; ++i)
        scanf("%lf", a + i);
    for (i = 0; i < n; ++i)
        a[n + i] = a[i] + 2 * L;
    a[2 * n] = a[0] + 4 * L;
    l = 0;
    rr = r = L * v2 / (v1 + v2);
    il = 0;
    ir = -1;
    while (a[ir + 1] < r)
        ++ir;
    while (true)
    {
        if (a[il] - l < a[ir + 1] - r)
        {
            m = ir - il + 1;
            if (a[il] > 2 * L)
            {
                answ[m] += (2 * L - l) / (2 * L);
                answout();
                return 0;
            }
            answ[m] += (a[il] - l) / (2 * L);
            l = a[il];
            r = a[il] + rr;
            ++il;
        }
        else
        {
            m = ir - il + 1;
            if (a[ir + 1] - rr > 2 * L)
            {
                answ[m] += (2 * L - l) / (2 * L);
                answout();
                return 0;
            }
            answ[m] += (a[ir + 1] - r) / (2 * L);
            r = a[ir + 1];
            l = a[ir + 1] - rr;
            ++ir;
        }
    }
    return 0;
}