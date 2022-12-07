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
int mn = 0;
int a[1000], b[1000];

int main() {
    scanf("%d", &n);
    REP(i, n) {
        scanf("%d%d", a + i, b + i);
    }
    REP(i, n) mn = max(mn, min(a[i], b[i]));
    LL best = 1e18;
    for (int x = mn; x <= 1000; ++x) {
        int sum = 0;
        REP(i, n) if (a[i] > x)
            sum += a[i];
        else if (b[i] > x)
            sum += b[i];
        else
            sum += min(a[i], b[i]);
        best = min(best, (LL)sum * x);
    }
    cout << best << endl;
    return 0;
}