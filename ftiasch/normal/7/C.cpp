// Codeforces Beta Round #7
// Problem C -- Line
#include <iostream>

using namespace std;

long long a, b, c;

long long gcd(long long a, long long b, long long &x, long long &y)
{
    if(b)
    {
        long long xx, yy, dd = gcd(b, a % b, xx, yy);
        x = yy, y = xx - (a / b) * yy;
        return dd;
    }
    else
    {
        x = 1, y = 0;
        return a;
    }
}

int main()
{
    cin >> a >> b >> c;
    long long x, y, d = gcd(a, b, x, y);
    if(c % d == 0)
        cout << - x * (c / d) << " " << - y * (c / d) << "\n";
    else
        cout << -1 << "\n";
    return 0;
}