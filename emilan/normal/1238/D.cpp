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

int cnt(string s, int n) {
    int l = 0, ans = 0;
    for (int r = 0; r < n; r++) {
        while (l < r && s[l] == s[l + 1]) l++;
        if (l < r) {
            if (s[l] != s[r]) ans++;
            else l++, r--;
        }
    }
    return ans;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int ab = 0;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] != s[i]) ab++;
    }

    ll ans = n * (n - 1ll) / 2;
    ans -= cnt(s, n);
    reverse(all(s));
    ans -= cnt(s, n);
    ans += ab;

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}