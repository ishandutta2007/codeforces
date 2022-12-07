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
typedef long long LL;
typedef pair<int, int> PII;

int f[12][12] = {};
string s;

int main() {
    cin >> s;
    int y = s[0] - 'a' + 2, x = s[1] - '1' + 2;
    for (int i = 2; i < 10; ++i) f[i][x] = f[y][i] = 1;
    cin >> s;
    int yy = s[0] - 'a' + 2, xx = s[1] - '1' + 2;
    f[yy - 2][xx + 1] = 1;
    f[yy - 2][xx - 1] = 1;
    f[yy + 2][xx + 1] = 1;
    f[yy + 2][xx - 1] = 1;
    f[yy - 1][xx + 2] = 1;
    f[yy - 1][xx - 2] = 1;
    f[yy + 1][xx + 2] = 1;
    f[yy + 1][xx - 2] = 1;
    f[yy][xx] = 1;
    int ans = 0;
    for (int i = 2; i < 10; ++i) for (int j = 2; j < 10; ++j) if (f[i][j] != 1) {
        int d1 = abs(y - i);
        int d2 = abs(x - j);
        if (d1 > d2) swap(d1, d2);
        if (d1 == 1 && d2 == 2) continue;
        d1 = abs(yy - i);
        d2 = abs(xx - j);
        if (d1 > d2) swap(d1, d2);
        if (d1 == 1 && d2 == 2) continue;
        ++ans;
    }
    cout << ans << endl;
    return 0;
}