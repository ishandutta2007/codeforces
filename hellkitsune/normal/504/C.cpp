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
int a[100000];
int deg[100000] = {}, cur[100000];

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i), --a[i];
    bool ok = true;
    REP(i, n) if (a[i] != a[n - 1 - i]) {
        ok = false;
        break;
    }
    if (ok) {
        cout << (LL)n * (n + 1) / 2 << endl;
        return 0;
    }
    REP(i, n) ++deg[a[i]];
    LL ans = 0;
    if (n & 1) {
        int o = -1;
        REP(i, n) if (deg[i] & 1) {
            if (o != -1) {
                printf("0\n");
                return 0;
            }
            o = i;
        }
        if (o == -1) {
            printf("0\n");
            return 0;
        }
        int lo = 0;
        while (lo < n / 2 && a[lo] == a[n - 1 - lo]) ++lo;
        ans = (LL)(lo + 1) * (lo + 1);
        REP(i, n) deg[i] = (deg[i] + 1) / 2;
        int bad = 0;
        REP(i, n) {
            cur[i] = 0;
            if (deg[i]) ++bad;
        }
        int i = 0;
        while (bad) {
            if (++cur[a[i]] == deg[a[i]]) {
                --bad;
            }
            ++i;
        }
        if (i == (n + 1) / 2 && a[i - 1] == o) {
            while (a[i - 1] == a[n - i]) --i;
        }
        ans += (LL)(lo + 1) * (n - lo - i);
        bad = 0;
        REP(i, n) {
            cur[i] = 0;
            if (deg[i]) ++bad;
        }
        i = n - 1;
        while (bad) {
            if (++cur[a[i]] == deg[a[i]]) {
                --bad;
            }
            --i;
        }
        if (i == n / 2 - 1 && a[i + 1] == o) {
            while (a[i + 1] == a[n - i - 2]) ++i;
        }
        ans += (LL)(lo + 1) * (i - lo + 1);
    } else {
        REP(i, n) if (deg[i] & 1) {
            printf("0\n");
            return 0;
        }
        int lo = 0;
        while (lo < n / 2 && a[lo] == a[n - 1 - lo]) ++lo;
        ans = (LL)(lo + 1) * (lo + 1);
        REP(i, n) deg[i] /= 2;
        int bad = 0;
        REP(i, n) {
            cur[i] = 0;
            if (deg[i]) ++bad;
        }
        int i = 0;
        while (bad) {
            if (++cur[a[i]] == deg[a[i]]) {
                --bad;
            }
            ++i;
        }
        if (i == n / 2) {
            while (a[i - 1] == a[n - i]) --i;
        }
        ans += (LL)(lo + 1) * (n - lo - i);
        bad = 0;
        REP(i, n) {
            cur[i] = 0;
            if (deg[i]) ++bad;
        }
        i = n - 1;
        while (bad) {
            if (++cur[a[i]] == deg[a[i]]) {
                --bad;
            }
            --i;
        }
        if (i == n / 2 - 1) {
            while (a[i + 1] == a[n - i - 2]) ++i;
        }
        ans += (LL)(lo + 1) * (i - lo + 1);
    }
    cout << ans << endl;
    return 0;
}