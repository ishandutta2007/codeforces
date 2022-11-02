#include <bits/stdc++.h>
using namespace std;

long long int k, d, t, o, t2, trj = 0, tcik, vrcik, vrrj = 0, no, vr1;

int main()
{
    scanf("%lld %lld %lld", &k, &d, &t);
    o = (long long) (d - k % d) % d;
    t2 = (long long) t * 2;
    tcik = (long long) 2 * k + (long long) 2 * o;
    vrcik = (long long) 2 * k + o;
    vrrj += (long long) t2 / vrcik;
    trj = (long long) vrrj * tcik;
    no = (long long) t2 % vrcik;
    vr1 = (long long) 2 * k;
    if (no == 0)
    {
        printf("%0.10lf", (double) (trj / 2));
        return 0;
    }
    if (no <= vr1)
    {
        printf("%0.10lf", (double) ((long long) trj + no) / 2);
    }
    else
    {
        printf("%0.10lf", (double) ((trj + vr1 + (no - vr1) * 2) / 2));
    }
    return 0;
}