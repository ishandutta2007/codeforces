#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, p;
int l[100001], r[100001], cnt[100001], tot[100001];

int main() {
    scanf("%d%d", &n, &p);
    REP(i, n) scanf("%d%d", l + i, r + i);
    REP(i, n) if (l[i] > r[i]) swap(l[i], r[i]);
    l[n] = l[0], r[n] = r[0];
    REP(i, n + 1) cnt[i] = r[i] / p - (l[i] - 1) / p;
    REP(i, n + 1) tot[i] = r[i] - l[i] + 1;
    double ans = 0;
    REP(i, n) {
        double p1 = (double)cnt[i] / tot[i];
        double p2 = (double)cnt[i + 1] / tot[i + 1];
        ans += 2000 * (p1 + p2 - p1 * p2);
    }
    printf("%.12f\n", ans);
    return 0;
}