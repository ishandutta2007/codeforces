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

double off[5000];
int x[5000], y[5000], z[5000], n;

inline int dist(int x, int y, int z) {
    return x * x + y * y + z * z;
}

inline double distD(double x, double y, double z) {
    return sqrt(x * x + y * y + z * z);
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d%d%d", x + i, y + i, z + i);
    for (int i = 1; i < n; ++i) {
        off[i] = sqrt(dist(x[i] - x[0], y[i] - y[0], z[i] - z[0]));
    }
    double ans = 1e30;
    for (int i = 1; i < n; ++i) for (int j = i + 1; j < n; ++j) {
        double dist = distD(x[i] - x[j], y[i] - y[j], z[i] - z[j]);
        dist -= abs(off[i] - off[j]);
        ans = min(ans, max(off[i], off[j]) + 0.5 * dist);
    }
    printf("%.12f\n", ans);
    return 0;
}