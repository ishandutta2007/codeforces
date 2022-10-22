#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 7;
const int INF = 1e9 + 7;
const int BIGINF = 1e18 + 7;

int n;
int a[MAXN], b[MAXN];

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> b[i];
}

bool bad(int i, int val) {
    if (val == 0) return 1;
    int pr = (i - 1 + n) % n;
    if (val <= b[pr]) return 1;
    return 0;
}

void kek(int i) {
    int nx = (i + 1) % n;
    int ost = b[i];

    int l = -1;
    int r = BIGINF / a[nx];

    while (l < r - 1) {
        int m = (l + r) / 2;
        int val = a[nx] * m + ost;
        if (bad(i, val)) {
            l = m;
        }
        else {
            r = m;
        }
    }

    a[i] = r * a[nx] + ost;
}

void calc(int i) {
    a[i] = b[i];
    for (int t = (i - 1 + n) % n; t != i; t = (t - 1 + n) % n) {
        kek(t);
    }
    
    for (int t = 0; t < n; ++t) {
        int nx = (t + 1) % n;
        if (a[t] % a[nx] != b[t]) return;
    }
    
    cout << "YES\n";
    for (int i = 0; i < n; ++i) cout << a[i] << ' ';
    cout << '\n';
    exit(0);
}

void solve() {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += b[i];
    }
    if (sum == 0) {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) cout << "1 ";
        cout << '\n';
        exit(0);
    }
    bool ch = 1;
    for (int i = 1; i < n; ++i) {
        ch &= (b[i] == b[i - 1]);
    }
    if (ch) {
        cout << "NO\n";
    }
    else {
        int mx = -1;
        for (int i = 0; i < n; ++i) {
            mx = max(mx, b[i]);
        }
        int pos = -1;
        for (int i = 0; i < n; ++i) {
            int pr = (i - 1 + n) % n;
            if (b[i] == mx && b[pr] != mx) pos = i;
        }
        calc(pos);
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();

    return 0;
}