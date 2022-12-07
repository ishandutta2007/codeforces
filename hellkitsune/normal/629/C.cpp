#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
char s[100005];
int cnt[2005][2005];
const int MOD = 1e9 + 7;

inline void modAdd(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

int main() {
    scanf("%d%d", &n, &m);
    scanf("%s", s);
    cnt[0][0] = 1;
    REP(i, 2003) REP(j, 2003) if (cnt[i][j]) {
        modAdd(cnt[i + 1][j + 1], cnt[i][j]);
        if (j) modAdd(cnt[i + 1][j - 1], cnt[i][j]);
    }
    int worst = 0, cur = 0;
    REP(i, m) {
        cur += (s[i] == '(' ? 1 : -1);
        worst = min(worst, cur);
    }
    int ans = 0;
    for (int i = -worst; i <= n - m; ++i) for (int j = -worst; j <= i; ++j) {
        int rem = n - m - i;
        int opened = cur + j;
        if (opened <= rem) {
            ans = (ans + (LL)cnt[i][j] * cnt[rem][opened]) % MOD;
        }
    }
    printf("%d\n", ans);
    return 0;
}