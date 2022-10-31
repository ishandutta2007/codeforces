#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <bitset>
#define N 200020
#define M 120
using namespace std;

bitset<N> f[M], g;
int s[N];

void Sieve(void)
{
    static bool u[N];
    int i, j;
    vector<int> v;

    for(i = 2; i < N; i ++)
        if(!u[i])
        {
            g[i] = true;
            v.push_back(i);

            if((long long)i * i < N)
                for(j = i; i * j < N; j ++)
                    u[i * j] = true;
        }
    // for(i=0;i<v.size();i++)cout<<v[i]<<" ";cout<<endl;

    for(i = 0; i < (signed)v.size(); i ++)
        for(j = i; j < (signed)v.size() && (long long)v[i] * v[j] < N; j ++)
            g[v[i] * v[j]] = true;

    return;
}

int main(void)
{
    int n, x, y, z;
    int i, o;

    Sieve();
    scanf("%d %d", &n, &x);
    g[x] = false;

    f[0] = g;
    for(i = 1; i < N; i ++)
    {
        for(; f[s[i]][i]; s[i] ++)
            ;
        f[s[i]] |= g << i;
    }

    for(o = 0; n --; )
    {
        scanf("%d %d %d", &x, &y, &z);
        o ^= s[y - x - 1] ^ s[z - y - 1];
    }
    printf("%s\n%s\n", o ? "Alice" : "Bob", o ? "Bob" : "Alice");

    return 0;
}