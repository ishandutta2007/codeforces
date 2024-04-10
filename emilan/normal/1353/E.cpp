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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int cnt1 = count(all(s), '1');
    if (!cnt1) {
        cout << "0\n";
        return;
    }

    int mx = 0;
    for (int i = 0; i < k; i++) {
        vt<int> p{0};
        multiset<int> ps;
        int idx = i;
        for (int j = i; j < n; j += k) {
            p.push_back(p.back() + (s[j] == '1') * 2 - 1);
            ps.insert(p.back());
        }

        for (int j = 1; j < sz(p); j++) {
            mx = max(mx, *ps.rbegin() - p[j - 1]);
            ps.erase(ps.find(p[j]));
        }
    }
    cout << cnt1 - mx << '\n';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) solve(tc);
}