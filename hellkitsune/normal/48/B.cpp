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

int n, m, a, b;
int t[50][50] = {};
const int INF = 1e9;

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) REP(j, m) scanf("%d", t[i] + j);
    scanf("%d%d", &a, &b);
    int ans = INF;
    REP(zzz, 2) {
        REP(i, n - a + 1) REP(j, m - b + 1) {
            int cur = 0;
            for (int ii = i; ii < i + a; ++ii) for (int jj = j; jj < j + b; ++jj) {
                cur += t[ii][jj];
            }
            ans = min(ans, cur);
        }
        if (a == b) break;
        swap(a, b);
    }
    printf("%d\n", ans);
    return 0;
}