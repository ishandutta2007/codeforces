#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;

void print(int n) {
    for (int i = 0; i < n; ++i)
        cout << "(";
    for (int i = 0; i < n; ++i)
        cout << ")";
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        print(n - i);
        print(i);
        cout << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}