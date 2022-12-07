#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int d, n, m;
int l[100000], r[100001], t[100000], b[100001];
int x[100000], y[100000], xx[100000], yy[100000];

int main() {
    scanf("%d%d%d", &d, &n, &m);
    forn(i, d) {
        scanf("%d%d%d%d", x + i, y + i, xx + i, yy + i), --x[i], --y[i], --xx[i], --yy[i];
        ++l[min(x[i], xx[i])];
        ++r[max(x[i], xx[i])];
        ++t[min(y[i], yy[i])];
        ++b[max(y[i], yy[i])];
    }
    forn(i, 99999) {
        l[i + 1] += l[i];
        t[i + 1] += t[i];
    }
    for (int i = 99999; i > 0; --i) {
        r[i - 1] += r[i];
        b[i - 1] += b[i];
    }
    int cntl, cntr, cntt, cntb;
    cin >> cntl >> cntr >> cntt >> cntb;
    forn(i, d) {
        int val = max(x[i], xx[i]);
        if ((val == 0 ? 0 : l[val - 1]) - (x[i] != xx[i]) != cntl) continue;

        val = min(x[i], xx[i]);
        if (r[val + 1] - (x[i] != xx[i]) != cntr) continue;

        val = max(y[i], yy[i]);
        if ((val == 0 ? 0 : t[val - 1]) - (y[i] != yy[i]) != cntt) continue;

        val = min(y[i], yy[i]);
        if (b[val + 1] - (y[i] != yy[i]) != cntb) continue;

        cout << i + 1 << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}