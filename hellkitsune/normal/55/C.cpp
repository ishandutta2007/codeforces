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

int n, m, k;

int main() {
    scanf("%d%d%d", &n, &m, &k);
    bool win = false;
    REP(i, k) {
        int x, y;
        scanf("%d%d", &x, &y);
        int dx = min(x - 1, n - x);
        int dy = min(y - 1, m - y);
        if (dx < 5 || dy < 5) {
            win = true;
        }
    }
    if (win) printf("YES\n");
    else printf("NO\n");
    return 0;
}