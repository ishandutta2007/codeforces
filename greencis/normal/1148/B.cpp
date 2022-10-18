#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, m, k;
ll ta, tb, a[200105], b[200105];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> ta >> tb >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    int ptr = 0;
    while (ptr < m && a[0] + ta > b[ptr])
        ++ptr;
    if (ptr + k >= m || k >= n || k >= m) {
        cout << -1 << endl;
        return 0;
    }
    ll ans = b[ptr + k] + tb;
    for (int i = 1; i < n && i <= k; ++i) {
        while (ptr < m && a[i] + ta > b[ptr])
            ++ptr;
        if (ptr + k - i >= m) {
            cout << -1 << endl;
            return 0;
        }
        ans = max(ans, b[ptr + k - i] + tb);
    }
    cout << ans << endl;
}