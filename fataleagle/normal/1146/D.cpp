#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;
long long m, a, b;
int s[10000001];
int f[10000001];

long long sumdiv(long long n, long long d)
{
    long long ret = 0;
    while (n % d != 0)
    {
        ret += n / d;
        n--;
    }
    if (n == 0)
    {
        return ret;
    }
    ret += n / d;
    n--;
    long long q = n/d;
    ret += 1LL * q * (q + 1) / 2 * d;
    return ret;
}

int main()
{
    cin >> m >> a >> b;
    long long n = a + b;
    n *= 2;
    priority_queue<int, vector<int>, greater<int>> Q;
    Q.push(0);
    s[0] = 1;
    f[0] = 0;
    for (long long i = 0; i <= n; i++)
    {
        f[i] = i;
    }
    while (!Q.empty())
    {
        int x = Q.top();
        Q.pop();
        if (x - b >= 0 && !s[x - b])
        {
            s[x - b] = 1;
            f[x - b] = max(f[x - b], f[x]);
            Q.push(x - b);
        }
        if (x + a <= n && !s[x + a])
        {
            s[x + a] = 1;
            f[x + a] = max(f[x + a], f[x]);
            Q.push(x + a);
        }
    }
    long long ans = 0;
    for (long long i = 0; i <= n; i++)
    {
        if (s[i])
        {
            //printf("%lld %d\n", i, f[i]);
            ans += max(0LL, min(m, n) - f[i] + 1);
        }
    }
    if (n < m)
    {
        ans += m - n;
        int g = __gcd(a, b);
        ans += sumdiv(m, g);
        ans -= sumdiv(n, g);
    }
    cout << ans << endl;
 }