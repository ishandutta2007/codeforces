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

struct P {
    int x, y, z;
    P(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}
};

P p[8], c[8];
int d[8];

inline LL scal(P a, P b) {
    return (LL)a.x * b.x + (LL)a.y * b.y + (LL)a.z * b.z;
}

inline LL dist(P a, P b) {
    return (LL)(a.x - b.x) * (a.x - b.x) + (LL)(a.y - b.y) * (a.y - b.y) + (LL)(a.z - b.z) * (a.z - b.z);
}

void go(int v) {
    if (v == 8) {
        REP(i, 8) d[i] = 0;
        LL ddist = -1;
        REP(i, 8) {
            REP(j, 7) for (int k = j + 1; k < 8; ++k) if (i != j && i != k) {
                if (scal(P(c[j].x - c[i].x, c[j].y - c[i].y, c[j].z - c[i].z),
                        P(c[k].x - c[i].x, c[k].y - c[i].y, c[k].z - c[i].z)) == 0) {
                    LL cur1 = dist(c[i], c[j]);
                    LL cur2 = dist(c[i], c[k]);
                    if (cur1 != cur2 || cur1 == 0) continue;
                    ++d[i];
                    if (ddist == -1) ddist = cur1;
                    else if (ddist != cur1) return;
                }
            }
            if (d[i] != 3) return;
        }
        cout << "YES\n";
        REP(i, 8) cout << c[i].x << ' ' << c[i].y << ' ' << c[i].z << endl;
        exit(0);
    }
    c[v].x = p[v].x, c[v].y = p[v].y, c[v].z = p[v].z; go(v + 1);
    c[v].x = p[v].x, c[v].y = p[v].z, c[v].z = p[v].y; go(v + 1);
    c[v].x = p[v].y, c[v].y = p[v].x, c[v].z = p[v].z; go(v + 1);
    c[v].x = p[v].y, c[v].y = p[v].z, c[v].z = p[v].x; go(v + 1);
    c[v].x = p[v].z, c[v].y = p[v].x, c[v].z = p[v].y; go(v + 1);
    c[v].x = p[v].z, c[v].y = p[v].y, c[v].z = p[v].x; go(v + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    REP(i, 8) {
        int x, y, z;
        cin >> x >> y >> z;
        p[i] = P(x, y, z);
    }
    c[0] = p[0];
    go(1);
    cout << "NO" << endl;
    return 0;
}