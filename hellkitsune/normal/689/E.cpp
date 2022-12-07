#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

struct Ev {
    int pos;
    bool st;
    Ev(int pos, bool st) : pos(pos), st(st) {}
    inline bool operator < (const Ev &rhs) const {
        return pos < rhs.pos;
    }
};

int n, k;
vector<Ev> ev;

int f[200005], rf[200005];
const int MOD = 1e9 + 7;

int c(int n, int k) {
    return (LL)f[n] * rf[k] % MOD * rf[n - k] % MOD;
}

int binPow(LL x, int p) {
    LL res = 1;
    while (p) {
        if (p & 1) res = res * x % MOD;
        p >>= 1;
        if (p) x = x * x % MOD;
    }
    return (int)res;
}

int main() {
    f[0] = rf[0] = 1;
    for (int i = 1; i < 200005; ++i) {
        f[i] = (LL)f[i - 1] * i % MOD;
        rf[i] = binPow(f[i], MOD - 2);
    }
    scanf("%d%d", &n, &k);
    REP(i, n) {
        int from, to;
        scanf("%d%d", &from, &to);
        ev.pb(Ev(from, true));
        ev.pb(Ev(to + 1, false));
    }
    int pre = -1e9 - 1234;
    sort(ev.begin(), ev.end());
    int cnt = 0;
    int ans = 0;
    for (Ev e : ev) {
        if (cnt >= k) {
            ans = (ans + (LL)c(cnt, k) * (e.pos - pre)) % MOD;
        }
        pre = e.pos;
        if (e.st) ++cnt;
        else --cnt;
    }
    printf("%d\n", ans);
    return 0;
}