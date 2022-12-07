#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
int p[2][100005];
const int MOD = 1e9 + 7;
int f[100005], rf[100005];

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

int rev25, rev26;

int ppn(int n, int k, int ans) {
    ans = (LL)ans * 26 % MOD;
    ans = (ans + (LL)c(n, k - 1) * p[0][n + 1 - k]) % MOD;
    return ans;
}

vector<int> pos[100005];
int a[100000], b[100000];
char st[100005];

bool cmp(const int &lhs, const int &rhs) {
    return a[lhs] < a[rhs];
}

int res[100000];

int main() {
    f[0] = rf[0] = 1;
    for (int i = 1; i < 100005; ++i) {
        f[i] = (LL)f[i - 1] * i % MOD;
        rf[i] = binPow(f[i], MOD - 2);
    }
    rev25 = binPow(25, MOD - 2);
    rev26 = binPow(26, MOD - 2);
    REP(i, 2) {
        p[i][0] = 1;
        REP(j, 100003) p[i][j + 1] = (LL)p[i][j] * (25 + i) % MOD;
    }
    /*n = 5, k = 2;

    int ans = 0;
    for (int z = k; z <= n; ++z) {
        ans = (ans + (LL)c(z - 1, k - 1) * p[0][z - k] % MOD * p[1][n - z]) % MOD;
    }*/

    int m;
    scanf("%d%s", &m, st);
    int n, k;
    k = strlen(st);
    REP(i, m) {
        int qt;
        scanf("%d", &qt);
        if (qt == 1) {
            scanf("%s", st);
            k = strlen(st);
            a[i] = b[i] = -1;
        } else {
            scanf("%d", &n);
            a[i] = n;
            b[i] = k;
            pos[b[i]].pb(i);
        }
    }
    REP(i, 100001) sort(pos[i].begin(), pos[i].end(), cmp);
    REP(k, 100001) if (!pos[k].empty()) {
        int n = k, ans = 0;
        for (int z = k; z <= n; ++z) {
            ans = (ans + (LL)c(z - 1, k - 1) * p[0][z - k] % MOD * p[1][n - z]) % MOD;
        }
        for (int x : pos[k]) {
            while (n < a[x]) {
                ans = ppn(n, k, ans);
                ++n;
            }
            if (a[x] < k) {
                res[x] = 0;
            } else {
                res[x] = ans;
            }
        }
    }
    REP(i, m) if (a[i] != -1) printf("%d\n", res[i]);
    return 0;
}