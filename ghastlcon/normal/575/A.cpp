#pragma GCC optimize("O3,inline,unroll-loops")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define N 50020
#define M 16
using namespace std;

extern int p;

extern inline int Mod(int);

class Matrix
{
public:
    int v[2][2];

    Matrix(void)
    {
        memset(v, 0, sizeof(v));

        return;
    }

    Matrix operator*(Matrix that)
    {
        Matrix o;

        o.v[0][0] = Mod((long long)this -> v[0][0] * that.v[0][0] % p + (long long)this -> v[0][1] * that.v[1][0] % p - p);
        o.v[0][1] = Mod((long long)this -> v[0][0] * that.v[0][1] % p + (long long)this -> v[0][1] * that.v[1][1] % p - p);
        o.v[1][0] = Mod((long long)this -> v[1][0] * that.v[0][0] % p + (long long)this -> v[1][1] * that.v[1][0] % p - p);
        o.v[1][1] = Mod((long long)this -> v[1][0] * that.v[0][1] % p + (long long)this -> v[1][1] * that.v[1][1] % p - p);
    
        return o;
    }

    Matrix operator^(long long y)
    {
        Matrix x, o;

        o.v[0][0] = o.v[1][1] = 1;
        for(x = *this; y; y >>= 1)
        {
            if(y & 1)
                o = o * x;
            x = x * x;
        }

        return o;
    }
};

int p;
int a[N];
pair<long long, int> b[N];
Matrix f[M][N], g;

inline int Mod(int x)
{
    return x + ((x >> 31) & p);
}

inline Matrix Form(int x, int y)
{
    Matrix o;

    o.v[0][1] = x;
    o.v[1][0] = 1;
    o.v[1][1] = y;

    return o;
}

Matrix Product(int l, int r)
{
    int i, p;
    Matrix o;

    o.v[0][0] = o.v[1][1] = 1;
    for(i = 0, p = l; i < M; i ++)
        if((r - l + 1) & (1 << i))
        {
            o = o * f[i][p];
            p += 1 << i;
        }

    return o;
}

Matrix Interval(long long l, long long r, int n)
{
    if(l / n == r / n)
        return Product(l % n, r % n);
    if(l / n + 1 == r / n)
        return Product(l % n, n - 1) * Product(0, r % n);

    return Product(l % n, n - 1) * (g ^ (r / n - l / n - 1)) * Product(0, r % n);
}

int main(void)
{
    long long k, q;
    int n, m;
    int i, j;
    Matrix o;

    ios::sync_with_stdio(false);
    cin >> k >> p >> n;
    if(k < 2)
    {
        cout << k % p << endl;

        return 0;
    }
    k -= 2;

    for(i = 0; i < n; i ++)
    {
        cin >> a[i];
        a[i] %= p;
        if(i)
            f[0][i - 1] = Form(a[i - 1], a[i]);
    }
    f[0][n - 1] = Form(a[n - 1], a[0]);

    for(i = 1; i < M; i ++)
        for(j = 0; j + (1 << i) - 1 < n; j ++)
            f[i][j] = f[i - 1][j] * f[i - 1][j + (1 << (i - 1))];
    g = Product(0, n - 1);

    cin >> m;
    for(i = 0; i < m; i ++)
    {
        cin >> b[i].first >> b[i].second;
        b[i].second %= p;
    }
    sort(b, b + m);
    for(i = 0; i < m; i ++)
        if(b[i].first == k)
            break;
    if(i == m)
    {
        b[m ++] = make_pair(k, a[k % n]);
        sort(b, b + m);
    }

    o.v[0][0] = o.v[1][1] = 1;
    for(i = 0; i < m; i ++)
    {
        q = i ? b[i - 1].first + 1 : 0;
        if(q <= b[i].first - 2)
            o = o * Interval(q, b[i].first - 2, n);

        if(!i || b[i - 1].first + 1 != b[i].first)
            o = o * Form(a[(b[i].first - 1) % n], b[i].second);
        if(i != m - 1 && b[i].first + 1 == b[i + 1].first)
            o = o * Form(b[i].second, b[i + 1].second);
        else
            o = o * Form(b[i].second, a[(b[i].first + 1) % n]);

        if(b[i].first == k)
            break;
    }
    cout << o.v[1][1] % p << endl;

    return 0;
}