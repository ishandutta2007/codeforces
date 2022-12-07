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

LL a[2000];
LL d;
int n;
LL ans = 0;

int main() {
    cin >> n >> d;
    REP(i, n) cin >> a[i];
    for (int i = 1; i < n; ++i) {
        if (a[i] <= a[i - 1]) {
            LL cur = (a[i - 1] - a[i]) / d + 1;
            ans += cur;
            a[i] += cur * d;
        }
    }
    cout << ans << endl;
    return 0;
}