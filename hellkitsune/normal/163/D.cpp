#include <iostream>
#include <math.h>

using namespace std;

int t, k;
long long p[20], pp[20][70], v, vv, vvv, a, b, c, mina, minb, minc, s, maxa, maxb;
unsigned long long mins;
int q[20], aq[20], bq[20];

void nexta()
{
    if (a == 1)
    {
        a = 0;
        return;
    }
    int i;
    for (i = 0; aq[i] == q[i]; ++i)
    {
        aq[i] = 0;
        a *= pp[i][q[i]];
    }
    ++aq[i];
    a /= p[i];
}

void nextb()
{
    if (b == 1)
    {
        b = 0;
        return;
    }
    int i;
    for (i = 0; bq[i] == aq[i]; ++i)
    {
        bq[i] = 0;
        b *= pp[i][aq[i]];
    }
    ++bq[i];
    b /= p[i];
}

int main(void)
{
    int i, j;
    cin >> t;
    for (; t; --t)
    {
        cin >> k;
        v = 1;
        for (i = 0; i < k; ++i)
        {
            cin >> p[i] >> q[i];
            aq[i] = 0;
            pp[i][0] = 1;
            for (j = 1; j <= q[i]; ++j)
            {
                v *= p[i];
                pp[i][j] = pp[i][j - 1] * p[i];
            }
        }
        mins = v * 4 + 10;
        maxa = pow(v, 1.0 / 3);
        while (maxa * maxa * maxa < v)
            ++maxa;
        for (a = v; a; nexta())
        {
            if (a > maxa)
                continue;
            for (i = 0; i < k; ++i)
                bq[i] = 0;
            vv = v / a;
            maxb = b = sqrt(vv);
            if (b * b >= vv)
                --b;
            if (maxb * maxb < vv)
                ++maxb;
            if ((2 * a + b) * b > (long long)mins)
                continue;
            for (b = vv; b; nextb())
            {
                if (b > maxb)
                    continue;
                c = vv / b;
                if (a * b + b * c + c * a < (long long)mins)
                {
                    mins = a * b + b * c + c * a;
                    mina = a;
                    minb = b;
                    minc = c;
                }
            }
        }
        cout << mins * 2 << ' ' << mina << ' ' << minb << ' ' << minc << '\n';
    }
    return 0;
}