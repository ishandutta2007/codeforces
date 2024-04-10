#include <iostream>

using namespace std;

int main()
{
    char a, b; cin >> a >> b;
    bool rx = (a == 'a' || a == 'h'),
         ry = (b == '1' || b == '8');
    int ans = 8;
    if (rx || ry) ans = 5;
    if (rx && ry) ans = 3;
    cout << ans;
}