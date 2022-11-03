#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << ((c == 0 && a == b) || (c != 0 && (b-a)%c == 0 && (b-a) / c >= 0) ? "YES" : "NO") << endl;
    return 0;
}