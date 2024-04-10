#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int a[2];
        int b[2];
        int n;
        string s;
        cin >> n >> s;
        a[0] = a[1] = 0;
        b[0] = b[1] = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                a[(s[i] - '0') % 2]++;
            }
            else
            {
                b[(s[i] - '0') % 2]++;
            }
        }
        /// first player wants a 1, second player wants 0
        if (n % 2 == 1) /// last = first player
        {
            if (a[1])
            {
                cout << "1\n";
            }
            else
            {
                cout << "2\n";
            }
        }
        else /// last = second player
        {
            if (b[0])
            {
                cout << "2\n";
            }
            else
            {
                cout << "1\n";
            }
        }
    }

}