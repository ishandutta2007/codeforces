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

int n, k, d;
vector<int> g[1001];
int gc = 1;
int ans[1001][1001];

int main() {
    cin >> n >> k >> d;
    REP(i, n) g[0].pb(i);
    REP(day, d) {
        int gg = gc;
        REP(i, gg) {
            int c = 0;
            int del = 0;
            REP(j, g[i].size()) {
                int cur = j % k;
                if (cur > 0) {
                    g[gc + cur - 1].pb(g[i][j]);
                    ++del;
                    c = max(c, cur);
                } else
                    g[i][j - del] = g[i][j];
                ans[day][g[i][j]] = cur + 1;
            }
            g[i].resize((int)g[i].size() - del);
            gc += c;
        }
    }
    if (gc != n) {
        cout << -1 << '\n';
    } else {
        REP(day, d) {
            REP(i, n) cout << ans[day][i] << ' ';
            cout << '\n';
        }
    }
    return 0;
}