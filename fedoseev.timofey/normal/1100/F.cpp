#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 5e5 + 7;
const int K = 20;
const int MAXA = 1e6 + 7;
int a[N];
vector <int> t[2 * N];
int lb[MAXA];
int ans[N];

int n;

vector <int> merge(const vector <int> &_a, const vector <int> &b) {
    vector <int> c = _a;
    for (int i = K - 1; i >= 0; --i) {
        if (b[i] == -1) continue;
        int x = b[i];
        while (x) {
            int y = lb[x];
            if (c[y] == -1) {
                c[y] = x;
                break;
            }
            else {
                x ^= c[y];
            }
        }
    }
    return c;
}

struct query {
    int l, r, id;
    query(int l, int r, int id) : l(l), r(r), id(id) {}
};

vector <int> suf[N];
vector <int> pref[N];

void rec(const vector <query> &qr, int l, int r) {
    if (qr.empty()) return;
    int m = (l + r) >> 1;
    vector <query> qrl, qrr;
    vector <query> qrm;
    for (int i = 0; i < (int)qr.size(); ++i) {
        if (qr[i].l <= m && m <= qr[i].r) {
            qrm.push_back(qr[i]);
        }
        else if (qr[i].r < m) qrl.push_back(qr[i]);
        else if (qr[i].l > m) qrr.push_back(qr[i]);
    }
    for (int i = m; i >= l; --i) {
        if (i != m) suf[i] = suf[i + 1];
        else suf[i] = vector <int> (K, -1);
        int x = a[i];
        while (x > 0) {
            int y = lb[x];
            if (suf[i][y] == -1) {
                suf[i][y] = x;
                break;
            }
            x ^= suf[i][y];
        }
    }
    for (int i = m; i <= r; ++i) {
        if (i != m) pref[i] = pref[i - 1];
        else pref[i] = vector <int> (K, -1);
        int x = a[i];
        while (x > 0) {
            int y = lb[x];
            if (pref[i][y] == -1) {
                pref[i][y] = x;
                break;
            }
            x ^= pref[i][y];
        }
    }
    for (auto &qr : qrm) {
        vector <int> cur = merge(suf[qr.l], pref[qr.r]);
        int x = 0;
        for (int i = K - 1; i >= 0; --i) {
            if (cur[i] != -1) x = max(x, x ^ cur[i]);
        }
        ans[qr.id] = x;
    }
    rec(qrl, l, m - 1);
    rec(qrr, m + 1, r);
}

void init() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
}

void precalc() {
    for (int i = 1; i < MAXA; ++i) {
        for (int j = K - 1; j >= 0; --j) {
            if (i & (1 << j)) {
                lb[i] = j;
                break;
            }
        }
    }
}

void solve() {
    int q;
    cin >> q;
    vector <query> qr;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        qr.emplace_back(l, r, i);
    }
    rec(qr, 0, n - 1);
    for (int i = 0; i < q; ++i) {
        cout << ans[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    precalc();
    init();
    solve();
}