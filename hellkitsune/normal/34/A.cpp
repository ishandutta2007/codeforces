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
int a[101];

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    a[n] = a[0];
    int best = 0;
    for (int i = 1; i < n; ++i) if (abs(a[i + 1] - a[i]) < abs(a[best + 1] - a[best])) {
        best = i;
    }
    if (best == n - 1) cout << n << ' ' << 1 << endl;
    else cout << best + 1 << ' ' << best + 2 << endl;
    return 0;
}