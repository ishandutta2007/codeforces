#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, q;
    cin >> n >> q;
    deque <int> d;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        d.push_back(x);
    }
    vector <pair <int, int>> op;
    for (int i = 0; i < 1e6; ++i) {
        int a = d.front();
        d.pop_front();
        int b = d.front();
        d.pop_front();
        if (a > b) d.push_front(a), d.push_back(b);
        else d.push_front(b), d.push_back(a);
        op.push_back({a, b});
    }
    for (int i = 0; i < q; ++i) {
        ll m;
        cin >> m;
        --m;
        if (m < op.size()) {
            cout << op[m].first << ' ' << op[m].second << '\n';
        }
        else {
            int id = (m - op.size()) % (n - 1);
            cout << d[0] << ' ' << d[id + 1] << '\n';
        }
    }
}