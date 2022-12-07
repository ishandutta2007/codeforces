#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
char s[100005];
int a[100000], ac = 0;

int main() {
    scanf("%d%d%s", &n, &k, s);
    ++k;
    REP(i, n) if (s[i] == '0') {
        a[ac++] = i;
    }
    n = ac;
    int ans = 1e9;
    for (int i = 0; i + k <= n; ++i) {
        int ind = lower_bound(a + i, a + i + k, (a[i] + a[i + k - 1]) / 2) - a;
        int from = max(ind - 3, i);
        int to = min(ind + 3, i + k - 1);
        for (int j = from; j <= to; ++j) {
            ans = min(ans, max(abs(a[j] - a[i]), abs(a[j] - a[i + k - 1])));
        }
    }
    printf("%d\n", ans);
    return 0;
}