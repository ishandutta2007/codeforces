#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

struct Ev {
    int pos, ind;
    bool st;
    Ev(int pos, int ind, bool st) : pos(pos), ind(ind), st(st) {}
    inline bool operator < (const Ev &rhs) const {
        return pos < rhs.pos;
    }
};

int n, k;
int x[100005], y[100005];
int all[200005], cnt;
vector<Ev> ev;
LL ans[100005] = {};
LL cur[100005] = {};
int z[200005];

int old, pos;

void add(int ind, int val) {
    ans[ind] = ans[ind] + old * cur[ind] + (cur[ind] + val) * (pos - old);
    cur[ind] += val;
    ans[ind] -= pos * cur[ind];
}

void sub(int ind, int val) {
    ans[ind] = ans[ind] + old * cur[ind] + (cur[ind] - val) * (pos - old);
    cur[ind] -= val;
    ans[ind] -= pos * cur[ind];
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &k);
    REP(i, n) scanf("%d%d", x + i, y + i);
    cnt = 0;
    REP(i, n) {
        all[cnt++] = x[i];
        all[cnt++] = x[i] + k;
    }
    sort(all, all + cnt);
    cnt = unique(all, all + cnt) - all;
    REP(i, n) {
        ev.pb(Ev(y[i], i, true));
        ev.pb(Ev(y[i] + k, i, false));
    }
    sort(ev.begin(), ev.end());
    REP(i, (int)ev.size() - 1) {
        Ev &e = ev[i];
        old = e.pos;
        pos = ev[i + 1].pos;
        int from = lower_bound(all, all + cnt, x[e.ind]) - all;
        int to = lower_bound(all, all + cnt, x[e.ind] + k) - all;
        for (int i = from; i < to; ++i) {
            if (z[i]) sub(z[i], all[i + 1] - all[i]);
            z[i] += e.st ? 1 : -1;
            if (z[i]) add(z[i], all[i + 1] - all[i]);
        }
    }
    pos = ev.empty() ? 0 : ev.back().pos;
    for (int i = 1; i <= n; ++i) ans[i] += pos * cur[i];
    for (int i = 1; i <= n; ++i) printf("%I64d ", ans[i]);
    printf("\n");
    return 0;
}