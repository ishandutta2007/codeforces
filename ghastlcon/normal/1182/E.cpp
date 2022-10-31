#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 6
#define MOD 1000000007
#pragma GCC optimize("O3")
using namespace std;

class Matrix
{
public:
    int n, m;
    int x[N][N];

    Matrix(int _n = 0, int _m = 0, int _x = 0) : n(_n), m(_m)
    {
        int i, j;

        for(i = 0; i < n; i ++)
            for(j = 0; j < m; j ++)
                x[i][j] = _x;

        return;
    }

    Matrix operator*(const Matrix &that) const
    {
        int i, j, k, t;
        Matrix r;

        if(m != that.n)
            return Matrix();

        r = Matrix(n, that.m);
        for(i = 0; i < n; i ++)
            for(j = 0; j < that.m; j ++)
            {
                for(k = t = 0; k < m; k ++)
                    t = (t + (long long)x[i][k] * that.x[k][j] % (MOD - 1)) % (MOD - 1);
                r.x[i][j] = t;
            }

        return r;
    }

    Matrix &operator*=(const Matrix &that)
    {
        return (*this) = (*this) * that;
    }
};

const int d[N][N] = 
{
    {1, 1, 1, 0, 1, 0},
    {1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 2},
    {0, 0, 0, 0, 0, 1},
};

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

Matrix Mtpow(Matrix x, long long y)
{
    Matrix o;
    int i;

    o = Matrix(N, N);
    for(i = 0; i < N; i ++)
        o.x[i][i] = 1;
    for(; y; y >>= 1)
    {
        if(y & 1)
            o *= x;
        x *= x;
    }

    return o;
}

int main(void)
{
    long long n;
    int f1, f2, f3, f4, c;
    int i, j;
    Matrix k;

    cin >> n >> f1 >> f2 >> f3 >> c;
    k = Matrix(N, N);
    for(i = 0; i < N; i ++)
        for(j = 0; j < N; j ++)
            k.x[i][j] = d[i][j];
    k = Mtpow(k, n - 4);
    f4 = (long long)c * c % MOD * f1 % MOD * f2 % MOD * f3 % MOD;

    long long fn=1;
    fn=fn*(long long)Power(f4,k.x[0][0])%MOD;
    fn=fn*(long long)Power(f3,k.x[0][1])%MOD;
    fn=fn*(long long)Power(f2,k.x[0][2])%MOD;
    fn=fn*(long long)Power(f1,k.x[0][3])%MOD;
    fn=fn*(long long)Power((long long)c*c%MOD,k.x[0][4]*2)%MOD;
    fn=fn*(long long)Power(c,k.x[0][5])%MOD;
    cout<<fn<<endl;

    return 0;
}