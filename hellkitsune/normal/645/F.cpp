#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k, q;
int a[200000];
int cnt[1000001] = {};
int mul[1000001];
bool p[2000];
vector<int> pr;
const int MOD = 1e9 + 7;
vector<int> di[1000001];
int f[2000005], rf[2000005];

int binPow(LL x, int p) {
    LL res = 1;
    while (p) {
        if (p & 1) res = res * x % MOD;
        p >>= 1;
        if (p) x = x * x % MOD;
    }
    return (int)res;
}

int c(int n, int k) {
    return (LL)f[n] * rf[k] % MOD * rf[n - k] % MOD;
}

int cc[200005];

bool used[1000001] = {};

int main() {
    //freopen("input.txt", "r", stdin);
    f[0] = rf[0] = 1;
    for (int i = 1; i < 2000005; ++i) {
        f[i] = (LL)f[i - 1] * i % MOD;
        rf[i] = binPow(f[i], MOD - 2);
    }
    REP(i, 2000) p[i] = true;
    p[0] = p[1] = false;
    REP(i, 2000) if (p[i]) {
        for (int j = i * i; j < 2000; j += i) {
            p[j] = false;
        }
    }
    REP(i, 2000) if (p[i]) pr.pb(i);
    scanf("%d%d%d", &n, &k, &q);
    REP(i, n + q) scanf("%d", a + i), used[a[i]] = true;
    for (int i = 1; i <= 1000000; ++i) { //ZZZZZ
        int rem = i;
        mul[i] = i;
        vector<int> v;
        for (int x : pr) {
            if (x * x > rem) break;
            if (rem % x == 0) {
                v.pb(x);
                rem /= x;
                while (rem % x == 0) {
                    rem /= x;
                }
            }
        }
        if (rem > 1) {
            v.pb(rem);
        }
        REP(mask, 1 << v.size()) if (mask) {
            int rem = i;
            REP(j, v.size()) if (mask & (1 << j)) {
                rem /= v[j];
            }
            if (__builtin_popcount(mask) & 1) {
                mul[i] -= rem;
            } else {
                mul[i] += rem;
            }
        }
        int j;
        if (used[i]) {
            for (j = 1; j * j < i; ++j) if (i % j == 0) {
                di[i].pb(j);
                di[i].pb(i / j);
            }
            if (j * j == i) {
                di[i].pb(j);
            }
        }
        mul[i] %= MOD;
        if (mul[i] < 0) mul[i] += MOD;
    }
    for (int i = 1; i <= 12; ++i) {
        //cout << i << ": " << mul[i] << endl;
    }
    LL ans = 0;
    for (int i = k; i < 200005; ++i) cc[i] = c(i, k);
    REP(i, n + q) {
        int val = a[i];
        for (int x : di[val]) {
            if (cnt[x] >= k) {
                ans -= (LL)mul[x] * cc[cnt[x]];
                if (ans < 0) ans += MOD;
            }
            if (++cnt[x] >= k) {
                ans += (LL)mul[x] * cc[cnt[x]];
            }
        }
        ans %= MOD;
        if (ans < 0) ans += MOD;
        if (i >= n) {
            printf("%d\n", (int)ans);
        }
    }
    return 0;
}