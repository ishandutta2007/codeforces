#include <iostream>

using namespace std;

int main(void)
{
    long long n, m, a;
    cin >> n >> m >> a;
    n = n / a + (n % a > 0);
    m = m / a + (m % a > 0);
    cout << m * n;
    return 0;
}