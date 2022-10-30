#pragma GCC optimize("O3,inline,unroll-loops")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#define N 65536
#define M 16
#define K 4
#define MOD 1000000007
using namespace std;

string a;
int b[M];

inline int Mod(int x)
{
    return x + ((x >> 31) & MOD);
}

void FWT(vector<int> &f, int w)
{
    int i, j, l;

    for(l = 0; l < M; l ++)
        for(i = 0; i < N; i += 2 << l)
            for(j = 0; j < (1 << l); j ++)
                switch(w)
                {
                case 1:
                    f[i + j + (1 << l)] = Mod(f[i + j + (1 << l)] + f[i + j] - MOD);
                    break;

                case -1:
                    f[i + j + (1 << l)] = Mod(f[i + j + (1 << l)] - f[i + j]);
                    break;

                case 2:
                    f[i + j] = Mod(f[i + j] + f[i + j + (1 << l)] - MOD);
                    break;

                case -2:
                    f[i + j] = Mod(f[i + j] - f[i + j + (1 << l)]);
                    break;

                default:
                    throw;
                }

    return;
}

vector<int> DP(int l, int r)
{
    int i, j, t;
    vector<int> o, x, y, p, q;

    o.resize(N);
    if(l == r)
    {
        if(a[l] == '?')
            for(i = 0; i < N; i ++)
                for(t = 0; t < K; t ++)
                {
                    for(j = 0; j < M; j ++)
                        if((j & (1 << t) && ~i & (1 << j)) || (~j & (1 << t) && i & (1 << j)))
                            break;
                    o[i] += j == M;
                    for(j = 0; j < M; j ++)
                        if((j & (1 << t) && i & (1 << j)) || (~j & (1 << t) && ~i & (1 << j)))
                            break;
                    o[i] += j == M;
                }
        else if(isupper(a[l]))
            for(i = 0; i < N; i ++)
            {
                for(j = 0; j < M; j ++)
                    if((j & (1 << (a[l] - 'A')) && ~i & (1 << j)) || (~j & (1 << (a[l] - 'A')) && i & (1 << j)))
                        break;
                o[i] = j == M;
            }
        else if(islower(a[l]))
            for(i = 0; i < N; i ++)
            {
                for(j = 0; j < M; j ++)
                    if((j & (1 << (a[l] - 'a')) && i & (1 << j)) || (~j & (1 << (a[l] - 'a')) && ~i & (1 << j)))
                        break;
                o[i] = j == M;
            }
        else
            throw;

        return o;
    }

    for(i = l, t = 0; i <= r; i ++)
    {
        t += a[i] == ')' ? -1 : a[i] == '(';
        if(!t && a[i] != '(' && a[i] != ')')
        {
            t = i;
            break;
        }
    }

    // printf("midpoint (%d-%d) : %d\n", l, r, t);
    x = DP(l + 1, t - 2);
    y = DP(t + 2, r - 1);
    if(a[t] != '&')
    {
        p = x;
        q = y;
        FWT(p, 1);
        FWT(q, 1);
        for(i = 0; i < N; i ++)
            p[i] = (long long)p[i] * q[i] % MOD;
        FWT(p, -1);
        for(i = 0; i < N; i ++)
            o[i] = Mod(o[i] + p[i] - MOD);
    }
    if(a[t] != '|')
    {
        p = x;
        q = y;
        FWT(p, 2);
        FWT(q, 2);
        for(i = 0; i < N; i ++)
            p[i] = (long long)p[i] * q[i] % MOD;
        FWT(p, -2);
        for(i = 0; i < N; i ++)
            o[i] = Mod(o[i] + p[i] - MOD);
    }

    return o;
}

int main(void)
{
    int m;
    int i, j, x, t, o;
    vector<int> v;

    cin >> a;
    v = DP(0, (int)a.size() - 1);

    cin >> m;
    fill(b, b + M, -1);
    while(m --)
    {
        for(i = t = 0; i < K; i ++)
        {
            cin >> x;
            if(x)
                t |= 1 << i;
        }
        cin >> b[t];
    }

    for(i = o = 0; i < N; i ++)
    {
        for(j = 0; j < M; j ++)
            if(b[j] != -1 && b[j] != !!(i & (1 << j)))
                break;
        if(j == M)
            o = Mod(o + v[i] - MOD);
    }
    cout << o << endl;

    return 0;
}