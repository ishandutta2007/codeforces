#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;

int n;
int a[MAXN], b[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    set <int> ms;
    for (int i = 0; i < n; ++i) ms.insert(a[i]);

    int u = 0;
    for (int i = 0; i < n; ++i) {
        if (ms.find(b[i]) == ms.end()) {
            cout << "0 ";
            continue;
        }
        else {
            int ans = 0;
            while (1) {
                ms.erase(a[u]);
                ++u;
                ++ans;
                if (a[u - 1] == b[i]) break;
            }
            cout << ans << ' ';
        }
    }

    cout << '\n';
    return 0;
}