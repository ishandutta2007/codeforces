#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
#define pb push_back
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int N = 201;
int sz;
LL mat[N][N] = {}, res[N][N] = {}, tmp[N][N] = {}, tr[N][N];
const LL INF = 1e18;

void matMul(LL (&a)[N][N], LL (&b)[N][N]) {
    REP(i, sz) REP(j, sz) {
        tr[i][j] = b[j][i];
    }
    REP(i, sz) REP(j, sz) {
        LL res = -INF;
        REP(k, sz) {
            res = max(res, a[i][k] + tr[j][k]);
        }
        tmp[i][j] = res;
    }
    REP(i, sz) REP(j, sz) a[i][j] = tmp[i][j];
}

void matPow(LL p) {
    REP(i, sz) REP(j, sz) res[i][j] = i == j ? 0 : -INF;
    while (p) {
        if (p & 1) matMul(res, mat);
        p >>= 1;
        if (p) matMul(mat, mat);
    }
}

struct AC {
    int nx[205][26] = {};
    int suf[205], term[205];
    int q[205];
    int cnt = 1;

    void addString(string s, int val) {
        int pos = 0;
        for (char cc : s) {
            int c = cc - 'a';
            if (!nx[pos][c]) {
                nx[pos][c] = cnt++;
            }
            pos = nx[pos][c];
        }
        term[pos] += val;
    }

    void build() {
        q[0] = 0;
        for (int qh = 0, qt = 1; qh < qt; ++qh) {
            int v = q[qh];
            if (v != 0) term[v] += term[suf[v]];
            REP(i, 26) if (nx[v][i]) {
                q[qt++] = nx[v][i];
                if (v == 0) suf[nx[v][i]] = 0;
                else suf[nx[v][i]] = nx[suf[v]][i];
            } else {
                nx[v][i] = nx[suf[v]][i];
            }
        }
    }
};

int m;
LL n;
string s;
int a[205];
AC ac;

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);

    ios_base::sync_with_stdio(false);
    cin >> m >> n;
    REP(i, m) cin >> a[i];
    REP(i, m) {
        cin >> s;
        ac.addString(s, a[i]);
    }
    ac.build();

    sz = ac.cnt;
    REP(i, sz) REP(j, sz) mat[i][j] = -INF;
    REP(i, sz) REP(j, 26) if (ac.nx[i][j]) {
        mat[i][ac.nx[i][j]] = ac.term[ac.nx[i][j]];
    }
    matPow(n);
    LL ans = 0;
    REP(i, sz) ans = max(ans, res[0][i]);

    cout << ans << endl;
    return 0;
}