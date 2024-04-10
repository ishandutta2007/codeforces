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

bool f[1005][1005] = {};
int n, m, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int q = 1; q <= k; ++q) {
        int y, x;
        cin >> y >> x;
        f[y][x] = true;
        for (int yy = y-1; yy <= y; ++yy) for (int xx = x-1; xx <= x; ++xx) {
            if (f[yy][xx] && f[yy + 1][xx] && f[yy][xx + 1] && f[yy + 1][xx + 1]) {
                cout << q << endl;
                return 0;
            }
        }
    }
    cout << 0 << endl;
    return 0;
}