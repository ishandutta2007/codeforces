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

int n, x, m, y;
LL ans;

int main() {
    scanf("%d%d%d%d", &n, &x, &m, &y);
    int dist = abs(y - x);
    LL v = n + m, e = n + m, cc = dist <= n + m;
    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        if (i <= dist) {
            int lo = max(1, dist - i + 1);
            int hi = min(m, dist + i - 1);
            cnt += max(0, hi - lo + 1) * 2;
            int tlo = dist - i;
            int thi = dist + i;
            if (tlo >= 1 && tlo <= m) ++cnt;
            if (thi >= 1 && thi <= m) ++cnt;
        } else {
            int lo = max(1, i - dist + 1);
            int hi = min(dist + i - 1, m);
            cnt += max(0, hi - lo + 1) * 2;
            int tlo = i - dist;
            int thi = i + dist;
            if (tlo >= 1 && tlo <= m) ++cnt;
            if (thi >= 1 && thi <= m) ++cnt;
        }
        v += max(0, cnt - 1);
        e += max(0, cnt - 1);
        if (cnt == 0) ++cc;
    }
    for (int i = 1; i <= m; ++i) {
        int cnt = 0;
        if (i <= dist) {
            int lo = max(1, dist - i + 1);
            int hi = min(n, dist + i - 1);
            cnt += max(0, hi - lo + 1) * 2;
            int tlo = dist - i;
            int thi = dist + i;
            if (tlo >= 1 && tlo <= n) ++cnt;
            if (thi >= 1 && thi <= n) ++cnt;
        } else {
            int lo = max(1, i - dist + 1);
            int hi = min(dist + i - 1, n);
            cnt += max(0, hi - lo + 1) * 2;
            int tlo = i - dist;
            int thi = i + dist;
            if (tlo >= 1 && tlo <= n) ++cnt;
            if (thi >= 1 && thi <= n) ++cnt;
        }
        if (cnt > 0) --v;
        e += max(0, cnt - 1);
        if (cnt == 0) ++cc;
    }
    ans += 1 + cc + e - v;
    cout << ans << endl;
    return 0;
}