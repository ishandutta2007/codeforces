#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
inline int power(int a, int b) {
    long long res = a, ans = 1;
    for (; b; b >>= 1, res = res * res % mod) if (b & 1) ans = ans * res % mod;
    return ans;
}
struct node {
    int a, b, id, type;
    friend inline int operator < (const node &a, const node &b) {
        return 1ll * a.a * b.b > 1ll * b.a * a.b;
    }
};
priority_queue < node > q;
int n;
int v[100010], x[100010], p[100010];
int prodp[100010], prod1p[100010], now[100010], ans, fa[100010], rest, vis[100010];
int qd[100010];
inline int gf(int a) {
    return fa[a] == a ? a : fa[a] = gf(fa[a]);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", x + i, v + i, p + i);
        p[i] = 1ll * p[i] * power(100, mod - 2) % mod;
        fa[i] = i;
        prodp[i] = p[i];
        prod1p[i] = (1 - p[i] + mod) % mod;
        now[i] = 1;
    }
    for (int i = 1; i < n; i++) {
        q.push(node{x[i + 1] - x[i], v[i + 1] + v[i], i, 0});
        if (v[i] != v[i + 1]) q.push(node{x[i + 1] - x[i], abs(v[i + 1] - v[i]), i, 1});
    }
    rest = 1;
    while (!q.empty()) {
        node nown = q.top();
        q.pop();
        // cerr << nown.id << ' ' << nown.type << endl;
        int id = nown.id, x = 1ll * nown.a * power(nown.b, mod - 2) % mod;
        if (nown.type == 0) {
            vis[id] = 1;
            int l = gf(id), r = gf(id + 1);
            if (qd[id] == 'l' || qd[id + 1] == 'r') {
                continue;
            }
            if (qd[id] == 'r' && qd[id + 1] == 'l') {
                ans = (ans + 1ll * rest * x) % mod;
                return cout << ans << endl, 0;
            }
            if (qd[id] == 'r') {
                int tmp = rest;
                rest = 1ll * rest * prodp[r] % mod * power(now[r], mod - 2) % mod;
                ans = (ans + 1ll * (tmp - rest + mod) * x) % mod;
                for (int i = id + 1; vis[i - 1]; i++) {
                    if (qd[i] == 'l') return cout << ans << endl, 0;
                    qd[i] = 'r';
                }
                fa[r] = l;
            }
            else if (qd[id + 1] == 'l') {
                int tmp = rest;
                rest = 1ll * rest * prod1p[l] % mod * power(now[l], mod - 2) % mod;
                ans = (ans + 1ll * (tmp - rest + mod) * x) % mod;
                for (int i = id; i && vis[i]; i--) {
                    if (qd[i] == 'r') return cout << ans << endl, 0;
                    qd[i] = 'l';
                }
                fa[l] = r;
            }
            else {
                int tmp = rest;
                fa[l] = r;
                rest = 1ll * rest * power(now[l], mod - 2) % mod * power(now[r], mod - 2) % mod;
                now[r] = (1ll * now[r] * prod1p[l] + 1ll * now[l] * prodp[r] + mod - 1ll * prodp[r] * prod1p[l] % mod) % mod;
                rest = 1ll * rest * now[r] % mod;
                prodp[r] = 1ll * prodp[r] * prodp[l] % mod;
                prod1p[r] = 1ll * prod1p[r] * prod1p[l] % mod;
                ans = (ans + 1ll * (tmp - rest + mod) * x) % mod;
            }
        }
        else {
            int f = gf(id);
            if (v[id] > v[id + 1]) {
                int i, tmp = rest;
                for (i = id; i && vis[i]; i--) {
                    if (qd[i] == 'r') return cout << (ans + 1ll * rest * x) % mod, 0;
                    if (qd[i] == 'l') break;
                }
                rest = 1ll * rest * power(now[f], mod - 2) % mod;
                for (; i++ != id; ) {
                    qd[i] = 'l';
                    rest = 1ll * rest * (mod + 1 - p[i]) % mod;
                    now[f] = 1ll * power(mod + 1 - p[i], mod - 2) * (now[f] - prodp[f] + mod) % mod;
                    prodp[f] = 1ll * prodp[f] * power(p[i], mod - 2) % mod;
                    prod1p[f] = 1ll * prod1p[f] * power(mod + 1 - p[i], mod - 2) % mod;
                }
                rest = 1ll * rest * now[f] % mod;
                ans = (ans + 1ll * (tmp - rest + mod) * x) % mod;
            }
            else {
                int i, tmp = rest;
                for (i = id + 1; vis[i - 1]; i++) {
                    if (qd[i] == 'l') return cout << (ans + 1ll * rest * x) % mod << endl, 0;
                    if (qd[i] == 'r') break;
                }
                rest = 1ll * rest * power(now[f], mod - 2) % mod;
                for (; i-- != id + 1; ) {
                    qd[i] = 'r';
                    rest = 1ll * rest * p[i] % mod;
                    now[f] = 1ll * power(p[i], mod - 2) * (now[f] - prod1p[f] + mod) % mod;
                    prodp[f] = 1ll * prodp[f] * power(p[i], mod - 2) % mod;
                    prod1p[f] = 1ll * prod1p[f] * power(mod + 1 - p[i], mod - 2) % mod;
                }
                rest = 1ll * rest * now[f] % mod;
                ans = (ans + 1ll * (tmp - rest + mod) * x) % mod;
            }
        }
        // cerr << rest << endl;
    }
    return cout << ans << endl, 0;
}