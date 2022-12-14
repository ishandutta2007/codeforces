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

const int mod = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    map<char, ll> contribution;
    vt<char> order(k);
    iota(all(order), 'a');
    ll ans = 1;
    for (char c : s) {
        ll delta = (ans - contribution[c] + mod) % mod;
        ans = (ans + delta) % mod;
        contribution[c] = (contribution[c] + delta) % mod;

        order.erase(find(all(order), c));
        order.push_back(c);
    }

    while (n--) {
        char c = order[0];
        ll delta = (ans - contribution[c] + mod) % mod;
        ans = (ans + delta) % mod;
        contribution[c] = (contribution[c] + delta) % mod;

        order.push_back(c);
        order.erase(order.begin());
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}