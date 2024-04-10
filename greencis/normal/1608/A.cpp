#include <iostream>

using namespace std;

int main()
{
    int ttt;
    cin >> ttt;
    while (ttt--) {

        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            cout << i + 2 << ' ';
        cout << '\n';
    }
}