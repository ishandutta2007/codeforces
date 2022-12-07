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
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int a[5][5];
int ans = 0;
bool vis[5];
int ord[5];

void go(int v) {
    if (v == 5) {
        int cur = 0;
        for (int i = 0; i < 4; ++i)
            for (int j = i; j < 4; j += 2) {
                cur += a[ord[j]][ord[j + 1]];
                cur += a[ord[j + 1]][ord[j]];
            }
        ans = max(ans, cur);
        return;
    }
    REP(i, 5)
        if (!vis[i]) {
            vis[i] = true;
            ord[v] = i;
            go(v + 1);
            vis[i] = false;
        }
}

int main() {
    REP(i, 5) REP(j, 5)
        cin >> a[i][j];
    go(0);
    cout << ans << endl;
    return 0;
}