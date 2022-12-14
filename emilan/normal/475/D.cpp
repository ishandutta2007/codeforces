#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    map<int, i64> m, cur;
    m[a[0]] = cur[a[0]] = 1;
    for (int i = 1; i < n; i++) {
        map<int, i64> nxt;
        for (auto [j, x] : cur) {
            m[gcd(j, a[i])] += x;
            nxt[gcd(j, a[i])] += x;
        }
        m[a[i]]++;
        nxt[a[i]]++;
        swap(cur, nxt);
    }

    int q;
    cin >> q;
    while (q--) {
        int i;
        cin >> i;
        cout << m[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}