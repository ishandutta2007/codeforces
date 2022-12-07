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
int w[200000], h[200000];
int W, mx, mx2;

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d%d", w + i, h + i);
    W = 0;
    REP(i, n) W += w[i];
    mx = max(h[0], h[1]);
    mx2 = min(h[0], h[1]);
    for (int i = 2; i < n; ++i) {
        if (h[i] >= mx) {
            mx2 = mx;
            mx = h[i];
        } else if (h[i] > mx2) {
            mx2 = h[i];
        }
    }
    REP(i, n) {
        int curW = W - w[i];
        int curH = mx;
        if (h[i] == mx) curH = mx2;
        printf("%d ", curW * curH);
    }
    printf("\n");
    return 0;
}