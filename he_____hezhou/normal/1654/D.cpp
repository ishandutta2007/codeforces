#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
typedef long long ll;
int power(int a, int b) {
    long long res = a, ans = 1;
    for (; b; b >>= 1, res = res * res % mod) if (b & 1) ans = ans * res % mod;
    return ans;
}
int np[200010], prime[200010], cnt;
int n;
int x[200010], y[200010];
int sum;
vector < int > qwqx[200010], qwqy[200010];
vector < pair < int, int > > son[200010];
vector < int > calc(int x) {
    vector < int > ans;
    while (x > 1) ans.push_back(np[x]), x /= np[x];
    return ans;
}
int cur[200010], _max[200010];
void del(vector < int > &a) {
    for (auto i : a) cur[i]--;
}
void add(vector < int > &a) {
    for (auto i : a) _max[i] = max(_max[i], ++cur[i]);
}
void dfs(int cur, int fa, int prod) {
    if ((sum += prod) >= mod) sum -= mod;
    for (auto i : son[cur]) if (i.first != fa) {
        int nxtprod, id = i.second;
        if (id > 0) {
            nxtprod = 1ll * prod * y[id] % mod * power(x[id], mod - 2) % mod;
            del(qwqy[id]);
            add(qwqx[id]);
        }
        else {
            id = -id;
            nxtprod = 1ll * prod * x[id] % mod * power(y[id], mod - 2) % mod;
            del(qwqx[id]);
            add(qwqy[id]);
            id = -id;
        }
        dfs(i.first, cur, nxtprod);
        if (id > 0) {
            del(qwqx[id]);
            add(qwqy[id]);
        }
        else {
            id = -id;
            del(qwqy[id]);
            add(qwqx[id]);
            id = -id;
        }
    }
}
void rmain() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) son[i].clear();
    for (int i = 1; i < n; i++) {
        int u, v, x, y;
        scanf("%d%d%d%d", &u, &v, &x, &y);
        ::x[i] = x;
        ::y[i] = y;
        qwqx[i] = calc(x);
        qwqy[i] = calc(y);
        son[u].push_back({v, i});
        son[v].push_back({u, -i});
    }
    sum = 0;
    for (int i = 1; i <= n; i++) cur[i] = _max[i] = 0;
    dfs(1, 0, 1);
    for (int i = 1; i <= n; i++) if (_max[i]) sum = 1ll * sum * power(i, _max[i]) % mod;
    printf("%d\n", sum);
}
int main() {
    for (int i = 2; i <= 200000; i++) {
        if (!np[i]) np[i] = i, prime[++cnt] = i;
        for (int j = 1; prime[j] * i <= 200000; j++) {
            np[i * prime[j]] = prime[j];
            if (i % prime[j] == 0) break;
        }
    }
    int T;
    scanf("%d", &T);
    while (T--) rmain();
}