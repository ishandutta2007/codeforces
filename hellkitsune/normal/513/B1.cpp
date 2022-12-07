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
LL m;
bool used[15] = {};
int mx = 0, pos = 0;
int a[100];
int ans[100];

void go(int v) {
    if (v == n) {
        int cur = 0;
        REP(i, n) for (int j = i; j < n; ++j) {
            int mn = a[i];
            for (int k = i + 1; k <= j; ++k)
                mn = min(mn, a[k]);
            cur += mn;
        }
        if (cur > mx) {
            mx = cur;
            pos = 1;
            if (pos == m) {
                REP(i, n) ans[i] = a[i];
            }
        } else if (cur == mx) {
            ++pos;
            if (pos == m) {
                REP(i, n) ans[i] = a[i];
            }
        }
        return;
    }
    for (int i = 1; i <= n; ++i) if (!used[i]) {
        used[i] = true;
        a[v] = i;
        go(v + 1);
        used[i] = false;
    }
}

int main() {
    cin >> n >> m;
    go(0);
    REP(i, n) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}