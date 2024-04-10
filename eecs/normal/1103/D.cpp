#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1000010;
int n, mark[maxn], ctz[1 << 11];
ll K, f[12][1 << 11], num[11], prod[1 << 11];
pair<ll, ll> a[maxn];
vector<array<int, 2>> tr;

char _buf[100000], *_op(_buf), *_ed(_buf);
#define gc (_op == _ed && (_ed = (_op = _buf) + fread(_buf, 1, 100000, stdin), _op == _ed) ? EOF : *_op++)

ll read() {
    ll x = 0; char ch = gc;
    while (ch < '0' || ch > '9') ch = gc;
    while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = gc;
    return x;
}

void chk(ll &x, ll y) {
    if (x > y) x = y;
}

int main() {
    n = read(), K = read();
    ll g = 0;
    for (int i = 1; i <= n; i++) {
        a[i].second = read(), g = __gcd(g, a[i].second);
    }
    if (g == 1) puts("0"), exit(0);
    for (int i = 1; i <= n; i++) {
        a[i].first = read();
    }
    double st = clock();
    vector<ll> V;
    for (ll i = 2; i * i <= g; i++) if (!(g % i)) {
        V.push_back(i);
        while (!(g % i)) g /= i;
    }
    if (g > 1) V.push_back(g);
    vector<ll> val;
    for (int i = 1; i <= n; i++) {
        ll x = 1;
        for (ll p : V) {
            while (!(a[i].second % p)) a[i].second /= p, x *= p;
        }
        val.push_back(a[i].second = x);
    }
    sort(val.begin(), val.end());
    val.resize(unique(val.begin(), val.end()) - val.begin());
    sort(a + 1, a + n + 1);
    assert(V.size() <= 11);
    memset(f, 0x3f, sizeof(f)), f[0][0] = 0;
    for (int i = 0; i < 1 << V.size(); i++) {
        ctz[i] = __builtin_ctz(i);
    }
    for (int i = 0; i < 1 << V.size(); i++) {
        int S = ((1 << V.size()) - 1) ^ i;
        for (int T = S; T; T = (T - 1) & S) tr.push_back({i, T});
    }
    for (int i = 1; i <= n; i++) {
        int pos = lower_bound(val.begin(), val.end(), a[i].second) - val.begin();
        if (++mark[pos] > V.size() || (clock() - st) / CLOCKS_PER_SEC > 2.5) continue;
        for (int j = 0; j < V.size(); j++) {
            num[j] = 1;
            while (!(a[i].second % V[j])) a[i].second /= V[j], num[j] *= V[j];
        }
        bool flag = 0;
        for (int j = prod[0] = 1; j < 1 << V.size(); j++) {
            prod[j] = prod[j ^ (1 << ctz[j])] * num[ctz[j]];
            if (prod[j] <= K) flag = 1;
        }
        if (!flag) continue;
        for (int j = V.size() - 1; ~j; j--) {
            for (auto &p : tr) if (prod[p[1]] <= K) {
                chk(f[j + 1][p[0] | p[1]], f[j][p[0]] + a[i].first);
            }
        }
    }
    ll ans = LLONG_MAX;
    for (int i = 1; i <= V.size(); i++) if (f[i][(1 << V.size()) - 1] < 1e18) {
        chk(ans, i * f[i][(1 << V.size()) - 1]);
    }
    printf("%lld\n", ans > 1e18 ? -1 : ans);
    return 0;
}