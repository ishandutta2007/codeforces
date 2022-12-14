#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

void solve() {
    vt<int> a(5);
    for (int &x : a) cin >> x;

    for (int i = 0; i < 16; i++) {
        vt<int> b(a);
        for (int j = 0; j < 4; j++) {
            if (i >> j & 1) {
                b[j + 1]--, b[(j + 1) % 4 + 1]--;
            }
        }

        if (all_of(b.begin() + 1, b.end(), [&](int x){
            return 0 <= x && x <= a[0] - 2;
        })) {
            return void(cout << "yEs\n");
        }
    }

    cout << "nO\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}