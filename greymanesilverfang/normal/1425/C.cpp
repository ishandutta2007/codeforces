#include <cstdio>
const int MOD = 1000000007,
          inv2 = (MOD+1)/2, 
          inv3 = (MOD+1)/3, 
          inv4 = (MOD+1)/4, 
          inv6 = (MOD+1)/6, 
          inv72 = (MOD+1)/72;
const int magic3[3] = {0, -32, -16},
          magic6[6] = {-16, 36, -32, 20, 0, 4};

int _add(int x) { return x < MOD ? x : x - MOD; }
int add(int x, int y) { return _add(x + y); }
int _sub(int x) { return x < 0 ? x + MOD : x; }
int sub(int x, int y) { return _sub(x - y); }
int mul(int x, int y) { return 1LL * x * y % MOD; }

int f4(int x)
{
    int res = mul(x + 6, mul(x, x));
    if (x % 2 == 0)
        res = add(res, MOD + magic3[x / 2 % 3]);
    else 
        res = add(res, add(mul(9, x), MOD + magic6[(x - 1) / 2 % 6]));
    res = mul(inv72, res);
    return res;
}

int f3(int x, int y)
{
    int res = mul(inv6, mul(add(x, y) + 4, mul(x + 1, y + 1)));
    if (x % 3 + y % 3 < 2)
        res = sub(res, mul(2, inv3));
    return res;
}

int f2(int x, int y)
{
    int res = mul(inv4, mul(y + 1, mul(x, x + 4)));
    if (x % 2 == 1)
    {
        res = add(res, mul(inv4, y + 1));
        if (y % 2 == 0)
            if (x % 4 == 1)
                res = sub(res, inv2);
            else 
                res = add(res, inv2);
    }
    return res;
}

int f(int x, int y)
{
    if (x < y)
        return f(y, x);
    --x; --y;
    int res = 0;
    if (y < x / 2)
    {
        res = add(res, f2(x, y));
        x = y * 2;
        res = sub(res, f2(x, y));
    }
    res = add(res, add(f3(x, y), add(f4(x), f4(y))));
    return res;
}

int solve()
{
    int x, y, n, m; scanf("%d%d%d%d", &x, &y, &n, &m);
    --x; --y;
    int res = sub(add(f(n, m), f(x, y)), add(f(x, m), f(n, y)));
    if (x == 2 && y == 2)
        res = add(res, 2);
    return res;
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; ++i)
        printf("%d\n", solve());
}