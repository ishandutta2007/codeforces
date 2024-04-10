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
int a[200000], p[200000], ord[200000];

bool cmp(const int &lhs, const int &rhs) {
    return p[lhs] < p[rhs];
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i), p[i] = a[i] + i;
    REP(i, n) ord[i] = i;
    sort(ord, ord + n, cmp);
    REP(i, n - 1) if (p[ord[i]] == p[ord[i + 1]]) {
        printf(":(\n");
        return 0;
    }
    REP(i, n) printf("%d ", p[ord[i]] - i);
    printf("\n");
    return 0;
}