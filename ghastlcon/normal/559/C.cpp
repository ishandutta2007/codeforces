#include <iostream>
#include <algorithm>
#include <cstdio>
#include <utility>
#define N 20200
#define M 200020
#define MOD 1000000007
using namespace std;

int Power(int, int);

namespace Comb
{
    int f[M], g[M];

    void Init(void)
    {
        int i;

        for(i = f[0] = 1; i < M; i ++)
            f[i] = (long long)i * f[i - 1] % MOD;
        g[M - 1] = Power(f[M - 1], MOD - 2);
        for(i = M - 2; i > -1; i --)
            g[i] = (long long)(i + 1) * g[i + 1] % MOD;
        
        return;
    }

    int C(int n, int m)
    {
        // printf("%d, %d\n", n, m); 
        return m > n ? 0 : (long long)f[n] * g[m] % MOD * g[n - m] % MOD;
    }
}

pair<int, int> a[N];
int f[N];

int Power(int x, int y)
{
    int o;

    for(o = 1; y; y >>= 1)
    {
        if(y & 1)
            o = (long long)o * x % MOD;
        x = (long long)x * x % MOD;
    }

    return o;
}

int main(void)
{
    int w, h, n;
    int i, j;

    Comb::Init();
    cin >> w >> h >> n;
    for(i = 1; i <= n; i ++)
        cin >> a[i].first >> a[i].second;
    a[++ n] = make_pair(w, h);
    sort(a + 1, a + n + 1);

    for(i = 1; i <= n; i ++)
    {
        f[i] = Comb::C(a[i].first + a[i].second - 2, a[i].first - 1);
        // printf("%d[%d, %d] : %d\n", i, a[i].first, a[i].second, f[i]);
        for(j = 1; j < i; j ++)
            if(a[i].second >= a[j].second)
                f[i] = ((f[i] - (long long)f[j] * Comb::C(a[i].first - a[j].first + a[i].second - a[j].second, a[i].first - a[j].first) % MOD) % MOD + MOD) % MOD;
    }
    cout << f[n] << endl;

    return 0;
}