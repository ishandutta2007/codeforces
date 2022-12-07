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

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;

double dist(double x, double y, double xx, double yy) {
    return sqrt((x - xx)*(x - xx) + (y - yy)*(y - yy));
}

int main() {
    cin >> n >> m;
    if (n == 0) {
        printf("%d %d\n%d %d\n%d %d\n%d %d\n", 0, 1, 0, m, 0, 0, 0, m - 1);
        return 0;
    }
    if (m == 0) {
        printf("%d %d\n%d %d\n%d %d\n%d %d\n", 1, 0, n, 0, 0, 0, n - 1, 0);
        return 0;
    }
    if (n < m) {
        if (dist(0, 0, n, m) + dist(n, m, n, 0) + dist(n, 0, 0, m) >
            dist(1, 0, n, m) + dist(n, m, 0, 0) + dist(0, 0, n - 1, m))
            printf("%d %d\n%d %d\n%d %d\n%d %d\n", 0, 0, n, m, n, 0, 0, m);
        else
            printf("%d %d\n%d %d\n%d %d\n%d %d\n", 1, 0, n, m, 0, 0, n - 1, m);
        return 0;
    }
    if (dist(0, 0, n, m) + dist(n, m, 0, m) + dist(0, m, n, 0) >
        dist(0, 1, n, m) + dist(n, m, 0, 0) + dist(0, 0, n, m - 1))
        printf("%d %d\n%d %d\n%d %d\n%d %d\n", 0, 0, n, m, 0, m, n, 0);
    else
        printf("%d %d\n%d %d\n%d %d\n%d %d\n", 0, 1, n, m, 0, 0, n, m - 1);
    return 0;
}