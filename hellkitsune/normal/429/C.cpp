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
int c[24], a[24] = {};

void go(int pos) {
    if (pos == n) {
        bool ok = true;
        REP(i, n) if (a[i] != c[i] - 1) {
            ok = false;
            break;
        }
        if (ok) {
            printf("YES\n");
            exit(0);
        }
        return;
    }
    REP(i, pos) if (c[pos] < c[i] - 1 && a[i] + c[pos] < c[i]) {
        a[i] += c[pos];
        go(pos + 1);
        a[i] -= c[pos];
        if (c[pos] == 1) break;
    }
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", c + i);
    sort(c, c + n, greater<int>());
    REP(i, n) if (c[i] == 2) {
        printf("NO\n");
        return 0;
    }
    int o = 0;
    REP(i, n) if (c[i] == 1) ++o;
    if (o < n / 2 + 1) {
        printf("NO\n");
        return 0;
    }
    go(1);
    printf("NO\n");
    return 0;
}