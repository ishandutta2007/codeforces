#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int long long

const int N = 1e5 + 7;

int p[N];
bool ok[N];

int cnt = 0;

int get(int u) {
    return (u == p[u] ? u : p[u] = get(p[u]));
}

void merge(int u, int v) {
    u = get(u);
    v = get(v);
    if (u != v) {
        --cnt;
        p[u] = v;
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m, l;
    cin >> n >> m >> l;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] > l) {
            ++cnt;
            p[i] = i;
            ok[i] = 1;
        }
    }
    for (int i = 1; i < n; ++i) {
        if (ok[i] && ok[i - 1]) merge(i, i - 1);
    }
    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;
        if (t == 0) {
            cout << cnt << '\n';
        }
        else {
            int id, d;
            cin >> id >> d;
            --id;
            a[id] += d;
            if (a[id] > l && !ok[id]) {
                p[id] = id;
                ok[id] = 1;
                ++cnt;
                if (id && ok[id - 1]) merge(id, id - 1);
                if (id != n - 1 && ok[id + 1]) merge(id, id + 1);
            }
        }
    }
}