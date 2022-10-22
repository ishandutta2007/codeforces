#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

bool ok(int n, int k, string s)
{
    for (int i = 0; i < k; i++)
    {
        int c0 = 0, c1 = 0;
        for (int j = i; j < n; j += k)
        {
            if (s[j] == '0')
            {
                c0++;
            }
            if (s[j] == '1')
            {
                c1++;
            }
        }
        if (c0 && c1)
        {
            return 0;
        }
        for (int j = i; j < n; j += k)
        {
            if (c0)
            {
                s[j] = '0';
            }
            if (c1)
            {
                s[j] = '1';
            }
        }
    }
    n = k;
    int c0 = 0, c1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            c0++;
        }
        if (s[i] == '1')
        {
            c1++;
        }
    }
    return (c0 <= n / 2 && c1 <= n / 2);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen ("input", "r", stdin);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        string s;
        cin >> n >> k >> s;
        if (ok(n, k, s))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}