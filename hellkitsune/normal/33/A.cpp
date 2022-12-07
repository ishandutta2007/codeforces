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

int n, m, k;
int row[1000];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    REP(i, m) row[i] = 1e7;
    REP(i, n) {
        int r, c;
        scanf("%d%d", &r, &c), --r;
        row[r] = min(row[r], c);
    }
    int ans = 0;
    REP(i, m) ans += row[i];
    ans = min(ans, k);
    cout << ans << endl;
    return 0;
}