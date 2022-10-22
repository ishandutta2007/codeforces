#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 7;
const int INF = 3e18 + 7;

int n, t;
int a[MAXN], p[MAXN], l[MAXN], r[MAXN];
int ans[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> t;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        cin >> p[i]; --p[i];
    }
    
    for (int i = 0; i < n - 1; ++i) {
        if (p[i + 1] < p[i]) {
            cout << "No\n";
            exit(0);
        }
    }

    for (int i = 0; i < n; ++i) {
        l[i] = 1;   
        r[i] = INF;
    }
    
    for (int i = 0; i < n; ++i) {
        l[p[i]] = max(l[p[i]], a[i] + t);
    }
    
    for (int i = 0; i < n; ++i) {
        l[i] = max(l[i], a[i] + t);
    }

    int mx = -1;
    for (int i = 0; i < n - 1; ++i) {
        mx = max(mx, p[i]);
        if (i < mx) {
            l[i] = max(l[i], a[i + 1] + t);
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        if (p[i] < i) {
            r[p[i]] = min(r[p[i]], a[p[i]] + t - 1);
        }
        else {
            r[p[i]] = min(r[p[i]], a[p[i] + 1] + t - 1);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (!i) ans[i] = l[i];
        else ans[i] = max(ans[i - 1] + 1, l[i]);
    }
    
    for (int i = 0; i < n - 1; ++i) {
        if (ans[i + 1] <= a[i]) {
            cout << "No\n";
            exit(0);
        }
        if (!(l[i] <= ans[i] && ans[i] <= r[i])) {
            cout << "No\n";
            exit(0);
        }
    }
    
    cout << "Yes\n";
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}