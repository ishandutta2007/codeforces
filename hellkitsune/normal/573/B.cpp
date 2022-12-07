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

int n, a[100000], ans = 0;

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    a[0] = 1;
    REP(i, n - 1) a[i + 1] = min(a[i + 1], a[i] + 1);
    a[n - 1] = 1;
    for (int i = n - 1; i > 0; --i) a[i - 1] = min(a[i - 1], a[i] + 1);
    REP(i, n) {
        int cur = min(min(i + 1, n - i), a[i]);
        ans = max(ans, cur);
    }
    printf("%d\n", ans);
    return 0;
}