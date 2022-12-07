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

LL d[25][4][25] = {};
int n, t;

int main() {
    cin >> n >> t;
    t *= 2;
    REP(i, 4) d[0][i][0] = 1;
    REP(i, n - 1) REP(j, 4) REP(k, t + 1) if (d[i][j][k]) {
        REP(q, 4) if (q > j) {
            if (k & 1) d[i + 1][q][k] += d[i][j][k];
            else d[i + 1][q][k + 1] += d[i][j][k];
        } else if (q < j && i) {
            if (k & 1) d[i + 1][q][k + 1] += d[i][j][k];
            else d[i + 1][q][k] += d[i][j][k];
        }
    }
    LL sum = 0;
    REP(i, 4) sum += d[n - 1][i][t];
    cout << sum << endl;
    return 0;
}