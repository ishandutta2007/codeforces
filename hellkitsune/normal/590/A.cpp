#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[500005];

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    int ans = 0;
    for (int beg = 0; beg < n - 1; ) if (a[beg] != a[beg + 1]) {
        int end = beg + 1;
        while (end < n - 1 && a[end] != a[end + 1]) ++end;
        if (a[beg] != a[end - 1]) {
            for (int i = beg + 1; i < end; ++i) {
                a[i] = a[beg];
            }
            ans = max(ans, (end - beg) / 2);
        } else {
            int cnt = (end - beg + 1) >> 1;
            for (int i = beg + 1; i < beg + cnt; ++i) {
                a[i] = a[beg];
            }
            for (int i = beg + cnt; i < end; ++i) {
                a[i] = a[end];
            }
            ans = max(ans, (end - beg + 1) / 2 - 1);
        }
        beg = end;
    } else {
        ++beg;
    }
    printf("%d\n", ans);
    REP(i, n) printf("%d ", a[i]);
    printf("\n");
    return 0;
}