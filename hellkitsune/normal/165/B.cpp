#include <iostream>

using namespace std;

long long n, k;

long long bs(int l, int r)
{
    long long m, t, kk;
    while (l < r)
    {
        m = (l + r) / 2;
        t = n;
        kk = 1;
        while (m / kk)
        {
            t -= m / kk;
            kk *= k;
        }
        if (t <= 0)
            r = m;
        else
            l = m + 1;
    }
    return l;
}

int main(void)
{
    cin >> n >> k;
    cout << bs(1, n);
    return 0;
}