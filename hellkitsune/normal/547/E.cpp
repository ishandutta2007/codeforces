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

char s[400005];
int sa[400005], rev[400005];
LL sah[400005];
int len = 0, n, q;
int st[200001];
const char A = 'a' - 1;
int cnt[27];
const int MOD[2] = {1000000007, 1000000009};
const int MUL[2] = {41, 37};
int mul[2][400005];
int h[2][400005];
int ql[500000], qr[500000], ans[500000];
vector<int> kfrom[400005], kto[400005], kq[400005];
int fen[400005] = {};

void fenInc(int pos) {
    for (; pos < len; pos |= pos + 1)
        ++fen[pos];
}

int fenGet(int pos) {
    int ret = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
        ret += fen[pos];
    return ret;
}

bool cmp(const int &lhs, const int &rhs) {
    return sah[lhs] < sah[rhs];
}

void SASort() {
    REP(i, len) sa[i] = i;
    sort(sa, sa + len, cmp);
    LL pre = sah[sa[0]];
    sah[sa[0]] = 1;
    for (int i = 1; i < len; ++i) if (sah[sa[i]] == pre) {
        pre = sah[sa[i]];
        sah[sa[i]] = sah[sa[i - 1]];
    } else {
        pre = sah[sa[i]];
        sah[sa[i]] = sah[sa[i - 1]] + 1;
    }
}

void SABuild() {
    REP(i, len) sah[i] = s[i] - A + 1;
    SASort();
    for (int p = 1; p < len; p *= 2) {
        REP(i, len) {
            sah[i] *= len + 1;
            if (i + p < len) sah[i] += sah[i + p];
        }
        SASort();
    }
    REP(i, len) rev[sa[i]] = i;
}

int getHash(int ind, int from, int to) {
    LL ret = (h[ind][from] - (LL)h[ind][to] * mul[ind][to - from]) % MOD[ind];
    if (ret < 0) ret += MOD[ind];
    return (int)ret;
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &q);
    REP(i, n) {
        scanf("%s", s + len);
        st[i] = len;
        len += strlen(s + len) + 1;
        s[len - 1] = A;
    }
    st[n] = len;
    SABuild();
    REP(i, 2) {
        mul[i][0] = 1;
        for (int j = 1; j <= len; ++j)
            mul[i][j] = (mul[i][j - 1] * (LL)MUL[i]) % MOD[i];
    }
    REP(i, 2) {
        h[i][len] = 0;
        for (int j = len - 1; j >= 0; --j) {
            h[i][j] = (h[i][j + 1] * (LL)MUL[i] + s[j] - A + 3) % MOD[i];
        }
    }
    REP(k, n) {
        int kLen = st[k + 1] - st[k] - 1;
        int lo = 0, hi = rev[st[k]], mid;
        int curH[2] = {getHash(0, st[k], st[k] + kLen), getHash(1, st[k], st[k] + kLen)};
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            if (sa[mid] + kLen > len || getHash(0, sa[mid], sa[mid] + kLen) != curH[0] || getHash(1, sa[mid], sa[mid] + kLen) != curH[1])
                lo = mid + 1;
            else
                hi = mid;
        }
        kfrom[lo].pb(k);
        lo = rev[st[k]], hi = len - 1;
        while (lo < hi) {
            mid = (lo + hi + 1) >> 1;
            if (sa[mid] + kLen > len || getHash(0, sa[mid], sa[mid] + kLen) != curH[0] || getHash(1, sa[mid], sa[mid] + kLen) != curH[1])
                hi = mid - 1;
            else
                lo = mid;
        }
        kto[lo].pb(k);
    }
    REP(i, q) {
        int k;
        scanf("%d%d%d", ql + i, qr + i, &k), --ql[i], --qr[i], --k;
        ql[i] = st[ql[i]];
        qr[i] = st[qr[i] + 1] - st[k + 1] + st[k];
        kq[k].pb(i);
    }
    REP(i, len) {
        for (int k : kfrom[i]) for (int qn : kq[k]) {
            ans[qn] -= fenGet(qr[qn]) - fenGet(ql[qn] - 1);
        }
        fenInc(sa[i]);
        for (int k : kto[i]) for (int qn : kq[k]) {
            ans[qn] += fenGet(qr[qn]) - fenGet(ql[qn] - 1);
        }
    }
    REP(i, q) printf("%d\n", ans[i]);
    return 0;
}