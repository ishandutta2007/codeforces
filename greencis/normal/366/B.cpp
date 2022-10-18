#include <iostream>

using namespace std;

int n,k,a[100100];

int main()
{
    cin >> n >> k;
    int t;
    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        a[i%k] += t;
    }

    int mn = 1e9, mni = -1;
    for (int i = 0; i < k; ++i) {
        if (a[i] < mn) {
            mn = a[i];
            mni = i+1;
        }
    }

    cout << mni;

    return 0;
}