#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, a, b, c, d, start, len;
int t[300005], q[300005];
LL x[20][300005], y[20][300005];
int lg[300005];

vector<PII> ev;

void stBuild() {
    int cur = 0;
    forn(i, 300005) {
        if ((2 << cur) < i) {
            ++cur;
        }
        lg[i] = cur;
    }
    forn(i, 19) forn(j, n - (2 << i) + 2) {
        x[i + 1][j] = min(x[i][j], x[i][j + (1 << i)]);
        y[i + 1][j] = min(y[i][j], y[i][j + (1 << i)]);
    }
}

LL sxGet(int from, int to) {
    int lev = lg[to - from + 1];
    return min(x[lev][from], x[lev][to - (1 << lev) + 1]);
}

LL syGet(int from, int to) {
    int lev = lg[to - from + 1];
    return min(y[lev][from], y[lev][to - (1 << lev) + 1]);
}

int main() {
    scanf("%d%d%d%d%d%d%d", &n, &a, &b, &c, &d, &start, &len);
    forn(i, n) scanf("%d%d", t + i, q + i);
    forn(i, n) {
        ev.pb(mp(t[i] + 1, -1));
        ev.pb(mp(max(0, t[i] + 1 - len), 1));
    }
    ev.pb(mp(0, 0));
    forn(i, n) if (q[i] == 0) {
        x[0][i + 1] = x[0][i] - b;
        y[0][i + 1] = y[0][i] - d;
    } else {
        x[0][i + 1] = x[0][i] + a;
        y[0][i + 1] = y[0][i] + c;
    }
    stBuild();
    int from = 0;
    int to = 0;
    sort(ev.begin(), ev.end());
    forn(i, ev.size()) {
        PII p = ev[i];
        if (p.second == -1) {
            ++from;
        } else if (p.second == 1) {
            ++to;
        }
        if (i == (int)ev.size() - 1 || p.first != ev[i + 1].first) {
            LL bal = start;
            if (bal + sxGet(0, from) < 0) {
                continue;
            }
            bal += x[0][from];
            if (bal + syGet(from, to) - y[0][from] < 0) {
                continue;
            }
            cout << p.first << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}