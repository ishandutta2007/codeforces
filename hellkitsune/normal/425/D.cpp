#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <unordered_set>
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
vector<int> vx[100001], vy[100001];
unordered_set<int> sx[100001], sy[100001];
int x[100000], y[100000];

int main() {
    scanf("%d", &n);
    REP(i, n) {
        scanf("%d%d", x + i, y + i);
        vx[x[i]].pb(y[i]);
        vy[y[i]].pb(x[i]);
        sx[x[i]].insert(y[i]);
        sy[y[i]].insert(x[i]);
    }
    int ans = 0;
    REP(i, n) {
        if (vx[x[i]].size() < vy[y[i]].size()) {
            REP(e, vx[x[i]].size())
                if (vx[x[i]][e] > y[i] && sy[y[i]].count(x[i] + vx[x[i]][e] - y[i]) && sy[vx[x[i]][e]].count(x[i] + vx[x[i]][e] - y[i]))
                    ++ans;
        } else {
            REP(e, vy[y[i]].size())
                if (vy[y[i]][e] > x[i] && sx[x[i]].count(y[i] + vy[y[i]][e] - x[i]) && sx[vy[y[i]][e]].count(y[i] + vy[y[i]][e] - x[i]))
                    ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}