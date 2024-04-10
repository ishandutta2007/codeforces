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

int n, j;
LL ind;
int x[100000], y[100000], xx, yy;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> ind;
    j = ind % (2 * n);
    cin >> xx >> yy;
    REP(i, n) cin >> x[i] >> y[i];
    REP(i, j) {
        int p = i % n;
        xx = 2 * x[p] - xx;
        yy = 2 * y[p] - yy;
    }
    cout << xx << ' ' << yy;
    return 0;
}