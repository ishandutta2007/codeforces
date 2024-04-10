#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

void solve() {
    int n;
    cin >> n;
    vector <int> d(n);
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        d[i] = c - '0';
    }
    for (int cnt = 0; cnt <= 10; ++cnt) {
        vector <int> col(n);
        bool bad = false;
        int la = -1, lb = -1;
        for (int i = 0; i < n; ++i) {
            if (d[i] < cnt) {
                if (d[i] < la) {
                    bad = true;
                    break;
                }
                col[i] = 1;
                la = d[i];
            } else if (d[i] > cnt) {
                col[i] = 2;
                if (d[i] < lb) {
                    bad = true;
                    break;
                }
                lb = d[i];
            } else {
                if (d[i] >= lb) {
                    lb = d[i];
                    col[i] = 2;
                } else if (d[i] >= la) {
                    la = d[i];
                    col[i] = 1;
                } else {
                    bad = true;
                    break;
                }
            }
        }
        if (!bad) {
            for (int i = 0; i < n; ++i) cout << col[i];
            cout << '\n';
            return;
        }
    }
    cout << "-\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) solve();
}