#include <iostream>

using namespace std;

int main(void)
{
    int n, d;
    cin >> n;
    cout << n;
    for (d = 2; d * d <= n; ++d)
        while (n % d == 0)
        {
            n = n / d;
            cout << ' ' << n;
        }
    if (n > 1)
        cout << " 1";
    return 0;
}