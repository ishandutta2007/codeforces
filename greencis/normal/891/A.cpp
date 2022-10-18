#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int n, a[2005];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int g = a[1];
    for (int i = 2; i <= n; ++i)
        g = gcd(g, a[i]);
    if (g > 1) {
        cout << -1 << endl;
        return 0;
    }

    int ones = 0;
    for (int i = 1; i <= n; ++i)
        ones += a[i] == 1;
    if (ones) {
        cout << n - ones << endl;
        return 0;
    }

    int ans = 1e9;
    for (int i = 1; i <= n; ++i) {
        int g = a[i];
        int iter = 0;
        for (int j = 1; i - j >= 1 && g > 1; ++j) {
            ++iter;
            g = gcd(g, a[i - j]);
        }
        if (g == 1)
            ans = min(ans, iter + n - 1);
        g = a[i];
        iter = 0;
        for (int j = 1; i + j <= n && g > 1; ++j) {
            ++iter;
            g = gcd(g, a[i + j]);
        }
        if (g == 1)
            ans = min(ans, iter + n - 1);
    }
    cout << ans << endl;

    return 0;
}