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

int n, k;
int f[2000];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    REP(i, n) cin >> f[i];
    sort(f, f + n, greater<int>());
    int flo = -1, cnt = 0;
    int ans = 0;
    REP(i, n) {
        if (cnt == 0) flo = f[i];
        if (++cnt == k) {
            cnt = 0;
            ans += (flo - 1) * 2;
        }
    }
    if (cnt) ans += (flo - 1) * 2;
    cout << ans << endl;
    return 0;
}