#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int n, cnt = 0;
int s[100000];
unordered_map<int, int> ma;
set<int> se;
int re[100000];
vector<int> pos[100000];
LL _h[100001], *h, mul[100001];
vector<PII> v;

const LL P = 1e6 + 3;
const LL MOD = 1e12 + 39;
const LL MASK = (1 << 20) - 1;

inline void mult(LL &a, LL b) {
    a = ((((a * (b >> 20)) % MOD) << 20) + a * (b & MASK)) % MOD;
}

inline bool eqHash(int l1, int r1, int l2, int r2) {
    LL h1 = h[r1] - h[l1 - 1];
    if (h1 < 0) h1 += MOD;
    LL h2 = h[r2] - h[l2 - 1];
    if (h2 < 0) h2 += MOD;
    mult(h1, mul[l2 - l1]);
    return h1 == h2;
}

bool cmp(const PII &lhs, const PII &rhs) {
    if (lhs.second - lhs.first == rhs.second - rhs.first) {
        return lhs.first < rhs.first;
    }
    return lhs.second - lhs.first < rhs.second - rhs.first;
}

int main() {
    h = _h + 1;
    scanf("%d", &n);
    REP(i, n) scanf("%d", s + i);
    REP(i, n) se.insert(s[i]);
    foreach(e, se)
        re[cnt] = *e, ma[*e] = cnt++;
    REP(i, n) s[i] = ma[s[i]];
    se.clear();
    REP(i, n) pos[s[i]].pb(i);
    mul[0] = 1;
    h[-1] = 0;
    REP(i, n) {
        h[i] = (h[i - 1] + mul[i] * (s[i] + 37)) % MOD;
        mul[i + 1] = (mul[i] * P) % MOD;
    }
    REP(i, cnt) {
        REP(p, pos[i].size()) for (int q = p + 1; q < (int)pos[i].size(); ++q) {
            int pp = pos[i][p];
            int qq = pos[i][q];
            if ((qq << 1) - pp > n) break;
            if (eqHash(pp, qq - 1, qq, (qq << 1) - pp - 1))
                v.pb(mp(pp, qq));
        }
    }
    int ans = 0;
    sort(v.begin(), v.end());
    for (PII e : v) {
        if (e.first >= ans)
            ans = e.second;
    }
    printf("%d\n", n - ans);
    for (int i = ans; i < n; ++i)
        printf("%d ", re[s[i]]);
    printf("\n");
    return 0;
}