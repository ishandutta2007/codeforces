#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int a[5555], n, g[5555], p, badPrimes[5555], best[5555];
set <int> isBadPrime;
vector <int> primes;

int f(int n)
{
    int res = 0;
    for (int i = 0; i < int(primes.size()) && primes[i] * primes[i] <= n; i++)
        while (n % primes[i] == 0)
        {
            n /= primes[i];
            if (isBadPrime.count(primes[i])) res--;
            else res++;
        }
    
    if (n == 1) return res;
    if (isBadPrime.count(n)) return res - 1;
    return res + 1;
}

int main()
{
    cin >> n >> p;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < p; i++) cin >> badPrimes[i], isBadPrime.insert(badPrimes[i]);
    
    g[0] = a[0];
    for (int i = 1; i < n; i++) g[i] = __gcd(g[i - 1], a[i]);
    
    for (int i = 2; i * i <= 1000000000; i++)
    {
        int isPrime = 1;
        for (int j = 2; j * j <= i; j++)
            if (i % j == 0)
            {
                isPrime = 0;
                break;
            }
        if (isPrime) primes.push_back(i);
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) ans += f(a[i]);
    
    int maxBest = 0;
    g[n] = 1;
    best[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        best[i] = -oo;
        for (int j = i + 1; j <= n; j++)
            best[i] = max(best[i], best[j] - f(g[i] / g[j]) * (i + 1));
        maxBest = max(maxBest, best[i]);
    }
    
    cout << ans + maxBest << endl;
}