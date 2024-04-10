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
typedef long long LL;
typedef pair<int, int> PII;

int n, d;
PII a[100000];

int main() {
    scanf("%d%d", &n, &d);
    REP(i, n) scanf("%d%d", &a[i].first, &a[i].second);
    sort(a, a + n);
    LL ans = 0, cur = 0;
    int l = 0;
    REP(i, n) {
        cur += a[i].second;
        while (a[i].first - a[l].first >= d) {
            cur -= a[l].second;
            ++l;
        }
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0;
}