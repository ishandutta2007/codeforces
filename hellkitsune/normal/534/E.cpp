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
int cnt[200000] = {};
int a[200000];
LL ans = -1, dist = 0;
int off = 0, cur = 0;
bool forw = true;
queue<int> q, dq;

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    scanf("%d", &m);
    REP(i, m) {
        int x;
        scanf("%d", &x), --x;
        if (++cnt[x] == 1)
            ++off;
    }
    int tot = 2 * n + m + 5;
    REP(i, tot) {
        q.push(cur);
        --cnt[cur];
        if (cnt[cur] == 0) --off;
        int curDist = 0;
        if (forw && cur != 0) curDist = a[cur] - a[cur - 1];
        else if (!forw) curDist = a[cur + 1] - a[cur];
        dq.push(curDist);
        dist += curDist;
        if (cnt[cur] < 0) {
            while (q.front() != cur) {
                ++cnt[q.front()];
                if (cnt[q.front()] == 1) ++off;
                q.pop();
                dist -= dq.front();
                dq.pop();
            }
            cnt[cur] = 0;
            q.pop();
            dist -= dq.front();
            dq.pop();
        }
        if (off == 0) {
            LL actualDist = dist;
            if (!dq.empty()) actualDist -= dq.front();
            if (ans != -1 && ans != actualDist) {
                printf("-1\n");
                return 0;
            }
            ans = actualDist;
        }
        if (forw && cur == n - 1) {
            forw = false;
        } else if (!forw && cur == 0) {
            forw = true;
        }
        if (forw) ++cur;
        else --cur;
    }
    printf("%I64d\n", ans);
    return 0;
}