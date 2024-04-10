#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int M = 10000005;
int n;
int eu[M];
bool pr[M];
int u[M] = {};

int main() {
    forn(i, M) pr[i] = true;
    pr[0] = pr[1] = false;
    forn(i, 10000) if (pr[i]) {
        for (int j = i * i; j < M; j += i) {
            pr[j] = false;
        }
    }
    forn(i, M) eu[i] = 1;
    eu[1] = 0;
    forn(i, M) if (pr[i]) {
        for (LL x = i; x < M; x *= i) {
            if (x == i) {
                for (int y = x; y < M; y += x) {
                    eu[y] *= i - 1;
                }
            } else {
                for (int y = x; y < M; y += x) {
                    eu[y] *= i;
                }
            }
        }
    }
    int n;
    cin >> n;
    if (n < 4) {
        cout << 0 << endl;
        return 0;
    }
    int mx = n / 2;
    int cnt = 0;
    for (int i = mx + 1; i <= n; ++i) {
        cnt += pr[i];
    }
    LL ans = (LL)(n - 1) * (n - 2) / 2;
    ans -= (LL)cnt * (cnt - 1) / 2;
    ans -= (LL)cnt * (n - 1 - cnt);
    int bad = 1;
    for (int i = 2; i <= n; ++i) {
        if (i > mx && pr[i]) {
            ++bad;
            continue;
        }
        ans += eu[i] - bad;
    }

    int z = sqrt(n + 0.5) + 1;
    cnt = 0;
    int j = 2;
    for (int i = z; i <= n; ++i) if (pr[i]) u[i] = 1;
    for (int i = mx + 1; i <= n; ++i) if (pr[i]) u[i] = 1;
    int tmp = 0;
    for (int i = 2; i <= n; ++i) if (!u[i]) {
        ++tmp;
    }
    for (int i = mx; i >= z; --i) if (pr[i]) {
        ++cnt;
        while ((LL)j * i <= n) {
            if (pr[j]) for (int k = j; k <= n; k += j) {
                if (!u[k]) {
                    u[k] = 1;
                    --tmp;
                }
            }
            ++j;
        }
        ans += tmp;
    }
    ans += (LL)cnt * (cnt - 1) / 2;

    cout << ans << endl;
    return 0;
}