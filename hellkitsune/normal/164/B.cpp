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

int n, m;
int a[2000000], b[1000000], rev[1000001];
LL pos[2000000];

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) scanf("%d", a + i);
    REP(i, n) a[i + n] = a[i];
    if (n > 1) n *= 2;
    REP(i, m) scanf("%d", b + i);
    REP(i, 1000001) rev[i] = -1;
    REP(i, m) rev[b[i]] = i;
    int cur = -1, ans = 0;
    REP(i, n) {
        if (rev[a[i]] == -1) {
            cur = -1;
            continue;
        }
        pos[i] = rev[a[i]];
        if (cur != -1) {
            pos[i] += pos[i - 1] - pos[i - 1] % m;
            if (pos[i] < pos[i - 1]) pos[i] += m;
            if (pos[i] - m >= pos[i - 1]) pos[i] -= m;
        }
        if (cur == -1) cur = i;
        while (pos[i] - pos[cur] >= m)
            ++cur;
        ans = max(ans, i - cur + 1);
    }
    printf("%d\n", ans);
    return 0;
}