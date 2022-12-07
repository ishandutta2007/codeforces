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
int a[200000];
int sum[200001];

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    for (int i = 1; i < n; ++i) {
        for (int from = 1; from < n; ) {
            if (from > 1000) {
                int pos = i - 1;
                int lo = from + 1, hi = n, mid, cur = pos / from;
                while (lo < hi) {
                    mid = (lo + hi) >> 1;
                    if (pos / mid != cur)
                        hi = mid;
                    else
                        lo = mid + 1;
                }
                if (a[cur] > a[i]) {
                    ++sum[from];
                    --sum[lo];
                }
                from = lo;
            } else {
                int cur = (i - 1) / from;
                if (a[cur] > a[i]) {
                    ++sum[from];
                    --sum[from + 1];
                }
                ++from;
            }
        }
    }
    int cur = 0;
    for (int i = 1; i < n; ++i) {
        cur += sum[i];
        printf("%d ", cur);
    }
    printf("\n");
    return 0;
}