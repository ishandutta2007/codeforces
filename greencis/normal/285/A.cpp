#include <iostream>

using namespace std;

int n,k;

int main()
{
    cin >> n >> k;

    if (k == 0) {
        for (int i = 0; i < n; ++i)
            cout << i+1<<" ";
        return 0;
    }
    cout << n << " ";
    for (int i = k; i > 0; --i)
        cout << i << " ";
    for (int i = k+1; i < n; ++i)
        cout << i << " ";
    return 0;
}