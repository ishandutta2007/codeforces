#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int T, cnt;
ll cur, f[110][110];

int main() {
    ios::sync_with_stdio(0);
    fill(f[0], f[0] + 110, 1);
    for (int i = 1; i <= 105; i++) {
        for (int j = 0; j <= 105; j++) {
            f[i][j] = min((ll)1e15, (j ? f[i - 1][j - 1] : 0) + f[i - 1][j + 1]);
        }
    }
    auto ask = [&](ll x) {
        assert(++cnt <= 100);
        cout << "? " << x << endl;
        string s; cin >> s;
        if (s[0] == 'L') cur += x;
        else assert(cur >= x), cur -= x;
        return s[0] == 'L';
    };
    auto solve = [&]() {
        cur = 1, cnt = 0;
        ll lb = 1, rb;
        while (lb <= (ll)1e14 && ask(lb)) lb <<= 1;
        rb = min((ll)1e14, lb - 1), lb >>= 1;
        if (!lb) return 0LL;
        if (!ask(lb)) return lb;
        ask(lb), ask(lb), ask(lb);
        int y = 0;
        while (lb < rb) {
            int x = 100 - cnt;
            if (!y) {
                if (!ask(lb)) return lb;
                y++;
            } else {
                ll pos = min((lb + rb + 1) >> 1, lb + f[x - 1][y - 1]);
                if (!ask(pos)) rb = pos - 1, y--;
                else lb = pos, y++;
            }
        }
        return lb;
    };
    cin >> T;
    while (T--) cout << "! " << solve() << endl;
    return 0;
}