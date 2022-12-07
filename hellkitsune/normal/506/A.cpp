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

int d[30001][1000];
int n, st;
int cnt[30001] = {};
int off;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> st;
    REP(i, n) {
        int x;
        cin >> x;
        ++cnt[x];
    }
    memset(d, -1, sizeof d);
    int ans = cnt[st];
    d[st][500] = cnt[st];
    st -= 500;
    for (int i = st + 500; i < 30000; ++i) REP(j, 1000) if (d[i][j] != -1) {
        int fi = j + st;
        int from = (fi == 1) ? 0 : -1;
        for (int len = from; len <= 1; ++len) {
            int pos = i + fi + len;
            if (pos > 30000) break;
            ans = max(ans, d[i][j] + cnt[pos]);
            d[pos][j + len] = max(d[pos][j + len], d[i][j] + cnt[pos]);
        }
    }
    cout << ans << '\n';
    return 0;
}