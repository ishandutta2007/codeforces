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

LL k;
int n;
int dist[500][500];
int cnt[1000] = {};
queue<PII> q;
int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
const int MOD = 1e9 + 7;

int binPow(LL x, int p) {
    LL ret = 1;
    while (p) {
        if (p & 1) ret = ret * x % MOD;
        p >>= 1;
        x = x * x % MOD;
    }
    return (int)ret;
}

int main() {
    scanf("%I64d%d", &k, &n);
    REP(i, 500) REP(j, 500) dist[i][j] = -1;
    REP(i, n) {
        int y, x;
        scanf("%d%d", &y, &x), y += 250, x += 250;
        dist[y][x] = -2;
    }
    dist[250][250] = 0;
    ++cnt[0];
    q.push(mp(250, 250));
    int rem = 0;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        rem = dist[y][x];
        if (y > 490 || x > 490 || y < 10 || x < 10) {
            break;
        }
        q.pop();
        int curD = dist[y][x] + 1;
        REP(i, 8) {
            int yy = y + dy[i];
            int xx = x + dx[i];
            if (dist[yy][xx] == -1) {
                ++cnt[dist[yy][xx] = curD];
                q.push(mp(yy, xx));
            }
        }
    }
    int tot = 0;
    if (q.empty() || k <= rem) {
        rem = min((LL)rem + 1, k);
        REP(i, rem + 1) tot += cnt[i];
        printf("%d\n", tot);
        return 0;
    }
    REP(i, rem + 1) tot += cnt[i];
    LL from = cnt[rem] + 28;
    LL to = cnt[rem] + (k - rem) % MOD * 28 % MOD;
    LL ccnt = (k - rem) % MOD;
    int res = (tot + (from + to) * ccnt % MOD * binPow(2, MOD - 2)) % MOD;
    printf("%d\n", res);
    return 0;
}