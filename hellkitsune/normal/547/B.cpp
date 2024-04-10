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
int a[200001];
int l[200001], r[200001];
int d[200001];

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    for (int i = 0; i < n; ++i) {
        l[i] = i;
        while (l[i] > 0 && a[l[i] - 1] >= a[i]) {
            l[i] = l[l[i] - 1];
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        r[i] = i;
        while (r[i] < n - 1 && a[r[i] + 1] >= a[i]) {
            r[i] = r[r[i] + 1];
        }
    }
    for (int i = 1; i <= n; ++i) d[i] = -1;
    REP(i, n) {
        d[r[i] - l[i] + 1] = max(d[r[i] - l[i] + 1], a[i]);
    }
    for (int i = n - 1; i >= 1; --i) {
        d[i] = max(d[i], d[i + 1]);
    }
    for (int i = 1; i <= n; ++i) printf("%d ", d[i]);
    printf("\n");
    return 0;
}