#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int md = 1e9 + 7;

void add(int &a, int b) {
    a += b;
    if (a >= md) a -= md;
}

struct event {
    int x, t, i;
    event(int x, int t, int i) : x(x), t(t), i(i) {}
    bool operator<(const event &other) const {
        if (x != other.x) return x < other.x;
        return t < other.t;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, x, y;
    cin >> n >> x >> y;
    vector <int> l(n), r(n);
    for (int i = 0; i < n; ++i) cin >> l[i] >> r[i];
    vector <event> ev;
    for (int i = 0; i < n; ++i) {
        ev.emplace_back(l[i], -1, i);
        ev.emplace_back(r[i], 1, i);
    }
    sort(ev.begin(), ev.end());
    int ans = 0;
    multiset <int> cur;
    for (auto e : ev) {
        if (e.t == -1) {
            int i = e.i;
            ll mn = x + (ll)(r[i] - l[i]) * y;
            if (!cur.empty()) {
                int id = *cur.rbegin();
                ll need = (ll)(r[e.i] - id) * y;
                if (need <= mn) {
                    cur.erase(--cur.end());
                }
                mn = min(mn, need);
            }
            add(ans, mn % md);
        }
        else {
            cur.insert(e.x);
        }
    }
    cout << ans << '\n';
}