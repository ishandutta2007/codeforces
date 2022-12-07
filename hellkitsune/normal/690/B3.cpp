#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
typedef pair<int, int> PII;

int n, m;
set<PII> have;
int x[200005], y[200005];
int mnx[100005], mxx[100005], mny[100005], mxy[100005];

inline bool check(int x, int y) {
    return have.find(mp(x, y)) != have.end();
}

bool cw(const PII &a, const PII &b, const PII &c) {
    return (LL)(b.first - a.first) * (c.second - a.second) - (LL)(b.second - a.second) * (c.first - a.first) < 0;
}

vector<PII> hull(vector<PII> p) {
    int n = p.size();
    if (n <= 1) return p;
    int k = 0;
    sort(p.begin(), p.end());
    vector<PII> q(n * 2);
    for (int i = 0; i < n; q[k++] = p[i++]) {
        while (k >= 2 && !cw(q[k - 2], q[k - 1], p[i])) {
            --k;
        }
    }
    for (int i = n - 2, t = k; i >= 0; q[k++] = p[i--]) {
        while (k > t && !cw(q[k - 2], q[k - 1], p[i])) {
            --k;
        }
    }
    q.resize(k - 1 - (q[0] == q[1]));
    return q;
}

int main() {
    //freopen("input.txt", "r", stdin);
    while (true) {
        scanf("%d%d", &n, &m);
        if (n == 0) break;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", x + i, y + i);
        }
        have.clear();
        for (int i = 0; i <= n; ++i) {
            mnx[i] = mny[i] = 1e9;
            mxx[i] = mxy[i] = -1e9;
        }
        for (int i = 0; i < m; ++i) {
            have.insert(mp(x[i], y[i]));
            mnx[y[i]] = min(mnx[y[i]], x[i] - 1);
            mxx[y[i]] = max(mxx[y[i]], x[i]);
            mny[x[i]] = min(mny[x[i]], y[i] - 1);
            mxy[x[i]] = max(mxy[x[i]], y[i]);
        }
        //cerr << mxx << ' ' << mxy << endl;
        vector<PII> bad;
        for (int i = 0; i < m; ++i) {
            bad.pb(mp(x[i], y[i]));
            bad.pb(mp(x[i] - 1, y[i]));
            bad.pb(mp(x[i], y[i] - 1));
            bad.pb(mp(x[i] - 1, y[i] - 1));
        }
        bad = hull(bad);
        set<PII> badSet;
        for (PII x : bad) badSet.insert(x);
        vector<PII> p;
        for (int i = 0; i < m; ++i) {
            int xx = x[i];
            int yy = y[i];
            int ch1 = check(xx, yy);
            int ch2 = check(xx + 1, yy);
            int ch3 = check(xx + 1, yy + 1);
            int ch4 = check(xx, yy + 1);
            int sum = ch1 + ch2 + ch3 + ch4;
            if (sum >= 3 && xx != mnx[yy] && xx != mnx[yy + 1] && yy != mny[xx] && yy != mny[xx + 1] &&
                xx != mxx[yy] && xx != mxx[yy + 1] && yy != mxy[xx] && yy != mxy[xx + 1]) {
                p.pb(mp(xx, yy));
            }

            xx = x[i] - 1;
            yy = y[i] - 1;
            ch1 = check(xx, yy);
            ch2 = check(xx + 1, yy);
            ch3 = check(xx + 1, yy + 1);
            ch4 = check(xx, yy + 1);
            sum = ch1 + ch2 + ch3 + ch4;
            if (sum >= 3 && xx != mnx[yy] && xx != mnx[yy + 1] && yy != mny[xx] && yy != mny[xx + 1] &&
                xx != mxx[yy] && xx != mxx[yy + 1] && yy != mxy[xx] && yy != mxy[xx + 1]) {
                p.pb(mp(xx, yy));
            }
        }
        p = hull(p);
        printf("%d\n", (int)p.size());
        for (PII z : p) {
            printf("%d %d\n", z.first, z.second);
        }
    }
    return 0;
}