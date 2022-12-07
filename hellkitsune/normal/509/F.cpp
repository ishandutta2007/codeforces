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
int a[500];
int d[501][501];

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> a[i];
    REP(i, n - 1) a[i] = a[i + 1];
    --n;
    if (n == 0) {
        cout << 1 << endl;
        return 0;
    }
    REP(i, n) d[i][i] = d[i + 1][i] = 1;
    for (int len = 2; len <= n; ++len) REP(i, n - len + 1) {
        int j = i + len - 1;
        d[i][j] = d[i + 1][j];
        for (int k = i + 1; k <= j; ++k) if (a[k] > a[i])
            d[i][j] = (d[i][j] + (LL)d[i + 1][k - 1] * d[k][j]) % MOD;
    }
    cout << d[0][n - 1] << endl;
    return 0;
}