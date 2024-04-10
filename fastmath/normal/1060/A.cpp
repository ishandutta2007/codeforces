#include <bits/stdc++.h>

using namespace std;

const int MAXN = 107;

int cnt[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        ++cnt[c - '0'];
    }

    for (int i = MAXN - 1; i >= 0; --i) {
        if (i <= cnt[8] && n >= i * 11) {
            cout << i << '\n';
            exit(0);
        }
    }

    return 0;
}