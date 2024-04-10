#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 7;

int ans[MAXN];
bool del[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int curr = 1;
    int ost = n;
    int u = 0;
    while (1) {
        int best = -1, want = ost;
        for (int i = curr * 2; i <= n; i += curr) {
            int c = ost;
            for (int j = i; j <= n; j += i) c -= !del[j];
            if (c == ost) break;
            if (c <= want) {
                best = i;
                want = c;
            }
        }
        for (int i = u; i < u + want; ++i) cout << curr << ' ';
        if (best == -1) break;

        ost -= want;
        curr = best;
        for (int i = 1; i <= n; ++i) {
            if (i % curr) del[i] = 1;
        }
    }
    cout << '\n';

    return 0;
}