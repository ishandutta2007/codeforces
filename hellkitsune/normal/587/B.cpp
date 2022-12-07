#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = 1e9 + 7;
int n, k;
LL l;
int a[1000001], d[1000001], acnt[1000001] = {};
int b[1000001], bcnt[1000001] = {};
vector<int> v;

inline void modAdd(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

int main() {
    cin >> n >> l >> k;
    REP(i, n) scanf("%d", a + i);
    REP(i, n) v.pb(a[i]);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    REP(i, n) b[i] = v[i];
    int sz = (int)v.size();
    REP(i, n) a[i] = lower_bound(b, b + sz, a[i]) - b;
    LL gr = l / n;
    int grm = gr % MOD + MOD;
    int last = l - gr * n;
    REP(i, last) b[i] = a[i];
    REP(i, n) ++acnt[a[i]];
    REP(i, last) ++bcnt[b[i]];
    d[0] = 1;
    int ans = 0;
    REP(i, k) {
        for (int j = 1; j < sz; ++j) {
            modAdd(d[j], d[j - 1]);
        }
        REP(j, sz) {
            ans = (ans + (LL)d[j] * bcnt[j]) % MOD;
        }
        if (i >= gr) break;
        int tot = 0;
        REP(j, sz) {
            d[j] = (LL)d[j] * acnt[j] % MOD;
            modAdd(tot, d[j]);
        }
        ans = (ans + (LL)tot * (grm - i)) % MOD;
    }
    printf("%d\n", ans);
    return 0;
}