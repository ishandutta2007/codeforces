#include <iostream>
using namespace std;

int n,a[100005],q[100005];

int main()
{
    cin >> n;
    if (n==1) cout << "YES";
    else {
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            ++q[a[i]];
            if (q[a[i]] * 2 - 1 > n) {
                cout << "NO";
                return 0;
            }
        }
        cout << "YES";
    }

    return 0;
}