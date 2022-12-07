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
    int a, b, c, d;
    S(int a, int b, int c, int d) : a(a), b(b), c(c), d(d) {}
    S() {}
};

int a[4];
int d[15][15][15][15], e[15][15][15][15];
queue<S> q;

void tryMove(int a, int b, int c, int dd, int p, int qq) {
    if (d[a][b][c][dd] != -1) return;
    d[a][b][c][dd] = p;
    e[a][b][c][dd] = qq;
    q.push(S(a, b, c, dd));
}

vector<string> ans;

int main() {
    REP(i, 4) cin >> a[i];
    while (true) {
        bool ok = true;
        REP(i, 4) if (a[i] > 9) {
            int j = (i + 1) % 4;
            if (a[i] % 2 == 1) {
                ++a[i], ++a[j];
                printf("+%d\n", i + 1);
            }
            if (a[j] % 2 == 1) {
                int k = (j + 1) % 4;
                ++a[j], ++a[k];
                printf("+%d\n", j + 1);
            }
            a[i] /= 2, a[j] /= 2;
            printf("/%d\n", i + 1);
            ok = false;
            break;
        }
        if (ok) break;
    }
    memset(d, -1, sizeof d);
    d[a[0]][a[1]][a[2]][a[3]] = 2;
    q.push(S(a[0], a[1], a[2], a[3]));
    while (!q.empty()) {
        S s = q.front();
        q.pop();
        int a = s.a, b = s.b, c = s.c, d = s.d;
        if (a < 14 && b < 14) tryMove(a + 1, b + 1, c, d, 0, 1);
        if (b < 14 && c < 14) tryMove(a, b + 1, c + 1, d, 0, 2);
        if (c < 14 && d < 14) tryMove(a, b, c + 1, d + 1, 0, 3);
        if (d < 14 && a < 14) tryMove(a + 1, b, c, d + 1, 0, 4);
        if (!(a & 1) && !(b & 1)) tryMove(a >> 1, b >> 1, c, d, 1, 1);
        if (!(b & 1) && !(c & 1)) tryMove(a, b >> 1, c >> 1, d, 1, 2);
        if (!(c & 1) && !(d & 1)) tryMove(a, b, c >> 1, d >> 1, 1, 3);
        if (!(d & 1) && !(a & 1)) tryMove(a >> 1, b, c, d >> 1, 1, 4);
    }
    if (d[1][1][1][1] == -1) {
        printf("-1\n");
        return 0;
    }
    {
        int a, b, c, dd;
        a = b = c = dd = 1;
        while (d[a][b][c][dd] != 2) {
            char c1 = '+';
            if (d[a][b][c][dd]) c1 = '/';
            char c2 = '0' + e[a][b][c][dd];
            ans.pb(string(1, c1) + string(1, c2));
            if (c1 == '+') {
                if (c2 == '1') --a, --b;
                else if (c2 == '2') --b, --c;
                else if (c2 == '3') --c, --dd;
                else --dd, --a;
            } else {
                if (c2 == '1') a <<= 1, b <<= 1;
                else if (c2 == '2') b <<= 1, c <<= 1;
                else if (c2 == '3') c <<= 1, dd <<= 1;
                else dd <<= 1, a <<= 1;
            }
        }
    }
    for (int i = (int)ans.size() - 1; i >= 0; --i) {
        printf("%s\n", ans[i].c_str());
    }
    return 0;
}