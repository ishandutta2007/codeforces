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

LL a[100], w;
LL m;

int main() {
    cin >> w >> m;
    if (w == 2) {
        cout << "YES" << endl;
        return 0;
    }
    a[0] = 1;
    int n = 1;
    while (a[n - 1] < 2 * m + 11) {
        a[n] = a[n - 1] * w;
        ++n;
    }
    REP(i, n) m += a[i];
    for (int i = n - 1; i >= 0; --i) {
        if (m >= a[i]) m -= a[i];
        if (m >= a[i]) m -= a[i];
    }
    if (m == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}