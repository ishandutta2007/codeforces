#include <iostream>
#include <iomanip>

using namespace std;

typedef long double ld;

ld* combine(ld* a, ld* b)
{
    ld* res = new ld[128];
    for (int i = 0; i < 128; i++) res[i] = 0;

    for (int i = 0; i < 128; i++)
        for (int j = 0; j < 128; j++)
            res[i ^ j] += a[i] * b[j];

    return res;
}

ld* bin_pow(ld* a, int p)
{
    ld* res = new ld[128];
    for (int i = 0; i < 128; i++) res[i] = 0;
    res[0] = 1;
    while (p)
    {
        if (p & 1) res = combine(res, a);
        a = combine(a, a);
        p >>= 1;
    }
    return res;
}

int main()
{
    int n, x; cin >> n >> x;
    ld* a = new ld[128];
    for (int i = 0; i < 128; i++) a[i] = 0;
    for (int i = 0; i <= x; i++) cin >> a[i];
    a = bin_pow(a, n);
    cout << fixed << setprecision(10) << 1 - a[0] << endl;
}