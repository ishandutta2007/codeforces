#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, sz = 1 << 17;
const long long mod2 = 1LL * mod * mod;

int add (int x, int y) {int ans = x + y; if (ans >= mod) ans -= mod; return ans;}
int subtract (int x, int y) {if (x >= y) return x - y; return x - y + mod;}
int mul (int x, int y) {return 1LL * x * y % mod;}
void adto (int &x, int y) {x += y; if (x >= mod) x -= mod;}

int power (int a, int b)
{
    int p = 1;
    for (int i=0; (1<<i) <= b; i++)
    {
        if (b & (1 << i)) p = mul (p, a);
        a = mul (a, a);
    }
    return p;
}

void to_transform (int dim, int data[], int type)
{
    for (int len = 1; 2 * len <= dim; len <<= 1)
        for (int i = 0; i < dim; i += 2 * len)
            for (int j = 0; j < len; j++)
            {
                int u = data[i + j], v = data[i + len + j];
                if (type == 0)
                {
                    ///And
                    data[i + j] = v;
                    data[i + len + j] = add (u, v);
                    continue;
                }
                else
                if (type == 1)
                {
                    ///Xor
                    data[i + j] = add (u, v);
                    data[i + j + len] = subtract (u, v);
                    continue;
                }
            }
}

void inv_transform(int dim, int data[], int type)
{
    for (int len = 1; 2 * len <= dim; len <<= 1)
        for (int i = 0; i < dim; i += 2 * len)
            for (int j = 0; j < len; j++)
            {
                int u = data[i + j], v = data[i + len + j];
                if (type == 0)
                {
                    ///And
                    data[i + j] = subtract (v, u);
                    data[i + len + j] = u;
                    continue;
                }
                else
                if (type == 1)
                {
                    ///Xor
                    data[i + j] = add (u, v);
                    data[i + j + len] = subtract (u, v);
                    continue;
                }
            }
    if (type == 1)
    {
        int inv = power (dim, mod - 2);
        for (int i=0; i<dim; i++)
            data[i] = mul (data[i], inv);
    }
}

int N, aux[sz], data[sz], data3[sz], f[sz];
/*
int bru[sz];
void brute (int data[], int v[], bool type)
{
    for (int i=0; i<sz; i++)
        for (int j=0; j<sz; j++)
            if (type == 0)
                adto (v[i & j], mul (data[i], data[j]));
            else
                adto (v[i ^ j], mul (data[i], data[j]));
}*/

void doFirst (int data[], int v[])
{
    for (int i=0; i<sz; i++)
    {
        long long val = 0;
        for (int j=i;; j = (j - 1) & i)
        {
            val += 1LL * data[j] * data[i ^ j];
            if (val >= mod2) val -= mod2;
            if (j == 0) break;
        }
        v[i] = val % mod;
    }
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf("%d", &N);
for (int i=1; i<=N; i++)
{
    int x;
    scanf ("%d", &x);
    data[x] ++;
}
f[0] = 0, f[1] = 1;
for (int i=2; i<sz; i++)
    f[i] = add (f[i - 1], f[i - 2]);
memcpy (aux, data, sizeof (data));
doFirst (aux, data3);
to_transform(sz, data, 1);
for (int i=0; i<sz; i++) data[i] = mul (data[i], data[i]);
inv_transform(sz, data, 1);

for (int i=0; i<sz; i++)
    data3[i] = mul (data3[i], f[i]), data[i] = mul (data[i], f[i]), aux[i] = mul (aux[i], f[i]);
to_transform(sz, data, 0);
to_transform(sz, data3, 0);
to_transform(sz, aux, 0);
for (int i=0; i<sz; i++) data[i] = mul (data[i], mul (data3[i], aux[i]));
inv_transform(sz, data, 0);
int ans = 0;
for (int i=0; (1 << i) <sz; i++)
    adto (ans, data[1 << i]);
printf ("%d\n", ans);
return 0;
}