#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int n;

int dist(int x, int y) {
    int z = abs(x - y);
    return min(z, n - z);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int m;
    cin >> n >> m;
    vector <vector <int>> kek(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (a > b) swap(a, b);
        int x = dist(a, b);
        if (((a + x) % n) == b) {
            kek[x].push_back(a);
        }
        if (((b + x) % n) == a){
            kek[x].push_back(b);
        }
    }
    for (int i = 0; i < n; ++i) sort(kek[i].begin(), kek[i].end());
    auto check = [&] (int x) {
        bool fl = true;
        for (int i = 0; i < n; ++i) {
            vector <int> cur;
            for (auto y : kek[i]) {
                cur.push_back((y + x) % n);
            }
            sort(cur.begin(), cur.end());
            fl &= (cur == kek[i]);
        }
        return fl;
    };
    for (int d = 1; d * d <= n; ++d) {
        if (n % d == 0) {
            if (check(d)) {
                cout << "Yes\n";
                exit(0);
            }
            int x = n / d;
            if (x != n) {
                if (check(x)) {
                    cout << "Yes\n";
                    exit(0);
                }
            }
        }
    }
    cout << "No\n";
}