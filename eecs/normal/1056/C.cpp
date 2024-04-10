#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010;
int n, m, dir, p[maxn], lnk[maxn], used[maxn];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> p[i];
    }
    while (m--) {
        int u, v; cin >> u >> v;
        lnk[u] = v, lnk[v] = u;
    }
    cin >> dir, dir--;
    for (int i = 1; i <= 2 * n; i++, dir ^= 1) {
        if (!dir) {
            int x = -1;
            for (int i = 1; i <= 2 * n; i++) if (!used[i] && lnk[i]) {
                if (p[i] > p[lnk[i]]) { x = i; break; }
                x = lnk[i]; break;
            }
            if (!~x) {
                int mx = 0;
                for (int i = 1; i <= 2 * n; i++) if (!used[i]) {
                    if (p[i] > mx) mx = p[i], x = i;
                }
            }
            cout << x << endl;
            used[x] = used[lnk[x]] = 1;
            if (lnk[x]) cin >> x, i++, dir ^= 1;
        } else {
            int x; cin >> x;
            used[x] = used[lnk[x]] = 1;
            if (lnk[x]) cout << lnk[x] << endl, i++, dir ^= 1;
        }
    }

    return 0;
}