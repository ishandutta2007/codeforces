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

int n;
int a[100000];
const int INF = 1e9;

int main() {
    cin >> n;
    REP(i, n) cin >> a[i];
    sort(a, a + n, greater<int>());
    int pre = INF;
    LL ans = 0, side = -1;
    REP(i, n) {
        if (pre - a[i] <= 1) {
            pre = INF;
            if (side == -1) {
                side = a[i];
            } else {
                ans += side * a[i];
                side = -1;
            }
        } else {
            pre = a[i];
        }
    }
    cout << ans << endl;
    return 0;
}