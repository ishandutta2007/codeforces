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

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int x[10000], y[10000];
vector<PII> ans;
vector<PII> revAns;
int xcnt, ycnt;

inline void xo(int a, int b) {
    x[a] ^= x[b];
    ans.pb(mp(a + 1, b + 1));
}

inline void yo(int a, int b) {
    y[a] ^= y[b];
    revAns.pb(mp(a + 1, b + 1));
}

bool setBits[32] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> x[i];
    REP(i, n) cin >> y[i];
    int cnt = 0;
    for (int i = 30; i >= 0; --i) {
        int pos = -1;
        for (int j = cnt; j < n; ++j) if (y[j] & (1 << i)) {
            pos = j;
            if (j != cnt) {
                yo(j, cnt);
                yo(cnt, j);
                yo(j, cnt);
            }
            break;
        }
        if (pos != -1) {
            setBits[i] = true;
            ++cnt;
            REP(j, n) if (j != cnt - 1) if (y[j] & (1 << i))
                yo(j, cnt - 1);
        }
    }
    ycnt = cnt;
    cnt = 0;
    for (int i = 30; i >= 0; --i) {
        int pos = -1;
        for (int j = cnt; j < n; ++j) if (x[j] & (1 << i)) {
            pos = j;
            if (j != cnt) {
                xo(j, cnt);
                xo(cnt, j);
                xo(j, cnt);
            }
            break;
        }
        if (pos != -1) {
            ++cnt;
            for (int j = 0; j < cnt - 1; ++j) if ((y[j] ^ x[j]) & (1 << i))
                xo(j, cnt - 1);
            for (int j = cnt; j < n; ++j) if (x[j] & (1 << i))
                xo(j, cnt - 1);
            if (!setBits[i]) {
                --cnt;
                xo(cnt, cnt);
            }
        }
    }
    xcnt = cnt;
    REP(i, n) if (x[i] != y[i]) {
        printf("-1\n");
        return 0;
    }
    int tot = (int)ans.size() + (int)revAns.size();
    printf("%d\n", tot);
    REP(i, ans.size())
        printf("%d %d\n", ans[i].first, ans[i].second);
    for (int i = (int)revAns.size() - 1; i >= 0; --i)
        printf("%d %d\n", revAns[i].first, revAns[i].second);
    return 0;
}