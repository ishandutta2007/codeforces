#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

const int maxn = 250100;
const int inf = 1e9;
int mod = 1e9 + 7;

int add(int a, int b)
{
    a += b;
    if(a >= mod) a -= mod;
    if(a < 0) a += mod;
    return a;
}

int mult(int a, int b)
{
    return (long long) a * b % mod;
}

int pot(int a, int b)
{
    int ret = 1;
    while(b)
    {
        if(b & 1) ret = mult(ret, a);
        b >>= 1;
        a = mult(a, a);
    }
    return ret;
}

int n;

int suma;

int fakt[maxn];

int main()
{
    cin >> n >> mod;
    fakt[0] = 1;
    REP(i, 1, maxn) fakt[i] = mult(fakt[i - 1], i);
    suma = 0;
    REP(i, 1, n + 1)
    {
        suma = add(suma, mult(mult(mult(n - (i - 1), n - (i - 1)), fakt[i]), fakt[n - i]));
    }
    cout << suma << endl;
    return 0;
}