#include <iostream>
#include <string>

using namespace std;

string s1, s2;
const long long mod = 1e9 + 7;
long long n, k, ans, p, p2, a, b;
bool eq;

int main(void)
{
    cin >> s1 >> s2 >> k;
    p = n = s1.length();
    eq = s1 == s2;
    if (!eq)
    {
        bool flag = false;
        for (int i = 1; i < n; ++i)
            if (s1.substr(i, n - i) + s1.substr(0, i) == s2)
            {
                flag = true;
                break;
            }
        if (!flag)
        {
            cout << 0;
            return 0;
        }
    }
    for (int i = 1; i <= n / 2; ++i)
    {
        if (n % i == 0)
        {
            p = i;
            for (int j = i; j < n; ++j)
                if (s1[j] != s1[j - i])
                {
                    p = n;
                    break;
                }
        }
        if (p != n)
            break;
    }
    p2 = n / p;
    if (eq)
    {
        a = 1;
        b = 0;
    }
    else
    {
        a = 0;
        b = 1;
    }
    long long newa;
    for (int i = 0; i < k; ++i)
    {
        newa = (a * (p2 - 1) + b * p2) % mod;
        b = (a * (n - p2) + b * (n - p2 - 1)) % mod;
        a = newa;
    }
    cout << a;
    return 0;
}