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
int x[100000], h[100000];

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d%d", x + i, h + i);
    int xx = -2e9, ans = 0;
    REP(i, n) {
        if (x[i] - h[i] > xx) {
            ++ans;
            xx = x[i];
        } else if (i == n - 1 || x[i] + h[i] < x[i + 1]) {
            ++ans;
            xx = x[i] + h[i];
        } else {
            xx = x[i];
        }
    }
    printf("%d\n", ans);
    return 0;
}