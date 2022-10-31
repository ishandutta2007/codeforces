#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define N 1000020
using namespace std;

vector<int> v[N];

int Power(int x, int y, int p)
{
    int o;

    for(o = 1; y; y >>= 1)
    {
        if(y & 1)
            o = (long long)o * x % p;
        x = (long long)x * x % p;
    }

    return o;
}

int main(void)
{
    int a, b, p;
    long long n;
    int i, j, t;
    long long o;

    cin >> a >> b >> p >> n;
    for(i = 0; i < p - 1; i ++)
        v[(long long)b * Power(Power(a, i, p), p - 2, p) % p].push_back(i);
    for(i = 1, o = 0; i < p && i <= n; i ++)
    {
        t = (long long)i * Power(a, i, p) % p;
        for(j = 0; j < (signed)v[t].size(); j ++)
            if((n - i) / p >= v[t].at(j))
                o += ((n - i) / p - v[t].at(j)) / (p - 1) + 1;
    }
    cout << o << endl;

    return 0;
}