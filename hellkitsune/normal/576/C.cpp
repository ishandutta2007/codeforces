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

int n;
vector<int> v[1000][1000];

void out(vector<int> &v) {
    for (int x : v) printf("%d ", x);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        x = min(999, x / 1000);
        y = min(999, y / 1000);
        v[x][y].pb(i);
    }
    REP(i, 1000) {
        if (i & 1) {
            REP(j, 1000) out(v[i][j]);
        } else {
            for (int j = 999; j >= 0; --j) out(v[i][j]);
        }
    }
    printf("\n");
    return 0;
}