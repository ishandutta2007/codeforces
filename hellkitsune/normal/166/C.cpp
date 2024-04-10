#include <iostream>

using namespace std;

int main(void)
{
    int n, x, i, j, l, r, answ = 0;;
    int p[501];
    cin >> n >> x;
    for (i = 1; i <= n; ++i)
        cin >> p[i];
    for (i = 1; i <= n; i++)
        for (j = 1; j < n; j++)
            if (p[j] > p[j + 1])
            {
                p[j] ^= p[j + 1];
                p[j + 1] = p[j] ^ p[j + 1];
                p[j] ^= p[j + 1];
            }
    l = 1;
    while ((l <= n) && (p[l] < x))
        ++l;
    r = n;
    while ((r >= 0) && (p[r] > x))
        --r;
    while ((l > (n + 1) / 2) || (r < (n + 1) / 2))
    {
        ++n;
        ++r;
        ++answ;
    }
    cout << answ;
    return 0;
}