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
int a[51];
bool c[51][51] = {};
bool was[51][51] = {};
int p1, p2;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    int cnt = (n * (n - 1)) / 2 - 1;
    REP(i, cnt) {
        int x, y;
        cin >> x >> y;
        was[x][y] = was[y][x] = c[x][y] = true;
    }
    for (int i = 1; i <= n; ++i) for (int j = i + 1; j <= n; ++j) if (!was[i][j]) {
        p1 = i;
        p2 = j;
    }
    c[p1][p2] = true;
    for (int i = 1; i <= n; ++i) a[i] = i;
    for (int i = 1; i < n; ++i) for (int j = 1; j < n; ++j) if (!c[a[j]][a[j + 1]])
        swap(a[j], a[j + 1]);
    for (int i = 1; i < n; ++i) for (int j = i + 1; j <= n; ++j) if (!c[a[i]][a[j]]) {
        cout << p2 << ' ' << p1 << endl;
        return 0;
    }
    cout << p1 << ' ' << p2 << endl;
    return 0;
}