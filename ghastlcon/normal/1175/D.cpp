#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 300020
using namespace std;

class Data
{
public:
    long long x;
    long long y;

    Data(long long _x = 0, long long _y = 0) : x(_x), y(_y)
    {
        return;
    }

    Data operator+(const Data &that) const
    {
        return Data(this -> x + that.x, this -> y + that.y);
    }

    bool operator<(const Data &that) const
    {
        return this -> x != that.x ? this -> x < that.x : this -> y > that.y;
    }
};

long long a[N];
Data f[N];
long long g[N];

void DP(long long n, long long k)
{
    long long i;
    Data v;

    f[n] = Data(a[n] + k, 1);
    for(i = n - 1; i >= 1; i --)
    {
        v = max(v, f[i + 1]);
        f[i] = v + Data(g[i] + k, 1);
    }

    return;
}

long long BSFind(long long n, long long k)
{
    long long l, m, r;

    for(l = -1000000000000, r = 1000000000000; l + 1 < r; )
    {
        m = (l + r) >> 1;
        DP(n, m);
        // printf("each add %I64d, will max %I64d, block %d\n", m, f[1].x, f[1].y);
        if(f[1].y <= k)
            l = m;
        else
            r = m;
    }

    // cout<<"ADD "<<l<<endl;
    DP(n, l);

    return f[1].x - l * k;
}

int main(void)
{
    long long n, k;
    long long i;

    scanf("%I64d %I64d", &n, &k);
    for(i = 1; i <= n; i ++)
        scanf("%I64d", &a[i]);
    for(i = n; i >= 1; i --)
        g[i] = g[i + 1] + a[i];
    printf("%I64d\n", BSFind(n, k));

    return 0;
}