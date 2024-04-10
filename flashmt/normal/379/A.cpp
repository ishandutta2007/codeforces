#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, ans = 0, left = 0;
    cin >> a >> b;
    while (a)
    {
        ans += a;
        left += a;
        a = left / b;
        left -= a * b;
    }
    cout << ans << endl;
}