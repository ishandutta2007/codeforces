#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
int a[200000], ri[200000];

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) scanf("%d", a + i);
    ri[n - 1] = n;
    for (int i = n - 2; i >= 0; --i) {
        if (a[i + 1] == a[i]) {
            ri[i] = ri[i + 1];
        } else {
            ri[i] = i + 1;
        }
    }
    REP(i, m) {
        int from, to, x;
        scanf("%d%d%d", &from, &to, &x), --from, --to;
        if (a[from] == x) from = ri[from];
        if (from > to) {
            printf("-1\n");
        } else {
            printf("%d\n", from + 1);
        }
    }
    return 0;
}