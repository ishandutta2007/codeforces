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
int d[200000];
LL a, s;

int main() {
    scanf("%d%I64d", &n, &a);
    REP(i, n) scanf("%d", d + i);
    s = 0;
    REP(i, n) s += d[i];
    REP(i, n) {
        int ans = min((LL)d[i], a - n + 1);
        ans -= max(1ll, a - s + d[i]) - 1;
        printf("%d ", d[i] - ans);
    }
    printf("\n");
    return 0;
}