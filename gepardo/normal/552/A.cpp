#include <iostream>
using namespace std;

int main()
{
    int n, a, b, c, d, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c >> d;
        sum += (d - b + 1) * (c - a + 1);
    }
    cout << sum;
}