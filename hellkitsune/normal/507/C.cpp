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

LL h, n;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> h >> n;
    bool rev = false;
    LL ans = 0;
    --n;
    for (LL cur = h - 1; cur >= 0; --cur) {
        if (n & (1ll << cur)) {
            if (rev) {
                ++ans;
                rev = false;
            } else {
                ans += 2ll << cur;
            }
        } else {
            if (rev) {
                ans += 2ll << cur;
            } else {
                ++ans;
                rev = true;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}