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
int a[1000];
const double EPS = 1e-9;

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    double lo = -1, hi = 1e9;
    REP(i, n) {
        //(i + 1) * alp >= a[i]
        //(i + 1) * alp < a[i] + 1
        lo = max(lo, a[i] / double(i + 1));
        hi = min(hi, (a[i] + 1) / double(i + 1));
    }
    lo *= n + 1;
    hi *= n + 1;
    int llo = (int)(lo + EPS);
    int hhi = (int)(hi - EPS);
    if (llo < hhi) {
        printf("not unique\n");
    } else {
        printf("unique\n");
        printf("%d\n", llo);
    }
    return 0;
}