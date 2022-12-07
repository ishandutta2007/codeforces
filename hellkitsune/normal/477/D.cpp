#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int n, a[5000];
string s;
int d[5000][5000] = {};
short e[5000][5000];
int fen[5000][5000] = {};
short fen2[5000][5000];
char st[13][13000000];
int off[5000];
int ln[5001];

const int MOD = 1e9 + 7;
const short INF = 10000;

inline void modAdd(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

void fenAdd(int *fen, int pos, int val) {
    for (; pos < n; pos |= pos + 1)
        modAdd(fen[pos], val);
}

int fenGet(int *fen, int pos) {
    int ret = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
        modAdd(ret, fen[pos]);
    return ret;
}

void fen2Upd(short *fen, int pos, short val) {
    for (; pos < n; pos |= pos + 1)
        fen[pos] = min(fen[pos], val);
}

short fen2Get(short *fen, int pos) {
    short ret = INF;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
        ret = min(ret, fen[pos]);
    return ret;
}

void stBuild() {
    for (int i = 1, l = 0; i <= n; ++i) {
        if (i == (1 << (l + 1)))
            ++l;
        ln[i] = l;
    }
    off[0] = 0;
    for (int i = 1; i < n; ++i) off[i] = off[i - 1] + n + 1 - i;
    REP(i, n) for (int j = i; j < n; ++j) if (a[i] < a[j])
        st[0][off[i] + j - i] = '<';
    else if (a[i] == a[j])
        st[0][off[i] + j - i] = '=';
    else
        st[0][off[i] + j - i] = '>';
    for (int k = 1; k < 13; ++k) {
        int nn = n - (1 << k) + 1;
        REP(i, nn) for (int j = i; j < nn; ++j)
        if (st[k - 1][off[i] + j - i] == '=') {
            st[k][off[i] + j - i] = st[k - 1][off[i + (1 << (k - 1))] + j - i];
        } else {
            st[k][off[i] + j - i] = st[k - 1][off[i] + j - i];
        }
    }
}

char cmp(int a, int b, int len) {
    int l = ln[len];
    if (st[l][off[a] + b - a] != '=') return st[l][off[a] + b - a];
    return st[l][off[a + len - (1 << l)] + b - a];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    n = (int)s.length();
    REP(i, n) a[i] = s[i] - '0';
    stBuild();
    REP(i, n) d[0][i] = 1;
    REP(i, n) REP(j, n) e[i][j] = INF;
    REP(i, n) REP(j, n) fen2[i][j] = INF;
    REP(i, n) e[0][i] = 1;
    REP(i, n - 1) fenAdd(fen[i], i + 1, 1);
    REP(i, n - 1) fen2Upd(fen2[i], i + 1, 1);
    for (int l = 1; l < n; ++l) if (a[l] == 1) for (int r = l; r < n; ++r) {
        if (l) {
            d[l][r] = fenGet(fen[l - 1], r - l);
            e[l][r] = min(INF, short(fen2Get(fen2[l - 1], r - l) + 1));
        }
        int len = r - l + 1;
        if (l >= len && cmp(l - len, l, len) != '>') {
            modAdd(d[l][r], d[l - len][l - 1]);
            e[l][r] = min(e[l][r], short(e[l - len][l - 1] + 1));
        }
        if (r != n - 1) {
            fenAdd(fen[r], r - l + 1, d[l][r]);
            fen2Upd(fen2[r], r - l + 1, e[l][r]);
        }
    }
    int ans = 0;
    REP(i, n) modAdd(ans, d[i][n - 1]);
    cout << ans << '\n';
    bool found = false;
    int best = 1e9;
    for (int i = n - 1; i >= 0; --i) {
        if (found && n - i > 20) break;
        if (e[i][n - 1] != INF) {
            int cur = 0;
            for (int j = i; j < n; ++j)
                cur = (2 * cur + a[j]) % MOD;
            cur += e[i][n - 1];
            if (!found) {
                found = true;
                best = cur;
            } else if (cur < best) {
                best = cur;
            }
        }
    }
    cout << best << '\n';
    return 0;
}