#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

int n;
double tmp;
ld a[100500], b[100500], x[100500], y[100500];
ld apr = 0., bpr = 0.;

int main()
{
    //ios_base::sync_with_stdio(0);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &tmp);
        x[i] = tmp;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &tmp);
        y[i] = tmp;
    }
    for (int i = 0; i < n; i++)
    {
        ld A = -x[i] - y[i] - apr + bpr;
        ld B = x[i] - bpr * (x[i] + y[i]);
        b[i] = (-A - sqrtl(max(ld(0), A * A - 4 * B))) / 2;
        a[i] = x[i] + y[i] - b[i];
        apr += a[i];
        bpr += b[i];
    }
    for (int i = 0; i < n; i++)
    {
        printf("%.17lf ", (double)a[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%.17lf ", (double)b[i]);
    }
    printf("\n");
    return 0;
}