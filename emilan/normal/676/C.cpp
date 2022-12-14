#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, k;
    string s;
    cin >> n >> k >> s;

    auto f = [&](char c) {
        int ret = 0, l = 0, cnt = 0;
        for (int r = 0; r < n; r++) {
            if (s[r] != c) cnt++;
            while (cnt > k) {
                if (s[l] != c) cnt--;
                l++;
            }
            ret = max(ret, r - l + 1);
        }

        return ret;
    };
    cout << max(f('a'), f('b'));
}