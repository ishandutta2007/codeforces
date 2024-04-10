#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int long long

const int K = 30;
int sm[K][2];

// 0 - initial
// 1 - reversed

void prec() {
    sm[0][0] = 1;
    for (int i = 1; i < K; ++i) {
        sm[i][0] = sm[i - 1][0] + sm[i - 1][1];
        sm[i][1] = (1 << i) - sm[i][0];
    }
}

int get(int x) {
    int fl = 0;
    int res = 0;
    for (int i = K - 1; i >= 0; --i) {
        if (x & (1 << i)) {
            res += sm[i][fl];
            fl ^= 1;
        }
    }
    return res;
}

int getk(int k) {
    return (get(k + 1) - get(k)) ^ 1;
}

int n, m;
vector <vector <int>> pref, ipref;

ll sum(int x, int y, bool rev) {
    ll val = 0;
    if (x <= n && y <= m) val = pref[x][y];
    if (x <= n) {
        int c = y / m;
        int ost = y % m;
        int cnt = get(c);
        int v = getk(c);
        val = (ll)pref[x][m] * cnt + (ll)ipref[x][m] * (c - cnt) + (v == 0 ? pref[x][ost] : ipref[x][ost]);
    }
    else {
        ll s = sum(n, y, 0);
        ll is = sum(n, y, 1);
        int c = x / n;
        int ost = x % n;
        int cnt = get(c);
        int v = getk(c);
        val = s * cnt + is * (c - cnt) + sum(ost, y, v);
    }
    if (rev == 0) return val;
    return ((ll)x * y - val);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    prec();
    int q;
    cin >> n >> m >> q;
    vector <vector <int>> a(n, vector <int> (m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }
    pref.resize(n + 1, vector <int> (m + 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            pref[i + 1][j + 1] = pref[i][j + 1] + pref[i + 1][j] - pref[i][j] + a[i][j];
        }
    }
    ipref.resize(n + 1, vector <int> (m + 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ipref[i + 1][j + 1] = ipref[i][j + 1] + ipref[i + 1][j] - ipref[i][j] + (a[i][j] ^ 1);
        }
    }
    
    for (int i = 0; i < q; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        --x1, --y1;
        cout << sum(x2, y2, 0) - sum(x1, y2, 0) - sum(x2, y1, 0) + sum(x1, y1, 0) << '\n';
    }
}