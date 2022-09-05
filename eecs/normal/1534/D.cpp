#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010;
int n, d[maxn];
set<pair<int, int>> E;

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    cout << "? " << 1 << endl;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        if (d[i] == 1) E.emplace(1, i);
    }
    int cnt0 = 0, cnt1 = 0;
    for (int i = 2; i <= n; i++) {
        if (d[i] & 1) cnt1++;
        else cnt0++;
    }
    if (cnt0 <= cnt1) {
        for (int i = 2; i <= n; i++) if (!(d[i] & 1)) {
            cout << "? " << i << endl;
            for (int j = 1, k; j <= n; j++) {
                scanf("%d", &k);
                if (k == 1) E.emplace(min(i, j), max(i, j));
            }
        }
    } else {
        for (int i = 2; i <= n; i++) if (d[i] & 1) {
            cout << "? " << i << endl;
            for (int j = 1, k; j <= n; j++) {
                scanf("%d", &k);
                if (k == 1) E.emplace(min(i, j), max(i, j));
            }
        }
    }
    cout << "!" << endl;
    for (auto p : E) {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}