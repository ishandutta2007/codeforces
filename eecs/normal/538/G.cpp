#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxL = 2000010;
int n, L;
ll tim[maxL], x[maxL];
bool vis[maxL];

int main() {
    scanf("%d %d", &n, &L), vis[0] = 1;
    vector<array<ll, 2>> X, Y;
    while (n--) {
        ll t, p, q;
        scanf("%lld %lld %lld", &t, &p, &q);
        if ((t + p + q) % 2) puts("NO"), exit(0);
        X.push_back({t, p + q}), Y.push_back({t, p - q});
    }
    auto solve = [&](vector<array<ll, 2>> X) {
        memset(vis, 0, sizeof(vis)), vis[0] = 1;
        ll lx = -L, rx = L;
        for (auto &p : X) {
            int t = p[0] % L;
            if (vis[t]) {
                if ((p[1] - x[t]) % (p[0] / L - tim[t])) puts("NO"), exit(0);
                ll v = (p[1] - x[t]) / (p[0] / L - tim[t]);
                lx = max(lx, v), rx = min(rx, v);
            } else {
                vis[t] = 1, tim[t] = p[0] / L, x[t] = p[1];
            }
        }
        auto ins = [&](ll foo, ll bar) { // foo * x <= bar
            if (!foo) {
                if (bar < 0) puts("NO"), exit(0);
            } else if (foo > 0) {
                ll x = bar / foo - 5;
                while (foo * (x + 1) <= bar) x++;
                rx = min(rx, x);
            } else {
                foo *= -1, bar *= -1;
                ll x = bar / foo - 5;
                while (foo * x < bar) x++;
                lx = max(lx, x);
            }
        };
        int lst = 0;
        for (int i = 1; i < L; i++) if (vis[i]) {
            ins(tim[lst] - tim[i], i - lst + x[lst] - x[i]);
            ins(tim[i] - tim[lst], i - lst + x[i] - x[lst]);
            lst = i;
        }
        ins(tim[lst] - tim[0] + 1, L - lst + x[lst] - x[0]);
        ins(tim[0] - tim[lst] - 1, L - lst + x[0] - x[lst]);
        if ((lx + L) % 2) lx++;
        if (lx > rx) puts("NO"), exit(0);
        x[L] = lx, vis[L] = 1, lst = 0;
        for (int i = 0; i < L; i++) {
            if (vis[i]) x[i] -= tim[i] * lx;
        }
        vector<int> res(L);
        for (int i = 1, cur = 0; i <= L; i++) if (vis[i]) {
            while (cur > x[i]) lst++, cur--;
            while (cur < x[i]) res[lst++] = 1, cur++;
            while (lst < i) res[lst] = 1, lst += 2;
        }
        return res;
    };
    auto move_x = solve(X), move_y = solve(Y);
    for (int i = 0; i < L; i++) {
        putchar("LDUR"[move_x[i] << 1 | move_y[i]]);
    }
    return 0;
}