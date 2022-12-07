#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
vector<int> where[100005];
vector<int> g[100005];
bool done[100005] = {};
int d[2][2], nd[2][2];
int e[100005];
vector<PII> res;
const int MOD = 1e9 + 7;

inline void modAdd(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    forn(i, n) {
        int cnt;
        scanf("%d", &cnt);
        forn(j, cnt) {
            int x;
            scanf("%d", &x);
            g[i].pb(x);
            where[abs(x)].pb(i);
        }
    }
    forn(ii, 2 * n) if (!done[ii % n]) {
        int i = ii % n;
        if (ii < n) {
            int trs = 0;
            for (int x : g[i]) if (where[abs(x)].size() == 2) {
                ++trs;
            }
            if (trs == 2) continue;
        }
        vector<int> all, tr;
        bool cyc = false;
        int cycVar = -1;
        int firstVar = -1;
        for (int j = i; ; ) {
            done[j] = true;
            all.pb(j);
            int nx = -1;
            int curTr = -1;
            bool locCyc = false;
            for (int x : g[j]) {
                x = abs(x);
                for (int y : where[x]) if (!done[y] && nx == -1) {
                    nx = y;
                    if (j == i) firstVar = x;
                    curTr = x;
                } else if (y == i && x != firstVar) {
                    locCyc = true;
                    cycVar = x;
                }
            }
            if (nx == -1) {
                cyc = locCyc;
                break;
            }
            int dif = 0;
            for (int x : g[j]) if (abs(x) == curTr && x > 0) dif ^= 1;
            for (int x : g[nx]) if (abs(x) == curTr && x > 0) dif ^= 1;
            tr.pb(dif);
            j = nx;
        }
        for (int x : all) done[x] = true;
//        for (int x : all) cerr << x << ' ';
//        cerr << endl;
//        for (int x : tr) cerr << x << ' ';
//        cerr << endl;
//        cerr << "---" << endl;
        if ((int)all.size() == 1) {
            if ((int)g[i].size() == 1 || g[i][0] == g[i][1]) {
                res.pb(mp(1, 1));
            } else if (abs(g[i][0]) == abs(g[i][1])) {
                res.pb(mp(0, 2));
            } else {
                res.pb(mp(1, 3));
            }
        } else {
            int sz = (int)all.size();
            int zero = 0, one = 0;
            for (int c = 0; c < 2; ++c) for (int ce = 0; ce < 2; ++ce) {
                if (cyc && ce == 1) continue;
                if (!cyc) {
                    if (c == 1 && (int)g[all[0]].size() == 1) continue;
                    if (ce == 1 && (int)g[all.back()].size() == 1) continue;
                }
                for (int j = 0; j <= sz; ++j) e[j] = 0;
                if (cyc) {
                    for (int x : g[all[0]]) if (abs(x) == cycVar) {
                        e[0] = c ^ (x > 0);
                    }
                    for (int x : g[all.back()]) if (abs(x) == cycVar) {
                        e[sz - 1] = c ^ (x > 0);
                    }
                } else {
                    e[0] = c;
                    e[sz - 1] = ce;
                }
                d[0][0] = 1;
                d[0][1] = d[1][0] = d[1][1] = 0;
                for (int j = 0; j < sz - 1; ++j) {
                    nd[0][0] = nd[0][1] = nd[1][0] = nd[1][1] = 0;
                    forn(a, 2) forn(b, 2) {
                        int aa = a | e[j];
                        forn(c, 2) {
                            int na = c ^ tr[j];
                            int nb = b ^ (aa | c);
                            modAdd(nd[na][nb], d[a][b]);
                        }
                    }
                    memcpy(d, nd, sizeof d);
                }
                forn(a, 2) forn(b, 2) {
                    if ((e[sz - 1] | a) ^ b) modAdd(one, d[a][b]);
                    else modAdd(zero, d[a][b]);
                }
            }
            res.pb(mp(zero, one));
        }
    }
    //for (PII z : res) cerr << z.first << ' ' << z.second << endl;
    int z = 1, o = 0, nz, no;
    for (PII x : res) {
        nz = ((LL)z * x.first + (LL)o * x.second) % MOD;
        no = ((LL)o * x.first + (LL)z * x.second) % MOD;
        z = nz;
        o = no;
    }
    for (int i = 1; i <= m; ++i) if (where[i].empty()) {
        o = 2ll * o % MOD;
    }
    printf("%d\n", o);
    return 0;
}