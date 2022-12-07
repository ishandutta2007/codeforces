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

int n, m, k;
int a[1005], x;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    REP(i, m) cin >> a[i];
    cin >> x;
    int ans = 0;
    REP(i, m) {
        int y = x ^ a[i];
        y = __builtin_popcount(y);
        if (y <= k) ++ans;
    }
    cout << ans << endl;
    return 0;
}