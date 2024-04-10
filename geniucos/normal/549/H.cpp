#include<cstdio>
#include<iomanip>
#include<iostream>
#include<fstream>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

int a, b, c, d, sg[10];
long double mini, x, eps = 1e-11;

int main()
{
//freopen ("input", "r", stdin);
//ofstream cout("output");

scanf ("%d %d %d %d", &a, &b, &c, &d);
mini = 10000000000.000;
for (int msk = 0; msk < 16; msk ++)
{
    for (int bit = 0; bit < 4; bit ++)
        if (msk & (1<<bit))
            sg[bit + 1] = 1;
        else
            sg[bit + 1] = -1;
    long long A, B, C;
    A = (long long) sg[1] * sg[2] - sg[3] * sg[4];
    B = (long long) 1LL * sg[1] * d + 1LL * sg[2] * a - 1LL * sg[4] * b - 1LL * sg[3] * c;
    C = (long long) (1LL * a * d - 1LL * b * c);
    if (A == 0 && B == 0 && C == 0)
    {
        printf ("0.0000000000\n");
        return 0;
    }
    if (A == 0 && B == 0)
        continue;
    if (A == 0)
        x = (long double) -C / B;
    else
    {
        if ((long double) B * B - (long double)4.0 * A * C < 0.0)
            continue;
        long double delt = (long double) sqrt( (long double) B * B - (long double)4.0 * A * C);
        if (A > 0) x = (long double) (-B + delt) / (2 * A);
        else x = (long double) (-B - delt) / (2 * A);
    }
    if (x < 0)
        continue;
/*    if (x < 0)
        x = -x;*/
    if (x < mini)
        mini = x;
}
cout << fixed << setprecision (12) << mini << '\n';

return 0;
}