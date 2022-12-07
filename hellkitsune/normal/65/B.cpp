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
int a[1001];
int d[4];

int main() {
    scanf("%d", &n);
    a[0] = 0;
    REP(i, n) scanf("%d", a + i + 1);
    for (int i = 1; i <= n; ++i) {
        int pre = a[i - 1];
        int x = a[i];
        REP(i, 4) {
            d[i] = x % 10;
            x /= 10;
        }
        int best = 9999;
        REP(i, 4) {
            int rem = d[i];
            REP(j, 10) {
                d[i] = j;
                int num = 0;
                for (int k = 3; k >= 0; --k) {
                    num = 10 * num + d[k];
                }
                if (num >= pre && num >= 1000 && num <= 2011) {
                    best = min(best, num);
                }
            }
            d[i] = rem;
        }
        if (best == 9999) {
            printf("No solution\n");
            return 0;
        }
        a[i] = best;
    }
    REP(i, n) printf("%d\n", a[i + 1]);
    return 0;
}