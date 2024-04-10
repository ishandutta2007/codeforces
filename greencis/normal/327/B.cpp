#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 1) cout << 1;
    else if (n == 2) cout << "2 3";
    else {
        for (int i = 0; i < n; ++i)
            cout << 3*n + i << " ";
    }
    return 0;
}