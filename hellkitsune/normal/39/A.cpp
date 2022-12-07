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
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int n, len, a;
char s[10005];
int mul[1000], ord[1000];
bool pre[1000];

inline bool cmp(const int &lhs, const int &rhs) {
    return mul[lhs] < mul[rhs];
}

int main() {
    scanf("%d%s", &a, s);
    len = strlen(s);
    n = 0;
    for (int beg = 0; beg < len; ) {
        int pos = beg;
        int sgn = 1;
        if (s[pos] == '+' || s[pos] == '-') {
            if (s[pos] == '-') sgn = -1;
            ++pos;
        }
        if (s[pos] >= '0' && s[pos] <= '9') {
            int val = 0;
            while (s[pos] != '*') {
                val = 10 * val + s[pos] - '0';
                ++pos;
            }
            ++pos;
            mul[n] = val * sgn;
        } else {
            mul[n] = sgn;
        }
        pre[n] = s[pos] == '+';
        ++n;
        beg = pos + 3;
    }
    REP(i, n) ord[i] = i;
    sort(ord, ord + n, cmp);
    LL ans = 0;
    REP(ii, n) {
        int i = ord[ii];
        if (pre[i]) ++a;
        ans += mul[i] * a;
        if (!pre[i]) ++a;
    }
    cout << ans << endl;
    return 0;
}