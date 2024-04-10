#include <algorithm>
#include <iostream>

long long F(long long, long long);

long long G(int x, int y)
{
    int i;
    long long o;

    if(!x || !y)
        return 1LL << (x | y);

    o = 1;
    for(i = 0; (x ^ y) >> i; i ++)
        if((x ^ y) & (1LL << i))
            o <<= 1LL << i;
    for(i = 0; (x & y) >> i; i ++)
        if((x & y) & (1LL << i))
            o = F(o, 3LL << ((1LL << i) - 1));

    return o;
}

long long F(long long x, long long y)
{
    int i, j;
    long long o;

    if(!x || !y)
        return x | y;
    if(x == 1 || y == 1)
        return std::max(x, y);

    o = 0;
    for(i = 0; x >> i; i ++)
        if(x & (1LL << i))
            for(j = 0; y >> j; j ++)
                if(y & (1LL << j))
                    o ^= G(i, j);

    return o;
}

int main(void)
{
    int t;
    long long n;
    int i, m;

    std::ios::sync_with_stdio(false);
    std::cin >> t;
    while(t --)
    {
        std::cin >> n;
        m = (n - 1) % 3;
        n = (n - 1) / 3;
        for(i = 0; n >= (1LL << i); i += 2)
            n -= 1LL << i;
        std::cout << F((1LL << i) + n, m + 1) << std::endl;
    }

    return 0;
}