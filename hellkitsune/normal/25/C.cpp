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

int n, k;
int d[300][300];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) REP(j, n) cin >> d[i][j];
    cin >> k;
    REP(query, k) {
        int a, b, c;
        cin >> a >> b >> c, --a, --b;
        if (d[a][b] > c) {
            d[a][b] = d[b][a] = c;
            REP(i, n) REP(j, n) {
                d[i][j] = min(d[i][j], d[i][a] + d[a][b] + d[b][j]);
                d[i][j] = min(d[i][j], d[i][b] + d[b][a] + d[a][j]);
            }
        }
        LL sum = 0;
        REP(i, n) for (int j = i + 1; j < n; ++j)
            sum += d[i][j];
        cout << sum << '\n';
    }
    return 0;
}