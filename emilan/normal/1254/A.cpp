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
    int n, m, k;
    cin >> n >> m >> k;
    vt<string> a(n);
    for (auto &s : a) cin >> s;

    int rice = 0;
    for (auto &s : a) rice += count(all(s), 'R');
    int cnt = rice / k, p1 = rice % k;

    int c = 0, ate = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i & 1 ? m - 1 : 0;
             ~j && j < m;
             j += i & 1 ? -1 : 1) {
            if (a[i][j] == 'R') ate++;
            if (ate > cnt + (c < p1)) {
                ate = 1;
                c++;
            }
            a[i][j] = c < 10 ? c + 48 :
                c < 36 ? c + 55 :
                c + 61;
        }
    }

    for (auto &s : a) cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}