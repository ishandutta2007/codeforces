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

const int maxn = 3e5 + 1, maxm = 1e6 + 1, maxk = 20;
int st[maxk][maxn];
vt<int> pos[maxm];

int query(int l, int r) {
    int k = __lg(r - l);
    return __gcd(st[k][l], st[k][r - (1 << k)]);
}

void solve() {
    int n;
    cin >> n;
    vt<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }

    copy(all(a), *st);
    for (int k = 1; k < maxk; k++) {
        for (int i = 0; i <= n - (1 << k); i++) {
            st[k][i] = __gcd(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
        }
    }
    
    auto check = [&](int s) {
        vt<int> ans;
        for (int i = 0; i <= n - s; i++) {
            int g = query(i, i + s);
            auto it = lower_bound(all(pos[g]), i);
            if (it != pos[g].end() && *it < i + s) ans.push_back(i + 1);
        }
        return ans;
    };
    int l = 1, r = n;
    while (l < r) {
        int mi = (l + r + 1) / 2;
        if (!check(mi).empty()) l = mi;
        else r = mi - 1;
    }

    vt<int> ans(check(l));
    cout << sz(ans) << ' ' << l - 1 << '\n';
    for (int x : ans) cout << x << ' ';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}