#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

const int mod = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    ll f = 1;
    for (int i = 2; i <= n; i++) f = f * i % mod;

    ll p2 = 1;
    for (int i = 1; i < n; i++) p2 = p2 * 2 % mod;

    cout << (f - p2 + mod) % mod;

    return 0;
}