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

int n, m;
int a[100], b[100];

void solve(int n, int *a) {
    REP(i, n) a[i] = 1;
    if (n == 1) return;
    if (n == 2) {
        a[0] = 3;
        a[1] = 4;
    } else if (n % 2 == 0) {
        a[n - 1] = (n - 1) / 2;
    } else {
        a[0] = 2;
        a[n - 1] = (n + 2) / 2;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    solve(n, a);
    solve(m, b);
    REP(i, n) {
        REP(j, m) printf("%d ", a[i] * b[j]);
        printf("\n");
    }
    return 0;
}