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

int n, t, q;
double c;
int a[200000];
double r[200000], appr[200000];

int main() {
    scanf("%d%d%lf", &n, &t, &c);
    REP(i, n) scanf("%d", a + i);
    double sum = 0;
    REP(i, t) sum += a[i];
    r[t - 1] = sum;
    for (int i = t; i < n; ++i) {
        sum += a[i] - a[i - t];
        r[i] = sum;
    }
    REP(i, n) r[i] /= t;
    double mean = 0;
    REP(i, n) {
        mean = (mean + (double)a[i] / t) / c;
        appr[i] = mean;
    }
    scanf("%d", &q);
    REP(query, q) {
        int p;
        scanf("%d", &p), --p;
        printf("%.9f %.9f %.9f\n", r[p], appr[p], abs(r[p] - appr[p]) / r[p]);
    }
    return 0;
}