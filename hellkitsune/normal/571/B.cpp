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

int n, k;
int a[300005];
int sz, cnt0, cnt1;
LL d[5005][5005];
const LL INF = 1e18;

int main() {
    scanf("%d%d", &n, &k);
    REP(i, n) scanf("%d", a + i);
    sort(a, a + n);
    sz = n / k;
    cnt0 = cnt1 = 0;
    REP(i, k) {
        int s = (n - i + k - 1) / k;
        //assert(s == sz || s == sz + 1);
        if (s == sz) ++cnt0;
        else ++cnt1;
    }
    //assert(cnt0 * sz + cnt1 * (sz + 1) == n);
    REP(i, cnt0 + 1) REP(j, cnt1 + 1) d[i][j] = INF;
    d[0][0] = 0;
    REP(i, cnt0 + 1) REP(j, cnt1 + 1) {
        int pos = i * sz + j * (sz + 1);
        if (i != cnt0) {
            d[i + 1][j] = min(d[i + 1][j], d[i][j] + a[pos + sz - 1] - a[pos]);
        }
        if (j != cnt1) {
            d[i][j + 1] = min(d[i][j + 1], d[i][j] + a[pos + sz] - a[pos]);
        }
    }
    cout << d[cnt0][cnt1] << endl;
    return 0;
}