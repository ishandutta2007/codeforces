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

string s[8];
int a[8];
int b[8];
int best = 16;

int main() {
    REP(i, 8) cin >> s[i];
    REP(i, 8) {
        a[i] = 0;
        REP(j, 8) if (s[i][j] == 'B')
            a[i] |= (1 << j);
    }
    REP(mask, (1 << 16) - 1) {
        int cur = 0;
        REP(i, 8) if (mask & (1 << i)) {
            ++cur;
            b[i] = 255;
        } else {
            b[i] = 0;
        }
        REP(i, 8) if (mask & (1 << (i + 8))) {
            ++cur;
            REP(j, 8) b[j] |= (1 << i);
        }
        bool flag = true;
        REP(i, 8) if (a[i] != b[i]) {
            flag = false;
            break;
        }
        if (flag) best = min(best, cur);
    }
    cout << best << endl;
    return 0;
}