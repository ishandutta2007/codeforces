#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int long long 

struct qr {
    int i, j, d;
};

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    multiset <pair <int, int>> s;
    multiset <int> t;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        s.insert({x, i});
    }
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        t.insert(x);
    }
    vector <qr> ans;
    while (!t.empty()) {
        int x = *t.begin();
        t.erase(t.begin());
        auto jt = s.upper_bound({x, (int)1e9});
        if (jt == s.begin()) {
            cout << "NO\n";
            return 0;
        }
        --jt;

        auto p1 = *jt;
        s.erase(jt);

        if (p1.first == x) continue;

        auto it = s.lower_bound({x, -1});
        if (it == s.end()) {
            cout << "NO\n";
            return 0;
        }

        auto p2 = *it;
        s.erase(it);

        int cr = min(x - p1.first, p2.first - x);
        ans.push_back({p1.second, p2.second, cr});

        p1.first += cr;
        p2.first -= cr;

        if (p1.first == x) s.insert(p2);
        else s.insert(p1);
    }
    cout << "YES\n";
    cout << ans.size() << '\n';
    for (auto &q : ans) {
        cout << q.i + 1 << ' ' << q.j + 1 << ' ' << q.d << '\n';
    }
}