#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[500000];
char s[500005];

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    scanf("%s", s);
    LL cur = 0;
    REP(i, n) if (s[i] == 'B') {
        cur += a[i];
    }
    LL ans = cur, save = cur;
    REP(i, n) {
        if (s[i] == 'A') cur += a[i];
        else cur -= a[i];
        ans = max(ans, cur);
    }
    cur = save;
    for (int i = n - 1; i > 0; --i) {
        if (s[i] == 'A') cur += a[i];
        else cur -= a[i];
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0;
}