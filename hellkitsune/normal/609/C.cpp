#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[100000];

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    int tot = 0;
    REP(i, n) tot += a[i];
    int mn = tot / n;
    int cnt = tot % n;
    sort(a, a + n);
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        int cur = mn + (n - i <= cnt);
        ans += max(0, a[i] - cur);
    }
    printf("%d\n", ans);
    return 0;
}