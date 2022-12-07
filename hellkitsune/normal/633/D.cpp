#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[1000], b[1000], c[1000], cnt = 0;
vector<int> r;

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    sort(a, a + n);
    b[0] = a[0], c[0] = 1;
    cnt = 1;
    for (int i = 1; i < n; ++i) if (a[i] == a[i - 1]) {
        ++c[cnt - 1];
    } else {
        b[cnt] = a[i];
        c[cnt] = 1;
        ++cnt;
    }
    n = cnt;
    int ans = 2;
    REP(i, n) if (b[i] == 0) ans = max(ans, c[i]);
    REP(i, n) REP(j, n) {
        if (b[i] == 0 && b[j] == 0) continue;
        if (i == j && c[i] < 2) continue;
        r.pb(i);
        r.pb(j);
        --c[i];
        --c[j];
        int x = b[i], y = b[j];
        while (true) {
            int z = x;
            x = y;
            y += z;
            int ind = lower_bound(b, b + n, y) - b;
            if (ind == n || b[ind] != y || c[ind] == 0) break;
            --c[ind];
            r.pb(ind);
        }
        ans = max(ans, (int)r.size());
        for (int ind : r) ++c[ind];
        r.clear();
    }
    printf("%d\n", ans);
    return 0;
}