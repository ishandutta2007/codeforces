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

int a[6];

int main() {
    REP(i, 6) cin >> a[i];
    LL ans = 0;
    int h = a[0] + a[1];
    int cur = 2 * a[2] - 1;
    for (int i = 0; i < h; ++i) {
        if (i < a[1]) ++cur;
        else if (i > a[1]) --cur;
        if (i < a[3]) ++cur;
        else if (i > a[3]) --cur;
        ans += cur;
    }
    //assert(cur == a[5] * 2 + 1);
    cout << ans << endl;
    return 0;
}