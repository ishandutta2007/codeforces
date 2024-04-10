#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, x, y, a[100105];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> x >> y;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n, greater<int>());
    n = x + y;
    if (x > y)
        swap(x, y);
    double a1 = 0, a2 = 0;
    for (int i = 0; i < x; ++i)
        a1 += a[i];
    for (int i = 0; i < y; ++i)
        a2 += a[x + i];
    cout << setprecision(17) << fixed << a1 / x + a2 / y;

    return 0;
}