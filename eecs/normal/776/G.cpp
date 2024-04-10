#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int q, a[20];
ll f[16][2][2];

int main() {
    ios::sync_with_stdio(0);
    cin >> q;
    auto solve = [&](string n) {
        while (n.size() < 15) n.insert(n.begin(), '0');
        for (int i = 0; i < 15; i++) {
            if (isdigit(n[i])) a[i] = n[i] - '0';
            else a[i] = n[i] - 'a' + 10;
        }
        ll ans = 0;
        for (int mx = 0; mx < 16; mx++) {
            memset(f, 0, sizeof(f)), f[0][0][0] = 1;
            for (int i = 0; i < 15; i++) {
                for (int j : {0, 1}) for (int k : {0, 1}) if (f[i][j][k]) {
                    for (int x = 0; x <= min(mx, k ? 15 : a[i]); x++) {
                        if (mx == 4 * (14 - i) && !(x & 1)) continue;
                        if (mx == 4 * (14 - i) + 1 && !(x & 2)) continue;
                        if (mx == 4 * (14 - i) + 2 && !(x & 4)) continue;
                        if (mx == 4 * (14 - i) + 3 && !(x & 8)) continue;
                        f[i + 1][j | (x == mx)][k | (x < a[i])] += f[i][j][k];
                    }
                }
            }
            ans += f[15][1][0] + f[15][1][1];
        }
        return ans;
    };
    while (q--) {
        string l, r;
        cin >> l >> r;
        int pos = l.size() - 1;
        while (pos >= 0 && l[pos] == '0') pos--;
        ll ans = solve(r);
        if (pos >= 0) {
            if (l[pos] == 'a') l[pos] = '9';
            else l[pos]--;
            for (int i = pos + 1; i < l.size(); i++) l[i] = 'f';
            ans -= solve(l);
        }
        cout << ans << '\n';
    }
    return 0;
}