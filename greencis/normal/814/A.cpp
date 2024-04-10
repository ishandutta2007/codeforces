#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, m, a[205], b[205];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    sort(b, b + m, greater<int>());
    int bi = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0)
            a[i] = b[bi++];
        if (i && a[i] <= a[i - 1]) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";

    return 0;
}