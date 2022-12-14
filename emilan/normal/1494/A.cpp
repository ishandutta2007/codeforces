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
    string s;
    cin >> s;

    for (int i = 0; i < 8; i++) {
        int k = 0;
        for (char c : s) {
            bool l = i >> (c - 'A') & 1;
            if (l) k++;
            else k--;

            if (k < 0) break;
        }

        if (!k) return void(cout << "yEs\n");
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