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
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

LL n;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    int ans = 0;
    for (int i = 1; ; ++i) {
        LL k = ((LL)i * (i + 1));
        k += k >> 1;
        LL tmp = n - k + i;
        if (tmp < 0) break;
        if (tmp % 3 == 0) ++ans;
    }
    cout << ans << '\n';
    return 0;
}