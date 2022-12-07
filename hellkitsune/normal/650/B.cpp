#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, a, b, t;
char s[500005];
int x[1500005];
LL y[1500005], z[1500005];

int main() {
    scanf("%d%d%d%d", &n, &a, &b, &t);
    scanf("%s", s);
    REP(i, n) if (s[i] == 'w') x[i] = 1 + b;
    else x[i] = 1;
    REP(i, 2 * n) x[n + i] = x[i];
    int pos = 0, ans = 0, rem = t;
    while (pos < n) {
        if (rem < x[pos]) break;
        rem -= x[pos];
        ++ans;
        if (rem < a) break;
        rem -= a;
        ++pos;
    }
    if (ans == n) {
        printf("%d\n", n);
        return 0;
    }
    pos = n, rem = t;
    int cur = 0;
    while (pos > 0) {
        if (rem < x[pos]) break;
        rem -= x[pos];
        ++cur;
        if (rem < a) break;
        rem -= a;
        --pos;
    }
    ans = max(ans, cur);
    y[n] = z[n] = 0;
    for (int i = n + 1; i < 2 * n; ++i) {
        y[i] = y[i - 1] + x[i] + a;
        z[i] = z[i - 1] + x[i] + 2 * a;
    }
    for (int i = n - 1; i > 0; --i) {
        y[i] = y[i + 1] + x[i] + a;
        z[i] = z[i + 1] + x[i] + 2 * a;
    }
    int l = 1;
    for (int r = n + 1; r < 2 * n; ++r) {
        while (l < n && y[l] + z[r] + x[n] > t) ++l;
        if (l == n) break;
        ans = max(ans, r - l + 1);
    }
    int r = 2 * n - 1;
    for (int l = n - 1; l > 0; --l) {
        while (r > n && z[l] + y[r] + x[n] > t) --r;
        if (r == n) break;
        ans = max(ans, r - l + 1);
    }
    printf("%d\n", ans);
    return 0;
}