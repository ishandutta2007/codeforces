#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)x.size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      x.begin(), x.end()
#define rall(x)     x.rbegin(), x.rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("io\\in.txt", "r", stdin);
    freopen("io\\out.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi a(n);
        rep(i, n) cin >> a[i];

        vi mn1(n), mn2(n);
        mn1[0] = 0, mn2[n - 1] = n - 1;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[mn1[i - 1]]) mn1[i] = i;
            else mn1[i] = mn1[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            if (a[i] < a[mn2[i + 1]]) mn2[i] = i;
            else mn2[i] = mn2[i + 1];
        }

        bool ok = false;
        for (int i = 1; i < n - 1; i++) {
            if (a[mn1[i - 1]] < a[i] && a[i] > a[mn2[i + 1]]) {
                ok = true;
                cout << "yes\n";
                cout << mn1[i - 1] + 1 << ' ' << i + 1 << ' ' << mn2[i + 1] + 1
                     << '\n';
                break;
            }
        }

        if (!ok) cout << "no\n";
    }

    return 0;
}