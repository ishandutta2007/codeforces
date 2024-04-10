#include <iostream>

using namespace std;

int main(void)
{
    const unsigned int modulo = 1000000007;
    unsigned int a = 0, d = 1, na;
    int n, i;
    cin >> n;
    for (i = 0; i < n; ++i)
    {
        na = (d + 2 * a) % modulo;
        d = (a * 3) % modulo;
        a = na;
    }
    cout << d;
    return 0;
}