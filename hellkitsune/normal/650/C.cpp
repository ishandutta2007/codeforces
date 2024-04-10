#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
vector<int> a[1000000], b[1000000];
vector<int> all;
int cnt;
vector<int> r[1000000], c[1000000];
int rr[1000000], cc[1000000];
int val[1000000];
vector<PII> pos[1000000];
bool rv[1000000] = {}, cv[1000000] = {};
queue<int> rq, cq;
vector<PII> cur;

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    REP(i, n) {
        a[i].resize(m);
        b[i].resize(m);
        REP(j, m) scanf("%d", &a[i][j]);
    }
    REP(i, n) REP(j, m) all.pb(a[i][j]);
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    REP(i, n) REP(j, m) {
        a[i][j] = lower_bound(all.begin(), all.end(), a[i][j]) - all.begin();
    }
    cnt = (int)all.size();
    REP(i, n) REP(j, m) {
        pos[a[i][j]].pb(mp(i, j));
    }
    memset(rr, -1, sizeof rr);
    memset(cc, -1, sizeof cc);
    REP(i, cnt) {
        for (PII x : pos[i]) b[x.first][x.second] = max(rr[x.first], cc[x.second]) + 1;
        for (PII x : pos[i]) {
            r[x.first].pb(x.second);
            c[x.second].pb(x.first);
        }
        for (PII x : pos[i]) if (!rv[x.first]) {
            int mx = b[x.first][x.second];
            rv[x.first] = cv[x.second] = true;
            rq.push(x.first);
            cq.push(x.second);
            cur.pb(mp(x.first, x.second));
            bool done = false;
            while (!done) {
                done = true;
                if (!rq.empty()) {
                    done = false;
                    int z = rq.front();
                    rq.pop();
                    for (int y : r[z]) {
                        mx = max(mx, b[z][y]);
                        cur.pb(mp(z, y));
                        if (!cv[y]) {
                            cv[y] = true;
                            cq.push(y);
                        }
                    }
                }
                if (!cq.empty()) {
                    done = false;
                    int z = cq.front();
                    cq.pop();
                    for (int y : c[z]) {
                        mx = max(mx, b[y][z]);
                        cur.pb(mp(y, z));
                        if (!rv[y]) {
                            rv[y] = true;
                            rq.push(y);
                        }
                    }
                }
            }
            for (PII y : cur) b[y.first][y.second] = mx;
            cur.clear();
        }
        for (PII x : pos[i]) {
            r[x.first].clear();
            c[x.second].clear();
            rv[x.first] = cv[x.second] = false;
        }
        for (PII x : pos[i]) {
            rr[x.first] = max(rr[x.first], b[x.first][x.second]);
            cc[x.second] = max(cc[x.second], b[x.first][x.second]);
        }
    }
    REP(i, n) {
        REP(j, m) printf("%d ", b[i][j] + 1);
        printf("\n");
    }
    return 0;
}