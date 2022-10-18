#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;
        if (360 % (180 - q)) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}