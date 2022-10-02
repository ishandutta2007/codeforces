#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;


const int MAXN = 2007;
const int MAXQ = 1000 * 1000 + 7;
int xl[MAXN], xr[MAXN], yl[MAXN], yr[MAXN];
long long have[MAXN][MAXN];
vector<pair<int, int> > pts[MAXN][MAXN];
int type[MAXQ], pos[MAXQ];
char buf[107];
int qcnt = 1;
int n, m, k;
bool on[MAXN];


struct Event {
    int type;
    int l, r;
    int id;
    Event(){}
    Event(int _type, int _x) {
        type = _type;
        l = _x;
    }
    Event(int _type, int _l, int _r) {
        type = _type;
        l = _l;
        r = _r;
    }
    Event(int _type, int _l, int _r, int _id) {
        type = _type;
        l = _l;
        r = _r;
        id = _id;
    }
};


vector<Event> e[MAXN];
struct segmentTree {
    vector<long long>tree;
    int sz;
    segmentTree(int n) {
        tree.resize(n + 5);
        sz = n + 2;
    }
    void add(int v, int tl, int tr, int pos, long long val) {
        for (int i = pos; i < sz; i = i|(i + 1)) {
            tree[i] += val;
        }
    }
    long long get(int x) {
        long long ans = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
            ans += tree[i];
        }
        return ans;
    }
    long long getSum(int v, int tl, int tr, int l, int r) {
        return get(r) - get(l - 1);
    }
};


int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= k; i++) {
        on[i] = true;
        int len;
        scanf("%d", &len);
        for (int j = 1; j <= len; j++) {
            int x, y;
            int w;
            scanf("%d %d", &x, &y);
            scanf("%d", &w);
            pts[i][x].push_back(make_pair(y, w));
        }
    }
    int q;
    scanf("%d\n", &q);
    for (int qq = 1; qq <= q; qq++) {
        scanf("%s", buf);
        if (buf[0] == 'S') {
            type[qq] = 1;
            scanf("%d\n", &pos[qq]);
        } else {
            type[qq] = 2;
            scanf("%d %d %d %d\n", &xl[qcnt], &yl[qcnt], &xr[qcnt], &yr[qcnt]);
            qcnt++;
        }
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            e[j].clear();
        }
        for (int j = 1; j <= n; j++) {
            for (int p = 0; p < (int)pts[i][j].size(); p++) {
                e[j].push_back(Event(1, pts[i][j][p].first, pts[i][j][p].first, pts[i][j][p].second));
            }
        }
        for (int j = 1; j <= qcnt; j++) {
            e[xl[j] - 1].push_back(Event(3, yl[j], yr[j], j));
            e[xr[j]].push_back(Event(2, yl[j], yr[j], j));
        }
        segmentTree st(m + 1);
        for (int j = 0; j <= n; j++) {
            for (int p = 0; p < (int)e[j].size(); p++) {
                Event ee = e[j][p];
                if (ee.type == 1) {
                    st.add(1, 1, m, ee.l, ee.id);
                } else if (ee.type == 2) {
                    have[ee.id][i] += st.getSum(1, 1, m, ee.l, ee.r);
                } else {
                    have[ee.id][i] -= st.getSum(1, 1, m, ee.l, ee.r);
                }
            }
        }
    }
    qcnt = 1;
    for (int qq = 1; qq <= q; qq++) {
        if (type[qq] == 1) {
            on[pos[qq]] = !on[pos[qq]];
        } else {
            long long ans = 0;
            for (int j = 1; j <= k; j++) {
                if (on[j]) {
                    ans += have[qcnt][j];
                }
            }
            qcnt++;
            printf("%I64d\n", ans);
        }
    }
    return 0;
}