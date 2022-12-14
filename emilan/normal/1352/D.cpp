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
    int n;
    cin >> n;
    deque<int> a(n);
    for (int &x : a) cin >> x;

    int mv = 0, e[2] = {0}, prev = 0, cur = 0;
    while (!a.empty()) {
        if (~mv & 1) {
            e[0] += a[0];
            cur += a[0];
            a.pop_front();
        } else {
            e[1] += a.back();
            cur += a.back();
            a.pop_back();
        }

        if (!a.empty() && cur > prev) {
            prev = cur;
            cur = 0;
            mv++;
        }
    }


    cout << ++mv << ' ' << e[0] << ' ' << e[1] << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}