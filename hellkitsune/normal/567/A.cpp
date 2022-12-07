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

int n, a[100000];
const int INF = 2e9 + 10;

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    REP(i, n) {
        int mn = INF;
        if (i != 0) mn = abs(a[i - 1] - a[i]);
        if (i != n - 1) mn = min(mn, abs(a[i + 1] - a[i]));
        int mx = 0;
        if (i != 0) mx = abs(a[0] - a[i]);
        if (i != n - 1) mx = max(mx, abs(a[n - 1] - a[i]));
        printf("%d %d\n", mn, mx);
    }
    return 0;
}