#include<bits/stdc++.h>

using namespace std;

int Ans = 0, K, KM, sub2, sub3, sub6, s[7][1100000];
long long M;
const int mod = 1e9 + 7;

long long add (long long x, long long y) {return (x + y) % mod;}
long long mul (long long x, long long y) {return (1LL * x * y) % mod;}
long long subtract (long long x, long long y) {long long ans = (x - y) % mod; if (ans < 0) ans += mod; return ans;}
//int add (int x, int y) {int ans = x + y; if (ans >= mod) ans -= mod; return ans;}
//int subtract (int x, int y) {if (x >= y) return x - y; return x - y + mod;}
//int mul (int x, int y) {return 1LL * x * y % mod;}
//void adto (int &x, int y) {x += y; if (x >= mod) x -= mod;}
void adto (int &x, long long y) {x = (x + y) % mod;}

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

int f (long long P)
{
    int curr = (P - 1) % mod;
    curr = mul (curr, P % mod);
    curr = mul (curr, (P + 1) % mod);
    curr = mul (curr, sub3);
    int curr2 = (P - 1) % mod;
    curr2 = mul (curr2, P % mod);
    curr2 = mul (curr2, (M - P + 1) % mod);
    adto (curr, curr2);
    return subtract (K, curr);
}

int sum3 (int x, int y)
{
    int p2 = mul (x, x), ans = 0;
    ans = mul (p2, mul (p2, p2)), ans = mul (ans, y);
    adto (ans, s[6][y]);

    int curr = mul (p2, p2);
    curr = mul (curr, 3);
    curr = mul (curr, s[2][y]);
    adto (ans, curr);

    curr = mul (p2, s[4][y]);
    curr = mul (curr, 3);
    adto (ans, curr);
/*    int ans = 0;
    for (int i=1; i<=y; i++)
    {
        int curr = x * x + i * i;
        adto (ans, mul (curr, mul (curr, curr)));
    }
    return ans;*/
    return ans;
}

int sum2 (int x, int y)
{
    assert (x <= 1000000 && y <= 1000000);
    int ans = mul (x, x);
    ans = mul (ans, ans);
    ans = mul (ans, y);
    int curr = mul (x, x);
    curr = mul (curr, 2);
    curr = mul (curr, s[2][y]);
    adto (ans, curr);
    adto (ans, s[4][y]);
    /*int ans = 0;
    for (int i=1; i<=y; i++)
    {
        int curr = x * x + i * i;
        adto (ans, mul (curr, curr));
    }*/
    return ans;
}

int sum1 (int x, int y)
{
    int ans = add (mul (y, mul (x, x)), s[2][y]);
    /*for (int i=1; i<=y; i++)
    {
        int curr = x * x + i * i;
        adto (ans, curr);
    }*/
    return ans;
}

int getSum (int x, int y)
{
/*    int ans = 0;
    for (int i=1; i<=y; i++)
        adto (ans, subtract (K, f (x * x + i * i)));
    return ans;*/
    int s1 = sum1 (x, y), s2 = sum2 (x, y), s3 = sum3 (x, y);
    int curr = mul (KM, subtract (s2, s1));
    adto (curr, mul (sub3, subtract (s3, s1)));
    int curr2 = add (s3, s1);
    curr2 = subtract (curr2, add (s2, s2));
    return subtract (curr, curr2);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%I64d", &M), sub2 = power (2, mod - 2), sub3 = power (3, mod - 2), sub6 = mul (sub2, sub3);
K = KM = M % mod;
K = mul (K, (M + 1) % mod);
K = mul (K, (M + 2) % mod);
K = mul (K, sub3);

for (int i=1; i<=1001000; i++)
{
    int val = 1;
    for (int e = 1; e<=6; e++)
    {
        val = mul (val, i);
        s[e][i] = add (s[e][i - 1], val);
    }
}

int y = 0;
while (1LL * (y + 1) * (y + 1) <= M) y ++;
for (int x=0; 1LL * x * x<=M; x++)
{
    while (1LL * y * y + 1LL * x * x > M) y --;
    int curr = getSum (x, y);

//    for (int i=1; i<=y; i++)
  //      adto (curr, f (x * x + i * i));
    curr = subtract (mul (K, y), curr);

    curr = add (curr, curr);
    adto (curr, f (1LL * x * x));
    if (x != 0) curr = add (curr, curr);
    adto (Ans, curr);
}

Ans = mul (Ans, sub2);
printf ("%d\n", Ans);

return 0;
}