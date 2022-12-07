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

bool h[100][100] = {};
int n, k, m, c;

const int INF = 1e9;

int main() {
    cin >> n >> k;
    c = k / 2 + 1;
    REP(i, n) {
        cin >> m;
        int best = INF, bestx, besty;
        for (int x = 1; x <= k; ++x) {
            int sum = 0, cnt = 0;
            for (int y = 1; y <= m; ++y) {
                sum += abs(x - c) + abs(y - c);
                if (h[x][y]) ++cnt;
            }
            int yl = 1;
            while (true) {
                if (!cnt && sum < best) {
                    best = sum;
                    bestx = x;
                    besty = yl;
                }
                if (yl + m > k) break;
                if (h[x][yl]) --cnt;
                if (h[x][yl + m]) ++cnt;
                sum -= abs(yl - c);
                sum += abs(yl + m - c);
                ++yl;
            }
        }
        if (best == INF) printf("-1\n");
        else {
            printf("%d %d %d\n", bestx, besty, besty + m - 1);
            for (int y = besty; y < besty + m; ++y)
                h[bestx][y] = true;
        }
    }
    return 0;
}