#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int WWW = 3000000;
int n;
int cnt[WWW + 1] = {};
LL ans[WWW + 1] = {};

int main() {
    scanf("%d", &n);
    REP(i, n) {
        int x;
        scanf("%d", &x);
        if (x <= WWW) ++cnt[x];
    }
    for (int i = 1; i <= WWW; ++i) {
        for (int j = 1; i * j <= WWW; ++j) {
            if (i == j) {
                ans[i * j] += (LL)cnt[i] * (cnt[i] - 1);
            } else {
                ans[i * j] += (LL)cnt[i] * cnt[j];
            }
        }
    }
    REP(i, WWW) ans[i + 1] += ans[i];
    int qcnt;
    scanf("%d", &qcnt);
    REP(q, qcnt) {
        int x;
        scanf("%d", &x);
        printf("%I64d\n", (LL)n * (n - 1) - ans[x - 1]);
    }
    return 0;
}