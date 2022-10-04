#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int long long

const int Inf = 1e9;

const int N = 2e5 + 7;
const int K = 21;

int go[K][N];
int a[N];
vector <int> where[N];

int get_nxt(int id, int x) {
    auto it = upper_bound(where[x].begin(), where[x].end(), id);
    if (it == where[x].end()) return -1;
    return *it;
}



signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m, q;
    cin >> n >> m >> q;
    vector <int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }
    vector <int> pos(n);
    for (int i = 0; i < n; ++i) pos[p[i]] = i;
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        --a[i];
    }
    for (int i = 0; i < m; ++i) {
        where[a[i]].push_back(i);
    }

    for (int i = 0; i < m; ++i) {
        int ps = (pos[a[i]] + 1) % n;
        int x = p[ps];
        int j = get_nxt(i, x);
        go[0][i] = j;
    }

    for (int i = m - 1; i >= 0; --i) {
        for (int j = 1; j < K; ++j) {
            int x = go[j - 1][i];
            if (x == -1) go[j][i] = -1;
            else go[j][i] = go[j - 1][x];
        }
    }
    vector <int> r(m, Inf);
    for (int i = m - 1; i >= 0; --i) {
        int x = i;
        for (int j = 0; j < K; ++j) {
            if ((n - 1) & (1 << j)) {
                if (x != -1) x = go[j][x];
            }
        }
        if (x != -1) r[i] = x;
    }

    for (int i = m - 2; i >= 0; --i) {
        r[i] = min(r[i], r[i + 1]);
    }
    for (int i = 0; i < q; ++i) {
        int l, rr;
        cin >> l >> rr;
        --l, --rr;
        if (r[l] <= rr) {
            cout << 1;
        }
        else {
            cout << 0;
        }
    }
}