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

LL l, r;
LL d[2520][48][2], nd[2520][48][2];

LL solve(string s) {
    memset(d, 0, sizeof d);
    d[0][0][0] = 1;
    REP(ii, (int)s.length()) {
        memset(nd, 0, sizeof nd);
        REP(i, 2520) REP(j, 48) REP(dig, 10) if (d[i][j][0] || d[i][j][1]) {
            int newI = (10 * i + dig) % 2520;
            int newJ = j;
            if (dig == 2) {
                if (!(newJ & 3)) newJ |= 1;
            } else if (dig == 3) {
                if (!(newJ >> 4)) newJ |= 16;
            } else if (dig == 4) {
                if ((newJ & 3) < 2) newJ = ((newJ >> 2) << 2) | 2;
            } else if (dig == 5) {
                newJ |= 4;
            } else if (dig == 6) {
                if (!(newJ & 3)) newJ |= 1;
                if (!(newJ >> 4)) newJ |= 16;
            } else if (dig == 7) {
                newJ |= 8;
            } else if (dig == 8) {
                newJ |= 3;
            } else if (dig == 9) {
                newJ = 32 | (newJ & 15);
            }
            if (dig < s[ii] - '0') {
                nd[newI][newJ][1] += d[i][j][0] + d[i][j][1];
            } else if (dig == s[ii] - '0') {
                nd[newI][newJ][0] += d[i][j][0];
                nd[newI][newJ][1] += d[i][j][1];
            } else {
                nd[newI][newJ][1] += d[i][j][1];
            }
        }
        memcpy(d, nd, sizeof d);
    }
    LL ret = 0;
    REP(i, 2520) REP(j, 48) {
        if ((j & 3) == 1 && i % 2 != 0) continue;
        if ((j & 3) == 2 && i % 4 != 0) continue;
        if ((j & 3) == 3 && i % 8 != 0) continue;
        if ((j & 4) && i % 5 != 0) continue;
        if ((j & 8) && i % 7 != 0) continue;
        if ((j >> 4) == 1 && i % 3 != 0) continue;
        if ((j >> 4) == 2 && i % 9 != 0) continue;
        ret += d[i][j][0] + d[i][j][1];
    }
    return ret;
}

int main() {
    int tt;
    cin >> tt;
    REP(test, tt) {
        cin >> l >> r, --l;
        ostringstream ossL;
        ossL << l;
        LL ans = -solve(ossL.str());
        ostringstream ossR;
        ossR << r;
        ans += solve(ossR.str());
        cout << ans << endl;
    }
    return 0;
}