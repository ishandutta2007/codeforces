#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 107;

int n;
int a[MAXN];

bool check(int m) {
    int x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
        x += m - a[i];
        y += a[i];
    }
    return x > y;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    int mx = -1;
    for (int i = 0; i < n; ++i) mx = max(mx, a[i]);

    int l = mx - 1;
    const int INF = 1e9 + 7;
    int r = INF;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (!check(m)) l = m;
        else r = m;
    }   
    
    cout << r << '\n';
    return 0;
}