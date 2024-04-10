#include<cstdio>
#include<cstring>
#include<algorithm>
#define baza 10000

using namespace std;

int nr, sum, mod;
long long N, M;

int get_sum (long long a, long long b)
{
    long long f1 = a + b, f2 = b - a + 1;
    if (f1 & 1LL) f2 >>= 1LL;
    else f1 >>= 1LL;
    return (1LL * (f1 % mod) * (f2 % mod)) % mod;
}

long long brute (long long a, long long b)
{
    long long sum = 0;
    for (long long i=1; i<=b; i++)
        sum += a % i;
    return sum;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%I64d %I64d", &N, &M), mod = 1e9 + 7;

//long long real_ans = brute (N, M);

if (M > N)
{
    sum = (1LL * ((M - N) % mod) * (N % mod)) % mod;
    M = N;
}
else sum = 0;

for (long long i=1; i <= N && i <= M; i ++)
{
    ///d[i + 1] > N / x >= d[i]
    ///N >= x * d[i]
    ///N / d[i] >= x
    ///N / d[i + 1] < x
    long long curr = N / i;
    long long left = i, right = N / curr;
//    printf ("%I64d %I64d  ->  %I64d\n", left, right, curr);
    if (left > M) break;
    if (right > M)
        right = M;
    ///N / x = curr pentru x de la left la right
    ///N % x = N - curr * x
    ///suma = N * (right - left + 1) - curr * (left + left + 1 + ... + right)
        sum = ((long long)
sum + (1LL * (N % mod) * ((right - left + 1) % mod)) % mod
               - (1LL * (curr % mod) * get_sum (left, right)) % mod + mod) % mod;
    i = right;
}
printf ("%d\n", sum);
return 0;
}