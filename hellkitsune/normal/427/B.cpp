#include <cstdio>
#include <cmath>
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

int n, t, c, cur = 0;
LL ans = 0;

int main() {
    scanf("%d%d%d", &n, &t, &c);
    REP(i, n) {
        int x;
        scanf("%d", &x);
        if (x <= t)
            ++cur;
        else {
            if (cur >= c)
                ans += cur - c + 1;
            cur = 0;
        }
    }
    if (cur >= c)
        ans += cur - c + 1;
    cout << ans << endl;
    return 0;
}