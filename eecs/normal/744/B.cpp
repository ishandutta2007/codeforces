#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int n, mn[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    memset(mn, 0x3f, sizeof(mn));
    for (int k = 1; k <= 512; k *= 2) {
        vector<int> V;
        for (int i = 1; i <= n; i++) {
            if (i & k) V.push_back(i);
        }
        if (!V.empty()) {
            cout << V.size() << endl;
            for (int x : V) cout << x << " ";
            cout << endl;
            for (int i = 1, x; i <= n; i++) {
                cin >> x;
                if (!(i & k)) mn[i] = min(mn[i], x);
            }
        }
        V.clear();
        for (int i = 1; i <= n; i++) {
            if (!(i & k)) V.push_back(i);
        }
        if (!V.empty()) {
            cout << V.size() << endl;
            for (int x : V) cout << x << " ";
            cout << endl;
            for (int i = 1, x; i <= n; i++) {
                cin >> x;
                if (i & k) mn[i] = min(mn[i], x);
            }
        }
    }
    cout << -1 << endl;
    for (int i = 1; i <= n; i++) {
        cout << mn[i] << " ";
    }
    cout << endl;
    return 0;
}