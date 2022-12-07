#include <iostream>

using namespace std;

const int mod = (int)1e9 + 7;

struct mat
{
    long long a[2][2];
};

mat pow(mat p, long long k)
{
    if (k == 1)
        return p;
    mat res;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
        {
            res.a[i][j] = 0;
            for (int t = 0; t < 2; ++t)
                res.a[i][j] = (res.a[i][j] + p.a[i][t] * p.a[t][j]) % mod;
        }
    res = pow(res, k / 2);
    if (k % 2)
    {
        mat res2;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
            {
                res2.a[i][j] = 0;
                for (int t = 0; t < 2; ++t)
                    res2.a[i][j] = (res2.a[i][j] + res.a[i][t] * p.a[t][j]) % mod;
            }
        return res2;
    }
    return res;
}

int main(void)
{
    mat p;
    p.a[0][0] = 3; p.a[0][1] = 1;
    p.a[1][0] = 1; p.a[1][1] = 3;
    long long k;
    cin >> k;
    if (k == 0)
    {
        cout << 1 << endl;
        return 0;
    }
    p = pow(p, k);
    cout << p.a[0][0] % mod << endl;
    return 0;
}