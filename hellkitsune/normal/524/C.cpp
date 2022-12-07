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

int n, k;
bool se[10000001] = {};
int a[5000];

int main() {
    scanf("%d%d", &n, &k);
    REP(i, n) {
        scanf("%d", a + i);
        se[a[i]] = true;
    }
    int q;
    scanf("%d", &q);
    REP(query, q) {
        int x;
        scanf("%d", &x);
        int best = k + 1;
        REP(i, n) {
            for (int p = 1; p < best; ++p) {
                int val = p * a[i];
                if (val > x) break;
                if (val == x) {
                    best = p;
                    break;
                }
                val = x - val;
                for (int q = 1; p + q < best; ++q) {
                    if (val % q != 0) continue;
                    int nval = val / q;
                    if (nval <= 10000000 && se[nval]) {
                        best = p + q;
                        break;
                    }
                }
            }
        }
        if (best == k + 1) best = -1;
        printf("%d\n", best);
    }
    return 0;
}