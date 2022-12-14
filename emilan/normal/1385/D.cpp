#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)x.size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      x.begin(), x.end()
#define rall(x)     x.rbegin(), x.rend()
#define fi          first
#define se          second

string s;

int solve(int l, int r, char c) {
    if (l == r) return s[l] != c;

    int hd = (r - l + 1) / 2;
    int lc = hd - count(s.begin() + l, s.begin() + r - hd + 1, c);
    int rc = hd - count(s.begin() + l + hd, s.begin() + r + 1, c);

    return min(lc + solve(l + hd, r, c + 1), rc + solve(l, r - hd, c +
                1));
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("io\\in.txt", "r", stdin);
    freopen("io\\out.txt", "w", stdout);
#endif

    int tcs;
    cin >> tcs;
    while (tcs--) {
        int n;
        cin >> n;
        cin >> s;

        cout << solve(0, n - 1, 'a') << '\n';
    }

    return 0;
}