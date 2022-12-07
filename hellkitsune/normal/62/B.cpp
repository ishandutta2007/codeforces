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

int n, len;
string s[100000], z;
char t[200005];
int dif[26][100000];

int main() {
    scanf("%d%d", &n, &len);
    scanf("%s", t);
    z = string(t);
    REP(i, n) {
        scanf("%s", t);
        s[i] = string(t);
    }
    REP(c, 26) {
        int val = -1;
        REP(i, len) {
            if (z[i] == 'a' + c) {
                val = i;
            }
            if (val == -1) dif[c][i] = len;
            else dif[c][i] = i - val;
        }
        val = -1;
        for (int i = len - 1; i >= 0; --i) {
            if (z[i] == 'a' + c) {
                val = i;
            }
            if (val != -1) dif[c][i] = min(dif[c][i], val - i);
        }
    }
    REP(i, n) {
        LL ans = 0;
        int sz = (int)s[i].length();
        REP(j, s[i].length()) {
            int c = s[i][j] - 'a';
            if (j >= len) {
                if (dif[c][len - 1] == len) ans += sz;
                else ans += dif[c][len - 1] + j - len + 1;
            } else {
                if (dif[c][j] == len) ans += sz;
                else ans += dif[c][j];
            }
        }
        printf("%I64d\n", ans);
    }

    return 0;
}