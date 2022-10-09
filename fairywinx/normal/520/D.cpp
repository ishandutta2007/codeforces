#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();
#define int long long

using namespace std;

map<pair<int, int>, int> cnt;
const int mod = 1e9 + 9;

int powm(int a, int b) {
    if (b == 0)
        return 1;
    if (b % 2 == 1) {
        return 1ll * a * powm(a, b - 1) % mod;
    } else {
        long long z = powm(a, b / 2);
        return z * z % mod;
    }
}

bool good(int x, int y) {
    if (!cnt[{x, y}])
        return false;
    if (cnt[{x, y + 1}] && !cnt[{x - 1, y}] && !cnt[{x + 1, y}])
        return false;
    if (cnt[{x + 1, y + 1}] && !cnt[{x + 1, y}] && !cnt[{x + 2, y}])
        return false;
    if (cnt[{x - 1, y + 1}] && !cnt[{x - 1, y}] && !cnt[{x - 2, y}])
        return false;
    return true;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        cnt[{a[i].first, a[i].second}] = i + 1;
    }
    set<array<int, 3>> s;
    for (int i = 0; i < n; ++i) {
        if (good(a[i].first, a[i].second)) {
            s.insert({i, a[i].first, a[i].second});
        }
    }
    int len = n - 1;
    int ans = 0;
    int type = 0;
    while (s.size()) {
        array<int, 3> z;
        if (type == 0)
            z = *s.rbegin();
        else
            z = *s.begin();
        s.erase(z);
        if (!good(z[1], z[2]))
            continue;
        // cout << z[0] << ' ' << z[1] << ' ' << z[2] << '\n';
        type ^= 1;
        cnt[{z[1], z[2]}] = 0;
        ans = (ans + 1ll * z[0] * powm(n, len)) % mod;
        --len;

        if (good(z[1], z[2] - 1)) {
            s.insert({cnt[{z[1], z[2] - 1}] - 1, z[1], z[2] - 1});
        }
        if (good(z[1] - 1, z[2] - 1)) {
            s.insert({cnt[{z[1] - 1, z[2] - 1}] - 1, z[1] - 1, z[2] - 1});
        }
        if (good(z[1] + 1, z[2] - 1)) {
            s.insert({cnt[{z[1] + 1, z[2] - 1}] - 1, z[1] + 1, z[2] - 1});
        }
    }
    cout << ans << '\n';
}