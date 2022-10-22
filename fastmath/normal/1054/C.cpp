#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1007;

int l[MAXN], r[MAXN];
int sum[MAXN];

vector <int> p[MAXN << 1];

int n;
int a[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> l[i];
    for (int i = 0; i < n; ++i) cin >> r[i];

    for (int i = 0; i < n; ++i) sum[i] = l[i] + r[i];
    for (int i = 0; i < n; ++i) p[sum[i]].push_back(i);

    int curr = n;
    for (int i = 0; i < 2 * MAXN; ++i) {
        if (p[i].empty()) continue;
        for (int t : p[i]) a[t] = curr;
        --curr;
    }

    for (int i = 0; i < n; ++i) {
        int nl = 0;
        for (int t = 0; t < i; ++t) nl += (a[i] < a[t]);
        int nr = 0;
        for (int t = i + 1; t < n; ++t) nr += (a[i] < a[t]);
        if (nl != l[i] || nr != r[i]) {
            cout << "NO\n";
            exit(0);
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i) cout << a[i] << ' ';
    cout << '\n';

    return 0;
}