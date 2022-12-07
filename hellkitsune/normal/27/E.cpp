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

int n;
int p[4], c[4], d[4][15], cnt = 0;
int v[100], vpos = 0;
int w[100];
bool pr[10000];
vector<int> vp;
LL INF = 2e18;
LL best = INF;

void go(int pos, int sub, int mx) {
    if (pos == cnt) {
        REP(i, vpos) w[i] = v[i];
        sort(w, w + vpos, greater<int>());
        bool flag = true;
        LL cur = 1;
        REP(i, vpos) if (flag) REP(j, w[i] - 1) {
            if (vp[i] > INF / cur) {
                flag = false;
                break;
            }
            cur *= vp[i];
        }
        if (flag) best = min(best, cur);
    }
    mx = min(mx, c[pos] - sub);
    for (int i = 1; i <= mx; ++i) {
        v[vpos++] = d[pos][i];
        if (i + sub == c[pos]) {
            go(pos + 1, 0, 100);
        } else {
            go(pos, sub + i, i);
        }
        --vpos;
    }
}

int main() {
    for (int i = 2; i < 10000; ++i) pr[i] = true;
    for (int i = 2; i < 1000; ++i) if (pr[i]) {
        for (int j = i * i; j < 10000; j += i)
            pr[j] = false;
    }
    for (int i = 2; i < 10000; ++i) if (pr[i])
        vp.pb(i);
    ios_base::sync_with_stdio(false);
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 2; i <= n; ++i) if (n % i == 0) {
        p[cnt] = i;
        c[cnt] = 0;
        while (n % i == 0) {
            ++c[cnt];
            n /= i;
        }
        d[cnt][0] = 1;
        for (int j = 1; j <= c[cnt]; ++j)
            d[cnt][j] = d[cnt][j - 1] * i;
        ++cnt;
    }
    go(0, 0, 100);
    cout << best << endl;
    return 0;
}