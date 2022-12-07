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

int n;
LL x, y;
LL s = 0;

inline LL cnt(LL r) {
    LL ret = ((r & 3) >> 1) ^ (r & 1);
    if (!(r & 1)) ret |= r;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) {
        cin >> x >> y;
        y = x + y - 1;
        s ^= cnt(y) ^ cnt(x - 1);
    }
    if (s == 0) cout << "bolik\n";
    else cout << "tolik\n";
    return 0;
}