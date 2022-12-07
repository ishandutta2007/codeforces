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

int x, y, xx, yy;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> x >> y >> xx >> yy;
    if (x == xx) {
        cout << x + yy - y << ' ' << y << ' ' << x + yy - y << ' ' << yy << '\n';
    } else if (y == yy) {
        cout << x << ' ' << y + xx - x << ' ' << xx << ' ' << y + xx - x << '\n';
    } else if (abs(x - xx) != abs(y - yy)) {
        cout << "-1\n";
    } else {
        cout << x << ' ' << yy << ' ' << xx << ' ' << y << '\n';
    }
    return 0;
}