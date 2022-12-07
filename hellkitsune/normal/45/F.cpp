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

struct S {
    int a, b, c;
    S(int a, int b, int c) : a(a), b(b), c(c) {}
    S() {}
};

int m, n, cur;
int d[2][3][100035];
set<int> se[2][3];
queue<S> q;

bool aCunningPlan() {
    return m - cur + 1 <= n;
}

int updVal;
void upd(int a, int b, int c) {
    if (d[a][b][c] == -1) {
        se[a][b].erase(c);
        d[a][b][c] = updVal;
        if (a != 1 || b != 0 || c != m) {
            q.push(S(a, b, c));
        }
    }
}

int main() {
    scanf("%d%d", &m, &n);
    REP(i, 2) REP(j, 3) REP(k, m + 1) d[i][j][k] = -1;
    d[0][0][0] = 0;
    q.push(S(0, 0, 0));
    REP(i, 2) REP(j, 3) REP(k, m + 1) if (i || j || k) se[i][j].insert(k);
    while (!q.empty()) {
        S s = q.front();
        q.pop();
        updVal = d[s.a][s.b][s.c] + 1;
        if (s.a == 0) {
            if (s.b == 0) {
                vector<int> v;
                for (auto it = se[1][0].lower_bound(s.c + 1); it != se[1][0].end() && *it <= min(s.c + n / 2, m); ++it) {
                    v.pb(*it);
                }
                for (int nc : v) upd(1, 0, nc);
                v.clear();
                if (m - s.c <= n) upd(1, 1, s.c);
                if (s.c == 0) {
                    for (auto it = se[1][2].lower_bound(s.c + 1); it != se[1][2].end() && *it <= min(s.c + n, m); ++it) {
                        v.pb(*it);
                    }
                    for (int nc : v) upd(1, 2, nc);
                }
            } else if (s.b == 1) {
                vector<int> v;
                for (auto it = se[1][1].lower_bound(s.c + 1); it != se[1][1].end() && *it <= min(s.c + n, m - 1); ++it) {
                    v.pb(*it);
                }
                for (int nc : v) upd(1, 1, nc);
                if (s.c + n >= m) upd(1, 0, m);
            } else {
                vector<int> v;
                for (auto it = se[1][2].lower_bound(s.c + 1); it != se[1][2].end() && *it <= min(s.c + n, m); ++it) {
                    v.pb(*it);
                }
                for (int nc : v) upd(1, 2, nc);
                if (m - s.c + m <= n) upd(1, 0, m);
                if (m <= n) upd(1, 1, m);
                if (s.c <= n) upd(1, 0, s.c);
            }
        } else {
            if (s.b == 0) {
                vector<int> v;
                for (auto it = se[0][0].lower_bound(max(0, s.c - n / 2)); it != se[0][0].end() && *it <= s.c - 1; ++it) {
                    v.pb(*it);
                }
                for (int nc : v) upd(0, 0, nc);
                if (s.c <= n) upd(0, 2, s.c);
            } else if (s.b == 1) {
                vector<int> v;
                for (auto it = se[0][1].lower_bound(max(0, s.c - n)); it != se[0][1].end() && *it <= s.c - 1; ++it) {
                    v.pb(*it);
                }
                for (int nc : v) upd(0, 1, nc);
                if (m - s.c <= n) upd(0, 0, s.c);
            } else {
                vector<int> v;
                for (auto it = se[0][2].lower_bound(max(1, s.c - n)); it != se[0][2].end() && *it <= s.c - 1; ++it) {
                    v.pb(*it);
                }
                for (int nc : v) upd(0, 2, nc);
            }
        }
    }
    printf("%d\n", d[1][0][m]);
    return 0;
}