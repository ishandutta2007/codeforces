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

#define die return void(cout << "No\n")

void solve() {
    int n, k;
    string a, b;
    cin >> n >> k >> a >> b;

    int cnt_a[128] = {}, cnt_b[128] = {};
    for (char c = 'a'; c <= 'z'; c++) {
        cnt_a[c] += count(all(a), c);
        cnt_b[c] += count(all(b), c);

        if (cnt_a[c] < cnt_b[c] || (cnt_a[c] - cnt_b[c]) % k) die;
        cnt_a[c + 1] = cnt_a[c] - cnt_b[c];
    }

    cout << "Yes\n";
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