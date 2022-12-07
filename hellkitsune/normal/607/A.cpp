#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[100000], b[100000];
PII p[100000];
int d[100000];

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d%d", &p[i].first, &p[i].second);
    sort(p, p + n);
    REP(i, n) a[i] = p[i].first, b[i] = p[i].second;
    REP(i, n) {
        int lo = -1, hi = i - 1, mid;
        while (lo < hi) {
            mid = (lo + hi + 1) >> 1;
            if (a[mid] < a[i] - b[i]) lo = mid;
            else hi = mid - 1;
        }
        if (lo == -1) d[i] = 1;
        else d[i] = 1 + d[lo];
    }
    int ans = 0;
    REP(i, n) ans = max(ans, d[i]);
    printf("%d\n", n - ans);
    return 0;
}