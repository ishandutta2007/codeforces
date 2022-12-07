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
int a[1000001], b[1000001], c[1000001], bs = 0;
bool d[1000001] = {};
int mx = 0;
LL ans = 0;

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", b + i);
    for (int i = 1; i < n; ++i)
        if (b[i] > b[mx])
            mx = i;
    for (int i = mx; i < n; ++i)
        a[i - mx] = b[i];
    for (int i = 0; i < mx; ++i)
        a[n - mx + i] = b[i];
    int cnt = 0;
    REP(i, n) if (a[i] == a[0]) ++cnt;
    REP(i, n) if (a[i] == a[0]) {
        for (int j = (i + 1) % n, mx = 0; a[j] != a[0];) {
            if (a[j] >= mx) {
                d[j] = true;
                ++ans;
                mx = a[j];
            }
            ++j; if (j == n) j = 0;
        }
        for (int j = (i - 1 + n) % n, mx = 0; a[j] != a[0];) {
            if (a[j] >= mx) {
                d[j] = true;
                ++ans;
                mx = a[j];
            }
            --j; if (j < 0) j = n - 1;
        }
    }
    if (cnt == 1) {
        ans = 0;
        REP(i, n) if (d[i]) ++ans;
    }
    ans += ((LL)cnt * (cnt - 1)) / 2;
    REP(i, n) {
        if (a[i] == a[0]) {
            bs = 0;
            continue;
        }
        while (bs && a[i] > b[bs - 1]) {
            ans += c[bs - 1];
            --bs;
        }
        if (bs && a[i] == b[bs - 1]) {
            ans += c[bs - 1];
            if (bs > 1) ++ans;
            ++c[bs - 1];
        }
        if (bs && a[i] < b[bs - 1]) {
            ++ans;
            b[bs] = a[i];
            c[bs++] = 1;
        }
        if (bs == 0) {
            b[0] = a[i];
            c[0] = 1;
            bs = 1;
        }
    }
    cout << ans << endl;
    return 0;
}