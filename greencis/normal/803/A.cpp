#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, k, a[105][105];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    if (k > n * n) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < n && k; ++i) {
        for (int j = i; j < n && k; ++j) {
            if (i == j)
                a[i][j] = 1, --k;
            else if (k >= 2)
                a[i][j] = a[j][i] = 1, k -= 2;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << a[i][j] << " ";
        cout << "\n";
    }

    return 0;
}