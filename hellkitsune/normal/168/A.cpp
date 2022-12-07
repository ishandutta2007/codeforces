#include <iostream>

using namespace std;

int main(void)
{
    long long n, x, y, k;
    cin >> n >> x >> y;
    k = (n * y) / 100;
    while (k * 100 < n * y)
        ++k;
    while ((k - 1) * 100 >= n * y)
        --k;
    if (k > x)
        cout << k - x;
    else
        cout << 0;
    return 0;
}