#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <functional>
#define N 100020
using namespace std;

namespace Sieve
{
    int p[N];
    bool u[N];
    int f[N];

    void Sieve(void)
    {
        int i, j, c;

        f[1] = 1;
        for(i = 2, c = 0; i < N; i ++)
        {
            if(!u[i])
            {
                p[c ++] = i;
                f[i] = -1;
            }
            for(j = 0; j < c && p[j] * i < N; j ++)
            {
                u[i * p[j]] = true;
                if(!(i % p[j]))
                    break;
                f[i * p[j]] = -f[i];
            }
        }

        return;
    }
}

int a[N];
vector<int> b[N], d[N];
int c[N];

long long Solve(vector<int> &a)
{
    int i, j, s;
    vector<int> f;
    long long o;

    for(i = o = 0; i < (signed)a.size(); i ++)
    {
        for(j = s = 0; j < (signed)d[a[i]].size(); j ++)
            s += Sieve::f[d[a[i]][j]] * c[d[a[i]][j]];
        // printf("select %d %llu\n", s, f.size());
        while(s)
        {
            if(__gcd(f.back(), a[i]) == 1)
            {
                s --;
                o = max(o, (long long)a[i] * f.back());
            }
            if(!s)
                break;

            for(j = 0; j < (signed)d[f.back()].size(); j ++)
                c[d[f.back()][j]] --;
            f.pop_back();
        }
        f.push_back(a[i]);
        for(j = s = 0; j < (signed)d[a[i]].size(); j ++)
            c[d[a[i]][j]] ++;
    }

    for(; !f.empty(); f.pop_back())
        for(i = 0; i < (signed)d[f.back()].size(); i ++)
            c[d[f.back()][i]] --;

    // printf("solving "); for(int xx : a) cout << xx << ' '; cout << endl << o << endl;

    return o;
}

int main(void)
{
    int n;
    int i, j;
    long long o;

    Sieve::Sieve();
    scanf("%d", &n);
    for(i = 0; i < n; i ++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    for(i = o = 0; i < n - 1; i ++)
        if(a[i] == a[i + 1])
            o = max(o, (long long)a[i]);
    n = (int)(unique(a, a + n) - a);

    for(i = 1; i < N; i ++)
        for(j = i; j < N; j += i)
            d[j].push_back(i);
    for(i = 0; i < n; i ++)
        for(j = 0; j < (signed)d[a[i]].size(); j ++)
            b[d[a[i]][j]].push_back(a[i]);

    for(i = 1; i < N; i ++)
        if(!b[i].empty())
        {
            sort(b[i].begin(), b[i].end(), greater<int>());
            for(j = 0; j < (signed)b[i].size(); j ++)
                b[i][j] /= i;
            o = max(o, Solve(b[i]) * i);
        }
    printf("%I64d\n", o);

    return 0;
}