#include <cstdio>
#include <cmath>
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

int n, m, sz;
int fen[2000000] = {}, ans[1000000];
PII val[2000000] = {};
bool used[1000001] = {};

void fenAdd(int pos, int d) {
    for (; pos < sz; pos = pos | (pos + 1))
        fen[pos] += d;
}

int fenGet(int pos) {
    int res = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
        res += fen[pos];
    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    sz = n + m;
    REP(i, n) {
        fenAdd(m + i, 1);
        val[m + i].second = i;
    }
    REP(i, m) {
        int x, y;
        scanf("%d%d", &x, &y);
        int l = 0, r = sz - 1, mid;
        while (l < r) {
            mid = (l + r) >> 1;
            if (fenGet(mid) < y)
                l = mid + 1;
            else
                r = mid;
        }
        if ((val[l].first && val[l].first != x) || (!val[l].first && used[x])) {
            printf("-1\n");
            return 0;
        }
        used[x] = true;
        fenAdd(l, -1);
        fenAdd(m - 1 - i, 1);
        val[m - 1 - i].first = x;
        val[m - 1 - i].second = val[l].second;
        val[l].second = -1;
    }
    REP(i, sz)
        if (val[i].second != -1)
            ans[val[i].second] = val[i].first;
    int next = 0;
    REP(i, n)
        if (ans[i] == 0) {
            while (used[++next]);
            printf("%d ", next);
        } else if (ans[i] != -1)
            printf("%d ", ans[i]);
    return 0;
}