#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, t, tot;
int a[111];
const int S = 20000;
int d[111] = {}, cc[111] = {};
map<int, int> ma;
set<int> se;
int mac = 0;
int mx = 0;

int main() {
    scanf("%d%d", &n, &t);
    tot = n * t;
    REP(i, n) scanf("%d", a + i);
    REP(i, n) se.insert(a[i]);
    for (int x : se) ma[x] = mac++;
    REP(i, n) a[i] = ma[a[i]];
    int cnt = min(tot, S);
    while (cnt % n) ++cnt;
    REP(i, cnt) {
        int val = a[i % n];
        int cur = d[val] + 1;
        for (int j = val; j < n && d[j] < cur; ++j) {
            d[j] = cur;
        }
    }
    int times = (tot - 2 * cnt) / n - 1;
    times = max(times, 0);
    REP(i, n) ++cc[a[i]];
    REP(i, n) mx = max(mx, cc[i]);
    REP(i, n) if (cc[i] == mx) {
        d[i] += times * mx;
    }
    REP(i, n - 1) d[i + 1] = max(d[i + 1], d[i]);
    cnt += times * n;
    for (int i = cnt; i < tot; ++i) {
        int val = a[i % n];
        int cur = d[val] + 1;
        for (int j = val; j < n && d[j] < cur; ++j) {
            d[j] = cur;
        }
    }
    int ans = 0;
    REP(i, n) ans = max(ans, d[i]);
    printf("%d\n", ans);
    return 0;
}