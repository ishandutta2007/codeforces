#include <bits/stdc++.h>
using namespace std;
const int BASE = int(1e9) + 7;

long long fact[200200], invFact[200200], a[100100], d[111][100100];
int n;

long long power(long long x, int y)
{
    if (!y) return 1;
    long long res = power(x, y / 2);
    res = res * res % BASE;
    if (y % 2) res = res * x % BASE;
    return res;
}

long long c(int n, int k)
{
    if (k > n) return 0;
    return fact[n] * invFact[n - k] % BASE * invFact[k] % BASE;
}

void query(int l, int r, int k)
{
    for (int i = k; i >= 0; i--)
    {
        d[i][l] = (d[i][l] + c(k, i)) % BASE;
        d[i][r - i + 1] = (d[i][r - i + 1] + BASE - c(r - l + k - i, r - l)) % BASE;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    int m, l, r, k;
    
    fact[0] = 1;
    for (int i = 1; i <= 200000; i++) fact[i] = fact[i - 1] * i % BASE;
    for (int i = 0; i <= 200000; i++) invFact[i] = power(fact[i], BASE - 2);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    while (m--)
    {
        cin >> l >> r >> k;
        if (r - l < 105)
        {
            for (int i = l; i <= r; i++)
                a[i] = (a[i] + c(i - l + k, k)) % BASE;
        }
        else query(l, r, k);    
    }
    
    for (int i = 100; i >= 0; i--)
        for (int j = 1; j <= n; j++) d[i][j] = (d[i][j] + d[i][j - 1] + d[i + 1][j - 1]) % BASE;
        
    for (int i = 1; i <= n; i++) cout << (d[0][i] + a[i]) % BASE << ' ';
    cout << endl;
}