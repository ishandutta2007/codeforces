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

string s[6], t[6];
string cur[30], best[30];
int besty = -1, cury, curx;
bool used[6] = {};
int len[6];
int cnt;

void go(int pos) {
    if (pos == 6) {
        REP(i, 6) len[i] = (int)t[i].length();
        if (len[0] + len[2] - 1 != len[1]) return;
        if (len[3] + len[5] - 1 != len[4]) return;
        if (t[0][0] != t[3][0]) return;
        if (t[0].back() != t[4][0]) return;
        if (t[1][0] != t[3].back()) return;
        if (t[1].back() != t[5][0]) return;
        if (t[2][0] != t[4].back()) return;
        if (t[2].back() != t[5].back()) return;
        if (t[1][len[0] - 1] != t[4][len[3] - 1]) return;
        cury = len[4];
        curx = len[1];
        REP(i, cury) cur[i].assign(curx, '.');
        REP(i, len[0]) cur[0][i] = t[0][i];
        REP(i, len[1]) cur[len[3] - 1][i] = t[1][i];
        REP(i, len[2]) cur[len[4] - 1][len[0] - 1 + i] = t[2][i];
        REP(i, len[3]) cur[i][0] = t[3][i];
        REP(i, len[4]) cur[i][len[0] - 1] = t[4][i];
        REP(i, len[5]) cur[len[3] - 1 + i][len[1] - 1] = t[5][i];
        bool ok = true, done = false;
        if (besty != -1) {
            int mn = min(besty, cury);
            REP(i, mn) if (best[i] < cur[i]) {
                ok = false;
                done = true;
                break;
            } else if (best[i] > cur[i]) {
                done = true;
                break;
            }
            if (!done && besty <= cury) {
                ok = false;
            }
        }
        if (ok) {
            besty = cury;
            REP(i, cury) best[i] = cur[i];
        }
        return;
    }
    REP(i, 6) if (!used[i]) {
        t[pos] = s[i];
        used[i] = true;
        go(pos + 1);
        used[i] = false;
    }
}

int main() {
    REP(i, 6) cin >> s[i];
    go(0);
    if (besty == -1) {
        cout << "Impossible" << endl;
    } else {
        REP(i, besty) cout << best[i] << endl;
    }
    return 0;
}