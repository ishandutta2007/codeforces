#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, a[105];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum) {
        cout << "YES\n1\n1 " << n;
        return 0;
    } else {
        for (int i = 0; i < n; ++i) {
            if (a[i]) {
                cout << "YES\n2\n1 " << i + 1 << "\n" << i + 2 << " " << n << endl;
                return 0;
            }
        }
    }
    cout << "NO\n";8;
    return 0;
}