#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m, k, s;
int a[200000], b[200000];
vector<LL> c, d, cs, ds;
vector<int> cnum, dnum;
vector<pair<LL, int> > v;

void mySort(vector<LL> &c, vector<int> &cnum) {
    v.clear();
    REP(i, c.size()) v.pb(mp(c[i], cnum[i]));
    sort(v.begin(), v.end());
    REP(i, c.size()) {
        c[i] = v[i].first;
        cnum[i] = v[i].second;
    }
}

int main() {
    scanf("%d%d%d%d", &n, &m, &k, &s);
    REP(i, n) scanf("%d", a + i);
    REP(i, n) scanf("%d", b + i);
    REP(i, m) {
        int t, cost;
        scanf("%d%d", &t, &cost);
        if (t == 1) c.pb(cost), cnum.pb(i + 1);
        else d.pb(cost), dnum.pb(i + 1);
    }
    mySort(c, cnum);
    mySort(d, dnum);
    cs = c;
    ds = d;
    for (int i = 1; i < (int)c.size(); ++i) {
        cs[i] += cs[i - 1];
    }
    for (int i = 1; i < (int)d.size(); ++i) {
        ds[i] += ds[i - 1];
    }
    int e = 1e7, f = 1e7, ed = 0, fd = 0;
    REP(i, n) {
        if (a[i] < e) {
            e = a[i];
            ed = i + 1;
        }
        if (b[i] < f) {
            f = b[i];
            fd = i + 1;
        }
        int lo = max(0, k - (int)d.size()), hi = min(k, (int)c.size()), mid;
        while (lo < hi) {
            mid = (lo + hi + 1) >> 1;
            if (c[mid - 1] * e > d[k - mid] * f) hi = mid - 1;
            else lo = mid;
        }
        LL cost = (lo == 0 ? 0ll : cs[lo - 1]) * e + (lo == k ? 0ll : ds[k - lo - 1]) * f;
        if (cost <= s) {
            printf("%d\n", i + 1);
            REP(j, lo) {
                printf("%d %d\n", cnum[j], ed);
            }
            REP(j, k - lo) {
                printf("%d %d\n", dnum[j], fd);
            }
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}