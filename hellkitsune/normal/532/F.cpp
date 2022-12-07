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

int n, m;
char s[200005], t[200005];
LL h[26] = {}, z[26] = {};
LL sub;
vector<int> ans;
int pos[26];
int q[26];

const LL MOD = 1e16 + 61;

int main() {
    scanf("%d%d%s%s", &n, &m, s, t);
    sub = 1;
    REP(i, m - 1) sub = (sub << 1) % MOD;
    REP(i, m) {
        REP(i, 26) h[i] = (h[i] << 1) % MOD;
        h[s[i] - 'a'] = (h[s[i] - 'a'] + 1) % MOD;
        REP(i, 26) z[i] = (z[i] << 1) % MOD;
        z[t[i] - 'a'] = (z[t[i] - 'a'] + 1) % MOD;
    }
    REP(i, 26) pos[i] = -1;
    REP(i, m) if (pos[t[i] - 'a'] == -1)
        pos[t[i] - 'a'] = i;
    for (int i = 0; i + m <= n; ++i) {
        REP(j, 26) q[j] = -1;
        bool flag = true;
        REP(j, 26) if (pos[j] != -1) {
            int sym = s[i + pos[j]] - 'a';
            if (q[sym] != -1) {
                flag = false;
                break;
            }
            q[sym] = j;
        }
        if (flag) REP(sym, 26) if (q[sym] != -1) {
            if (q[q[sym]] != sym) {
                if (q[q[sym]] == -1) {
                    q[q[sym]] = sym;
                } else {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) REP(j, 26) if (pos[j] != -1) {
            int sym = s[i + pos[j]] - 'a';
            if (h[sym] != z[j]) {
                flag = false;
                break;
            }
        }
        if (i + m != n) {
            h[s[i] - 'a'] = (h[s[i] - 'a'] - sub + MOD) % MOD;
            REP(j, 26) h[j] = (h[j] << 1) % MOD;
            h[s[i + m] - 'a'] = (h[s[i + m] - 'a'] + 1) % MOD;
        }
        if (flag) ans.pb(i + 1);
    }
    printf("%d\n", ans.size());
    REP(i, ans.size()) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}