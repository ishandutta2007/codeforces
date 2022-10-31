#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#define N 524289
#define M 19
#define K 3000020
#define MOD 998244353
using namespace std;

class Polynomial
{
public:
    vector<int> v;

    Polynomial(int _n = 0)
    {
        v = vector<int>(_n, 1);

        return;
    }

    bool operator<(const Polynomial &that) const
    {
        return this -> v.size() > that.v.size();
    }

    Polynomial operator*(Polynomial &that);
};

int a[K];
int w[N], r[N];
priority_queue<Polynomial> q;

inline int Mod(int x)
{
    return x + ((x >> 31) & MOD);
}

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

int InitNTT(int n)
{
    int i, j, c;

    for(c = 0; (1 << c) < n; c ++)
        ;
    if(!w[0])
    {
        for(i = 0; i < (1 << M); i ++)
            for(j = 0; j < M; j ++)
                if(i & (1 << j))
                    r[i] |= 1 << (M - j - 1);
        w[0] = 1;
        w[1] = Power(3, (MOD - 1) >> M);
        for(i = 2; i < (1 << M); i ++)
            w[i] = (long long)w[i - 1] * w[1] % MOD;
    }

    return c;
}

void NTT(int *f, int n)
{
    int i, j, l;
    int k;

    for(i = 0; i < (1 << n); i ++)
        if(i < (r[i] >> (M - n)))
            swap(f[i], f[r[i] >> (M - n)]);
    for(l = 0; l < n; l ++)
        for(i = 0; i < (1 << n); i += 2 << l)
            for(j = 0; j < (1 << l); j ++)
            {
                k = (long long)f[i + j + (1 << l)] * w[j << (M - l - 1)] % MOD;
                f[i + j + (1 << l)] = Mod(f[i + j] - k);
                f[i + j] = Mod(f[i + j] + k - MOD);
            }

    return;
}

void DFT(int *f, int n)
{
    NTT(f, n);

    return;
}

void IDFT(int *f, int n)
{
    int i, k;

    reverse(f + 1, f + (1 << n));
    NTT(f, n);

    k = Mod(-((MOD - 1) >> n));
    for(i = 0; i < (1 << n); i ++)
        f[i] = (long long)f[i] * k % MOD;

    return;
}

Polynomial Polynomial::operator*(Polynomial &that)
{
    static int a[N], b[N];
    int i, n, c;
    Polynomial o;

    n = (signed)this -> v.size() + (signed)that.v.size() - 1;
    c = InitNTT(n);
    for(i = 0; i < (1 << c); i ++)
        a[i] = b[i] = 0;
    for(i = 0; i < (signed)this -> v.size(); i ++)
        a[i] = this -> v[i];
    for(i = 0; i < (signed)that.v.size(); i ++)
        b[i] = that.v[i];

    DFT(a, c);
    DFT(b, c);
    for(i = 0; i < (1 << c); i ++)
        a[i] = (long long)a[i] * b[i] % MOD;
    IDFT(a, c);
    o.v.assign(a, a + n);

    return o;
}

int main(void)
{
    int n, v;
    int i;
    Polynomial x, y;

    scanf("%d", &n);
    for(i = 0; i < n; i ++)
    {
        scanf("%d", &v);
        a[v] ++;
    }
    for(i = 0; i < K; i ++)
        if(a[i])
            q.push(Polynomial(a[i] + 1));

    while(q.size() > 1)
    {
        x = q.top();
        q.pop();
        y = q.top();
        q.pop();
        q.push(x * y);
    }
    printf("%d\n", q.top().v[n >> 1]);

    return 0;
}