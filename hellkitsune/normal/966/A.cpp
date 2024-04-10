#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int INF = int(1e9);

int n, m, cl, ce, v, q;
int l[100000], e[100000];

vector<int> getInds(int *a, int cnt, int y, int yy) {
    vector<int> res;
    int ind = lower_bound(a, a + cnt, y) - a;
    if (ind != 0) {
        res.pb(ind - 1);
    }
    if (ind != cnt) {
        res.pb(ind);
    }
    ind = lower_bound(a, a + cnt, yy) - a;
    if (ind != 0) {
        res.pb(ind - 1);
    }
    if (ind != cnt) {
        res.pb(ind);
    }
    return res;
}

int main() {
    scanf("%d%d%d%d%d", &n, &m, &cl, &ce, &v);
    forn(i, cl) scanf("%d", l + i);
    forn(i, ce) scanf("%d", e + i);
    scanf("%d", &q);
    forn(_, q) {
        int x, y, xx, yy;
        scanf("%d%d%d%d", &x, &y, &xx, &yy);
        int ans = INF;
        if (x == xx) {
            ans = abs(y - yy);
        } else {
            if (cl != 0) {
                auto inds = getInds(l, cl, y, yy);
                for (int ind : inds) {
                    int coord = l[ind];
                    int cur = abs(y - coord);
                    cur += abs(x - xx);
                    cur += abs(yy - coord);
                    ans = min(ans, cur);
                }
            }
            if (ce != 0) {
                auto inds = getInds(e, ce, y, yy);
                for (int ind : inds) {
                    int coord = e[ind];
                    int cur = abs(y - coord);
                    cur += (abs(x - xx) + v - 1) / v;
                    cur += abs(yy - coord);
                    ans = min(ans, cur);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}