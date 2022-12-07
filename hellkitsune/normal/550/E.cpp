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
int a[100000];
ostringstream oss;

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    if (a[n - 1] == 1) {
        printf("NO\n");
        return 0;
    }
    if (n == 1) {
        printf("YES\n0\n");
        return 0;
    }
    if (a[n - 2] == 1) {
        printf("YES\n");
        REP(i, n - 1) printf("%d->", a[i]);
        printf("%d\n", a[n - 1]);
        return 0;
    }
    if (n == 2) {
        printf("NO\n");
        return 0;
    }
    int z = n - 3;
    while (z >= 0 && a[z] == 1) --z;
    if (z == -1) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    REP(i, z) printf("%d->", a[i]);
    for (int i = z; i < n - 2; ++i)
        printf("(%d->", a[i]);
    printf("0");
    REP(i, n - 2 - z) printf(")");
    printf("->0\n");
    return 0;
}