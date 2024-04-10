#include <cstdio>
#include <vector>
struct Data 
{
    long long x, y;
    char type;
};
std::vector<Data> res;

long long sum(long long x, long long y)
{
    res.push_back({x, y, '+'});
    return x + y;
}

long long xum(long long x, long long y)
{
    res.push_back({x, y, '^'});
    return x ^ y;
}

void solve(long long x)
{
    const int N = 22;
    long long p[N];
    p[0] = x;
    long long y = x;
    for (int i = 1; 1 << i <= x; ++i)
    {
        p[i] = sum(p[i - 1], p[i - 1]);
        if (y & 1 << i)
            y = xum(y, p[i]);
    }
    p[1] = xum(sum(x, y), xum(x, y));
    for (int i = 2; 1 << i <= x; ++i)
    {
        p[i] = sum(p[i - 1], p[i - 1]);
        if (x & 1 << i)
            x = xum(x, p[i]);
    }
}

int main()
{
    long long x; scanf("%lld", &x);
    solve(x & 2 ? xum(x, sum(x, x)) : x);
    printf("%d\n", res.size());
    for (Data d : res)
        printf("%lld %c %lld\n", d.x, d.type, d.y);
}