#include <bits/stdc++.h>

using namespace std;

unsigned long long f(unsigned long long x, int b)
{
    for(int i=0; i<64; i++)
        if(__builtin_popcountll(x)<b)
            x|=1ULL<<i;
    return x;
}

unsigned long long brute(unsigned long long l, unsigned long long r)
{
    unsigned long long ret=l;
    for(unsigned long long i=l; i<=r; i++)
        if(__builtin_popcountll(i)>__builtin_popcountll(ret))
            ret=i;
    return ret;
}

int main()
{
    int T;
    scanf("%d", &T);
    unsigned long long a, b;
    while(T--)
    {
        scanf("%llu%llu", &a, &b);
        unsigned long long ans=a;
        for(int i=__builtin_popcountll(a)+1; i<64; i++)
        {
            unsigned long long v=f(a, i);
            if(v<=b)
                ans=v;
        }
        printf("%lld\n", ans);
    }
    return 0;
}