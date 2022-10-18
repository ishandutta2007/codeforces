#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, x, y, z;
vector<ll> a[3];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    a[1].push_back(0);
    for (int i = 0; i < n; ++i) {
        cin >> x;
        a[1].push_back(x);
    }
    a[2] = a[1];
    sort(a[2].begin(), a[2].end());
    for (int i = 0; i < n; ++i)
        a[2][i + 1] += a[2][i], a[1][i + 1] += a[1][i];

    cin >> n;
    while (n--) {
        cin >> x >> y >> z;
        cout << a[x][z] - a[x][y - 1] << "\n";
    }

    return 0;
}