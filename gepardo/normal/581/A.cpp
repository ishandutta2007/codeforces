#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int c = min(a, b), d = a + b - (c * 2);
    cout << c << " " << d / 2;
}