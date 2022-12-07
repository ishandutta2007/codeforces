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

int n, x, xx, xxx, y, yy, yyy;

int main() {
    cin >> n >> x >> y >> xx >> yy >> xxx >> yyy;
    int cnt = min(y, n - xx - xxx);
    cout << cnt << ' ';
    n -= cnt;
    cnt = min(yy, n - xxx);
    cout << cnt << ' ';
    n -= cnt;
    cout << n << endl;
    return 0;
}