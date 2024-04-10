#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;
typedef long long llong;

llong convChunk(llong v)
{
    if (v == 0)
        return 0;
    else if (v == 1)
        return 2;
    else if (v == 2)
        return 3;
    else if (v == 3)
        return 1;
}

llong convert(llong a, int chunks)
{
    llong pw = 1LL;
    int i;
    llong res = 0LL;

    for (i=1;i<=chunks;i++)
    {
        llong aChunk = a % 4LL;
        a /= 4LL;

        llong bChunk = convChunk(aChunk);

        res += bChunk * pw;
        pw *= 4LL;
    }

    return res;
}

int main()
{
    int n;
    int i,j;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        llong v;

        scanf("%lld",&v);
        v--;

        llong trip = v / 3LL + 1LL;
        llong offs = v % 3LL;

        int sideLen = 0;
        llong sz = 1LL;

        while(trip > sz)
        {
            trip -= sz;
            sz *= 4LL;
            sideLen += 2;
        }

        llong vA = trip - 1LL;
        llong vB = convert(vA, sideLen / 2);

        vA = (1LL << (llong)sideLen) | vA;
        vB = (2LL << (llong)sideLen) | vB;

        llong vC = vA ^ vB;

        if (offs == 0)
            printf("%lld\n",vA);
        else if (offs == 1)
            printf("%lld\n",vB);
        else
            printf("%lld\n",vC);
    }

    return 0;
}