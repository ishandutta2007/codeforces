#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = 1e9 + 7;
const int CNT = 10000000;
int n;
vector<int> p;
bool pr[CNT], odd[CNT];
int cnt[CNT] = {}, acnt[CNT], pre[CNT];
vector<int> t;
int p2[500001];

inline void modAdd(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

int mul[555];

int main() {
    REP(i, CNT) pr[i] = odd[i] = true;
    pr[0] = pr[1] = false;
    for (int i = 2; i <= 10000; ++i) if (pr[i]) {
        for (int j = i * i; j < CNT; j += i) if (pr[j]) {
            pr[j] = false;
            pre[j] = j / i;
        }
    }
    for (int i = 2; i < CNT; ++i) if (!pr[i]) {
        odd[i] = !odd[pre[i]];
    }
    REP(i, CNT) if (pr[i]) p.pb(i);
    scanf("%d", &n);
    p2[0] = 1;
    for (int i = 1; i <= n; ++i) {
        p2[i] = p2[i - 1] << 1;
        if (p2[i] >= MOD) p2[i] -= MOD;
    }
    REP(i, n) {
        int x;
        scanf("%d", &x);
        t.clear();
        for (int j = 0; p[j] * p[j] <= x; ++j) if (x % p[j] == 0) {
            x /= p[j];
            t.pb(p[j]);
            while (x % p[j] == 0) {
                x /= p[j];
            }
        }
        if (x > 1) t.pb(x);
        int sz = (int)t.size();
        mul[0] = 1;
        for (int mask = 1; mask < (1 << sz); ++mask) {
            REP(j, sz) if (mask & (1 << j)) {
                mul[mask] = mul[mask ^ (1 << j)] * t[j];
                break;
            }
            ++cnt[mul[mask]];
        }
    }
    REP(i, CNT) acnt[i] = odd[i] ? cnt[i] : (-cnt[i]);
    REP(i, CNT) cnt[i] = p2[cnt[i]] - 1;
    REP(i, CNT) if (cnt[i] && !odd[i]) cnt[i] = MOD - cnt[i];
    for (int x : p) {
        int cumul = 1;
        for (int i = 2; i * x < CNT; ++i) {
            if (++cumul == x) {
                cumul = 0;
                continue;
            }
            acnt[i * x] += acnt[i];
            modAdd(cnt[i], cnt[i * x]);
        }
    }
    REP(i, CNT) if (cnt[i] && !odd[i]) cnt[i] = MOD - cnt[i];
    REP(i, CNT) if (cnt[i]) cnt[i] = (LL)cnt[i] * (n - acnt[i]) % MOD;
    int ans = 0;
    REP(i, CNT) {
        ans += cnt[i];
        if (ans >= MOD) ans -= MOD;
    }
    printf("%d\n", ans);
    return 0;
}