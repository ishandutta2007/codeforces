#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int f[300000];
vector < pair <int, int> > v;
int cnt[3000];
const int mod = (int)1e9 + 7;

inline int getInt()
{
    signed n;
    scanf("%d", &n);
    return n;
}

inline int rev(int a)
{
    int p = mod-2;
    int res = 1;
    while (p)
    {
        if (p & 1) res = (1LL * res * a) % mod;
        a = (1LL * a * a % mod);
        p >>= 1;
    }
    return res;
}

main()
{
    f[0] = 1;
    for (int i = 1; i < 210000; i++) f[i] = (1LL * f[i-1] * i) % mod;

    int t = 1;//getInt();

    for (int q = 0; q < t; q++)
    {
        int n = getInt(), m = getInt(), k = getInt();
        v.resize(k+1);

        for (int i = 0; i < k; i++)
        {
            int a = getInt(), b = getInt();
            v[i] = make_pair(a, b);
        }
        v[k] = make_pair(n, m);
        sort(v.begin(), v.end());

        for (int i = 0; i <= k; i++)
        {
            int n = v[i].first, m = v[i].second;
            cnt[i] = (1LL * f[n + m - 2] * rev((1LL * f[n - 1] * f[m - 1]) % mod)) % mod;
            for (int j = 0; j < i; j++)
            {
                int q, n = v[i].first - v[j].first + 1, m = v[i].second - v[j].second + 1;
                if (n < 1 || m < 1) continue;
                q = ((1LL * f[n + m - 2] * rev((1LL * f[n - 1] * f[m - 1]) % mod)) % mod * cnt[j]) % mod;
                cnt[i] = (cnt[i] + mod - q) % mod;
            }
        }
        printf("%d\n", cnt[k]);
    }
    return 0;
}