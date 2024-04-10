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

int n, t;
PII xx[1000];
int x[1000], a[1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> t, t <<= 1;
    REP(i, n) cin >> xx[i].first >> xx[i].second, xx[i].first <<= 1;
    sort(xx, xx + n);
    REP(i, n) x[i] = xx[i].first, a[i] = xx[i].second;
    int ans = 2;
    REP(i, n - 1) {
        if (x[i + 1] - x[i] - a[i + 1] - a[i] > t)
            ans += 2;
        else if (x[i + 1] - x[i] - a[i + 1] - a[i] == t)
            ++ans;
    }
    cout << ans << endl;
    return 0;
}