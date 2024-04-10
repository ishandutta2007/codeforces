#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    if (a == b)
    {
        cout << a;
        return 0;
    }
    int k1 = (a - b) / (2 * b), k2 = (a + b) / (2 * b);
    long double x1, x2, x;
    if (k1 <= 0) x1 = -1; else x1 = (long double) (a - b) / (long double) (2 * k1);
    if (k2 <= 0) x2 = -1; else x2 = (long double) (a + b) / (long double) (2 * k2);
    if (x1 < 0) x = x2; else if (x2 < 0) x = x1; else x = min(x1, x2);
    if (x < 0) cout << "-1"; else cout << setprecision(10) << x;
    return 0;
}