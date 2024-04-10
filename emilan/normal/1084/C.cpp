#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

const int mod = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    string s;
    cin >> s;
    ll ans = 1, cur = 1;
    for (char c : s) {
        if (c == 'a') cur++;
        else if (c == 'b') ans = ans * cur % mod, cur = 1;
    }
    cout << (ans * cur + mod - 1) % mod;
}