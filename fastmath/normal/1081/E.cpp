#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 5e5 + 7;

int n;
int a[MAXN];
int pref[MAXN];
int ans[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    n >>= 1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i < MAXN; ++i) {
        pref[i] = i * i;
    }

    int pr = 0;
    int u = 1;
    int c = 0;
    for (int i = 2; i < MAXN; ++i) {
        while (pref[i] - pref[u] > a[c]) {
            ++u;
        }

        //cout << i << ' ' << pref[i] << ' ' << pref[u] << '\n';

        if (pref[i] - pref[u] == a[c]) {
            ans[c] = pref[u] - pref[pr];
            ++c;
            if (c == n) {
                cout << "Yes\n";
                for (int t = 0; t < n; ++t) {
                    cout << ans[t] << ' ' << a[t] << ' ';
                }
                exit(0);
            }
            pr = i;
            u = i + 1;
        }
    }

    cout << "No\n";
    return 0;
}