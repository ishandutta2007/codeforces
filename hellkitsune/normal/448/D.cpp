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

LL n, m, k;

int main() {
    cin >> n >> m >> k;
    LL l = 1, r = n * m, mid;
    while (l < r) {
        mid = (l + r + 1) >> 1;
        LL cnt = 0;
        for (int i = 1; i <= n; ++i) {
            LL tmp = mid / i;
            if (mid % i == 0) --tmp;
            cnt += min(tmp, m);
        }
        if (cnt < k)
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << endl;
    return 0;
}