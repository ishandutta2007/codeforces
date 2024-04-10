#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[18][200000], b[18][200000];
int sz[200001];

int getMax(int from, int to) {
    int h = sz[to - from + 1];
    return max(a[h][from], a[h][to - (1 << h) + 1]);
}

int getMin(int from, int to) {
    int h = sz[to - from + 1];
    return min(b[h][from], b[h][to - (1 << h) + 1]);
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a[0] + i);
    REP(i, n) scanf("%d", b[0] + i);
    REP(i, 17) REP(j, n - (2 << i) + 1) {
        a[i + 1][j] = max(a[i][j], a[i][j + (1 << i)]);
    }
    REP(i, 17) REP(j, n - (2 << i) + 1) {
        b[i + 1][j] = min(b[i][j], b[i][j + (1 << i)]);
    }
    int cur = 0;
    for (int i = 1; i <= n; ++i) {
        if ((2 << cur) < i) ++cur;
        sz[i] = cur;
    }
    LL ans = 0;
    REP(i, n) {
        int lo = i, hi = n, mid;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            if (getMax(i, mid) >= getMin(i, mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        int from = lo;
        lo = from, hi = n;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            if (getMax(i, mid) > getMin(i, mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        ans += lo - from;
    }
    cout << ans << endl;
    return 0;
}