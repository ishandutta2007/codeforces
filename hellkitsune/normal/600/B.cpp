#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
int a[200000], b[200000];
int ans[200000];

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) scanf("%d", a + i);
    REP(i, m) scanf("%d", b + i);
    sort(a, a + n);
    REP(i, m) {
        int lo = -1, hi = n - 1, mid;
        while (lo < hi) {
            mid = (lo + hi + 1) >> 1;
            if (a[mid] <= b[i]) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        ans[i] = lo + 1;
    }
    REP(i, m) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}