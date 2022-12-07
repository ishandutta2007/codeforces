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

int n, w;
int a[200000];

int main() {
    scanf("%d%d", &n, &w);
    REP(i, 2 * n) scanf("%d", a + i);
    sort(a, a + (2 * n));
    double mx = min((double)a[0], 0.5 * a[n]);
    mx *= 3 * n;
    mx = min(mx, (double)w);
    cout << setprecision(12) << fixed << mx << endl;
    return 0;
}