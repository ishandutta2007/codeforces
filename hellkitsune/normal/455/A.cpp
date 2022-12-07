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
LL a[100005] = {};
LL d[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) {
        int x;
        cin >> x;
        ++a[x];
    }
    d[0] = 0;
    d[1] = a[1];
    LL ans = a[1];
    for (int i = 2; i <= 100002; ++i) {
        d[i] = max(d[i - 1], d[i - 2] + a[i] * i);
        ans = max(ans, d[i]);
    }
    cout << ans << endl;
    return 0;
}