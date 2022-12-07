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

int n;
LL a[500000];
LL sum = 0;
int _d[500001] = {}, *d;

int main() {
    d = _d + 1;
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> a[i];
    REP(i, n) sum += a[i];
    if (sum % 3 != 0 || n < 3) {
        cout << 0 << endl;
        return 0;
    }
    sum /= 3;
    int cnt = 0;
    LL cur = 0;
    REP(i, n) {
        cur += a[i];
        if (cur == sum) ++cnt;
        d[i] = cnt;
    }
    sum *= 2;
    LL ans = 0;
    cur = 0;
    REP(i, n - 1) {
        cur += a[i];
        if (cur == sum) ans += d[i - 1];
    }
    cout << ans << endl;
    return 0;
}