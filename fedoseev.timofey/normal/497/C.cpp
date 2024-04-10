#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

struct Event {
    int l, r, t, id, k;
    Event(int l, int r, int t, int id) : l(l), r(r), t(t), id(id), k(-1) {}
    Event(int l, int r, int t, int id, int k) : l(l), r(r), t(t), id(id), k(k) {}
    bool operator <(const Event &other) const {
        if (r != other.r) return r < other.r;
        if (t != other.t) return t < other.t;
        return l < other.l;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <Event> e;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        e.emplace_back(a, b, 0, i);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, k;
        cin >> a >> b >> k;
        e.emplace_back(a, b, 1, i, k);
    }
    vector <int> ans(n);
    sort(e.begin(), e.end());
    multiset <pair <int, int>> s;
    for (auto ev : e) {
        if (ev.t == 0) {
            s.insert({ev.l, ev.id});
        } else {
            int can = ev.k;
            while (can > 0) {
                auto it = s.lower_bound({ev.l, -1});
                if (it == s.end()) break;
                ans[it->second] = ev.id;
                --can;
                s.erase(it);
            }
        }
    }
    if (!s.empty()) cout << "NO\n";
    else {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) cout << ans[i] + 1 << ' ';
    }
}