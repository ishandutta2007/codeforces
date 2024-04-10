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

string s;
int a[50];
LL d[50][10] = {};
int n;

int main() {
    cin >> s;
    n = (int)s.length();
    REP(i, n) a[i] = s[i] - '0';
    REP(i, 10) d[0][i] = 1;
    REP(i, n - 1) REP(j, 10) if (d[i][j]) {
        int dig = (j + a[i + 1]) / 2;
        int mo = (j + a[i + 1]) % 2;
        d[i + 1][dig] += d[i][j];
        if (mo == 1) {
            d[i + 1][dig + 1] += d[i][j];
        }
    }
    LL ans = 0;
    REP(i, 10) ans += d[n - 1][i];
    bool ok = true;
    for (int i = 1; i < n; ++i) {
        int dig = (a[i - 1] + a[i]) / 2;
        int mo = (a[i - 1] + a[i]) % 2;
        if (dig != a[i] && (mo == 0 || dig + 1 != a[i])) {
            ok = false;
            break;
        }
    }
    if (ok) --ans;
    cout << ans << endl;
    return 0;
}