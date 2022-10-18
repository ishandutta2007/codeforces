#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int threshold;
int n, q, x, y, a[100105], d[325][100105];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    threshold = max(1, (int)sqrt(ld(n)));
    for (int k = 1; k <= threshold; ++k) {
        for (int i = n; i >= 1; --i) {
            int nxt = i + a[i] + k;
            d[k][i] = (nxt > n ? 0 : d[k][nxt]) + 1;
        }
    }
    cin >> q;
    while (q--) {
        cin >> x >> y;
        if (y <= threshold)
            cout << d[y][x] << "\n";
        else {
            int ans = 0;
            while (x <= n)
                x += a[x] + y, ++ans;
            cout << ans << "\n";
        }
    }

    return 0;
}