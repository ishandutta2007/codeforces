#include <iostream>

using namespace std;

int main()
{
    long long t, s, q, n = 0;
    cin >> t >> s >> q;
    while (s < t)
    {
        s *= q;
        n++;
    }
    cout << n;
}