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

int d[1 << 24], prev[1 << 24];
int xs, ys, n;
int x[24], y[24];
const int INF = 1e9;
int dist[24];
int dist2[24][24];
int c[24], cc;

int main() {
    cin >> xs >> ys >> n;
    REP(i, n) cin >> x[i] >> y[i], x[i] -= xs, y[i] -= ys;
    REP(i, n) dist[i] = x[i] * x[i] + y[i] * y[i];
    REP(i, n) REP(j, n) dist2[i][j] = x[i] * x[i] + y[i] * y[i] + x[j] * x[j] + y[j] * y[j] + (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
    REP(i, 1 << n) d[i] = INF;
    d[0] = 0;
    REP(mask, (1 << n) - 1) {
        cc = 0;
        REP(i, n) if ((mask & (1 << i)) == 0) c[cc++] = i;
            int i = c[0];
            if (d[mask | (1 << i)] > d[mask] + (dist[i] << 1)) {
                d[mask | (1 << i)] = d[mask] + (dist[i] << 1);
                prev[mask | (1 << i)] = i | (35 << 10);
            }
            for (int q = 1; q < cc; ++q) {
                int j = c[q];
                if (d[mask | (1 << i) | (1 << j)] > d[mask] + dist2[i][j]) {
                    d[mask | (1 << i) | (1 << j)] = d[mask] + dist2[i][j];
                    prev[mask | (1 << i) | (1 << j)] = i | (j << 10);
                }
            }
    }
    int cur = (1 << n) - 1;
    cout << d[cur] << endl << "0";
    while (cur != 0) {
        int i = prev[cur] & 63;
        int j = prev[cur] >> 10;
        if (j == 35) cout << " " << i + 1 << " 0";
        else cout << " " << i + 1 << " " << j + 1 << " 0";
        cur ^= (1 << i);
        if (j != 35) cur ^= (1 << j);
    }
    cout << endl;
    return 0;
}