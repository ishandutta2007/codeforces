#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 7;
const int INF = 1e9 + 7;

int n;
pair <int, int> a[MAXN];

int get(int del) {
    int r = INF;
    int l = -INF;
    for (int i = 0; i < n; ++i) {
        if (i == del) continue;
        l = max(l, a[i].first);
        r = min(r, a[i].second);
    }
    return max(0, r - l);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    int mx1 = -1, mx2 = -1;
    for (int i = 0; i < n; ++i) {
        if (mx1 == -1 || a[mx1].first < a[i].first) mx1 = i;
        if (mx2 == -1 || a[mx2].second > a[i].second) mx2 = i;
    }

    cout << max(get(mx1), get(mx2)) << '\n';
    return 0;
}