#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    vt<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (ans[i]) continue;

        for (int j = i + 1; j < n; j++) {
            if (ans[j]) continue;

            cout << "? " << i + 1 << ' ' << j + 1 << endl;
            int q1;
            cin >> q1;
            cout << "? " << j + 1 << ' ' << i + 1 << endl;
            int q2;
            cin >> q2;

            if (q1 > q2) {
                ans[i] = q1;
                break;
            } else {
                ans[j] = q2;
            }
        }
    }

    cout << '!';
    for (int i : ans) cout << ' ' << (!i ? n : i);
    cout << endl;
}