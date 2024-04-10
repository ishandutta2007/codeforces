#pragma GCC optimize("O3,inline,unroll-loops")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define N 4020
#define MOD 1000000007
using namespace std;

int f[N][N][2][2];

inline int Mod(int x)
{
    return x + ((x >> 31) & MOD);
}

inline void Modadd(int &x, int y)
{
    x = Mod(x + y - MOD);

    return;
}

int Modular(string &a, int b)
{
    string c;
    int i;
    long long t;

    c = string(a.size(), '0');
    for(i = t = 0; i < (signed)a.size(); i ++)
    {
        t = t * 10 + a[i] - 48;
        c[i] = t / b + 48;
        t %= b;
    }
    for(i = 0; i < (signed)c.size() && c[i] == '0'; i ++)
        ;
    a = c.substr(i);

    return (int)t;
}

int main(void)
{
    int p, k;
    string a;
    vector<int> b;
    int i, j, o;
    int w[6];

    cin >> p >> k >> a;
    while(!a.empty())
        b.push_back(Modular(a, p));
    reverse(b.begin(), b.end());
    // for(i=0;i<b.size();i++)cout<<b[i]<<' ';

    f[0][0][1][0] = 1;
    for(i = 0; i < (signed)b.size(); i ++)
    {
        w[0] = (long long)p * (p + 1) / 2 % MOD;
        w[1] = (long long)p * (p - 1) / 2 % MOD;
        w[2] = (long long)b[i] * (b[i] + 1) / 2 % MOD;
        w[3] = (long long)b[i] * (b[i] - 1) / 2 % MOD;
        w[4] = (long long)b[i] * (p + p - b[i] - 1) / 2 % MOD;
        w[5] = (long long)b[i] * (p + p - b[i] + 1) / 2 % MOD;

        for(j = 0; j <= i + 1; j ++)
        {
            Modadd(f[i + 1][j][0][0], (long long)f[i][j][0][0] * w[0] % MOD);
            Modadd(f[i + 1][j][0][0], (long long)f[i][j][1][0] * w[2] % MOD);
            Modadd(f[i + 1][j][0][1], (long long)f[i][j][0][0] * w[1] % MOD);
            Modadd(f[i + 1][j][0][1], (long long)f[i][j][1][0] * w[3] % MOD);

            Modadd(f[i + 1][j][1][0], (long long)f[i][j][1][0] * (b[i] + 1) % MOD);
            Modadd(f[i + 1][j][1][1], (long long)f[i][j][1][0] * b[i] % MOD);

            Modadd(f[i + 1][j + 1][0][0], (long long)f[i][j][0][1] * w[1] % MOD);
            Modadd(f[i + 1][j + 1][0][0], (long long)f[i][j][1][1] * w[4] % MOD);
            Modadd(f[i + 1][j + 1][0][1], (long long)f[i][j][0][1] * w[0] % MOD);
            Modadd(f[i + 1][j + 1][0][1], (long long)f[i][j][1][1] * w[5] % MOD);

            Modadd(f[i + 1][j + 1][1][0], (long long)f[i][j][1][1] * (p - b[i] - 1) % MOD);
            Modadd(f[i + 1][j + 1][1][1], (long long)f[i][j][1][1] * (p - b[i]) % MOD);
        }
    }

    for(i = k, o = 0; i <= (signed)b.size(); i ++)
        Modadd(o, Mod(f[b.size()][i][0][0] + f[b.size()][i][1][0] - MOD));
    cout << o << endl;

    return 0;
}