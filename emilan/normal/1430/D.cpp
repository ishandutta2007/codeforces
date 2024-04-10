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
    string s;
    cin >> n >> s;

    vt<int> seg{1};
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == s[i]) seg.back()++;
        else seg.push_back(1);
    }

    int l = 0, r = sz(seg) - 1, i = 0;
    while (l <= r) {
        while (i < r && (i < l || seg[i] == 1)) i++;
        if (i >= r && seg[r] == 1) r--;
        else seg[i]--;
        l++;
    }
    cout << l << '\n';
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