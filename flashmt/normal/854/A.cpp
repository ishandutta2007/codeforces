#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int x = n / 2; x; x--)
        if (x < n - x && __gcd(x, n - x) == 1)
        {
            cout << x << ' ' << n - x << endl;
            return 0;
        }
}