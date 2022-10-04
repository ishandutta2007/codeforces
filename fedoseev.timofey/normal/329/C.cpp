#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    set <pair <int, int>> ed;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        ed.insert({a, b});
        ed.insert({b, a});
    }
    vector <int> p(n);
    iota(p.begin(), p.end(), 0);
    mt19937 rnd(123);
    while ((double)clock() / CLOCKS_PER_SEC < 1.4) {
        shuffle(p.begin(), p.end(), rnd);
        bool fl = true;
        int uk = 0;
        for (int i = 0; i < m; ++i) {
            if (ed.count({p[uk], p[(uk + 1) % n]})) {
                fl = false;
                break;
            }
            ++uk;
        }
        if (fl) {
            uk = 0;
            for (int i = 0; i < m; ++i) {
                cout << p[uk] + 1 << ' ' << p[(uk + 1) % n] + 1 << '\n';
                ++uk;
            }
            return 0;
        }
    }
    cout << "-1\n";
}