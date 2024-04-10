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

LL a[10][10];

int main() {
    int n;
    cin >> n;
    REP(i, n) a[0][i] = 1;
    REP(i, n) a[i][0] = 1;
    for (int i = 1; i < n; ++i) for (int j = 1; j < n; ++j)
        a[i][j] = a[i - 1][j] + a[i][j - 1];
    LL mx = a[0][0];
    REP(i, n) REP(j, n) mx = max(mx, a[i][j]);
    cout << mx << endl;
    return 0;
}