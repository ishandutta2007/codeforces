
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

const int mod = 998244353;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> a(n);
    a[0] = 10;
    ll cur = 10, tot = 20, ten = 100;
    for (int i = 1; i < n; i++) {
        a[i] = (((i + 1) * ten - tot) % mod + mod) % mod;
        ten = ten * 10 % mod;
        cur = (cur + a[i]) % mod;
        tot = (tot + a[i] + cur) % mod;
    }

    for (int i = n - 1; i >= 0; i--) cout << a[i] << ' ';

    return 0;
}