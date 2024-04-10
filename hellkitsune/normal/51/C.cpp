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
int x[200000];
double cur[3], ans[3];

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", x + i);
    sort(x, x + n);
    double lo = 0, hi = 1e9 + 2, mid;
    REP(times, 200) {
        mid = (lo + hi) / 2;
        int pos = 0;
        REP(i, 3) {
            if (pos == n) {
                cur[i] = 1234;
                continue;
            }
            int plo = pos, phi = n - 1, pmid;
            while (plo < phi) {
                pmid = (plo + phi + 1) >> 1;
                if (x[pmid] - x[pos] > 2 * mid)
                    phi = pmid - 1;
                else
                    plo = pmid;
            }
            cur[i] = x[pos] + 0.5 * (x[plo] - x[pos]);
            pos = plo + 1;
        }
        if (pos < n) {
            lo = mid;
        } else {
            hi = mid;
            REP(i, 3) ans[i] = cur[i];
        }
    }
    printf("%.12f\n", lo);
    REP(i, 3) printf("%.12f ", ans[i]);
    printf("\n");
    return 0;
}