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

const ll mod = 1e9 + 7;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    ll q = 1, a = 0, b = 0, c = 0;
    for (char ch : s) {
        ll a_d = 0, b_d = 0, c_d = 0;
        if (ch == '?' || ch == 'a') a_d += q;
        if (ch == '?' || ch == 'b') b_d += a;
        if (ch == '?' || ch == 'c') c_d += b;
        if (ch == '?') {
            a_d += a * 2;
            b_d += b * 2;
            c_d += c * 2;
            q = q * 3 % mod;
        }

        a = (a + a_d) % mod;
        b = (b + b_d) % mod;
        c = (c + c_d) % mod;
    }

    cout << c;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}