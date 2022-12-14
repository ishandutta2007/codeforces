#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

void solve(int tc) {
    int n;
    cin >> n;
    vt<int> a(n);
    set<int> s;
    for (int &i : a) {
        cin >> i;
        s.insert(i);
    }

    for (int i = 1; i <= 1024; i++) {
        set<int> s1(s);
        for (int j = 0; j < n; j++) {
            s1.erase(a[j] ^ i);
        }
        if (s1.empty()) return void(cout << i << '\n');
    }
    cout << "-1\n";
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case #" << tc << ": ";
        solve(tc);
    }
}