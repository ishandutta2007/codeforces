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

const int bs = 4096;
char rbuf[bs + 2], wbuf[bs + 12];
int rpos = bs, wpos = 0;

inline char gch() {
    if (rpos == bs) cin.read(rbuf, bs), rpos = 0;
    return rbuf[rpos++];
}

inline int readInt() {
    char ch = gch();
    while (ch < '0' || ch > '9') ch = gch();
    int x = 0;
    while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = gch();
    return x;
}

inline void writeInt(int i, char c) {
    if (!i) wbuf[wpos++] = '0';
    else {
        int cnt = 0;
        while (i) {
            wbuf[wpos + cnt++] = i % 10 + '0';
            i /= 10;
        }
        reverse(wbuf + wpos, wbuf + wpos + cnt);
        wpos += cnt;
    }
    wbuf[wpos++] = c;
    if (wpos >= bs) {
        cout.write(wbuf, wpos);
        wpos = 0;
    }
}

int n, m, N;
int a[100800], cnt[100800], t[100800], lst[100800];
const int INF = 1e9;
int z, p, q;

void calc(int x) {
    int lo = x << 9, hi = (x + 1) << 9;
    for (int i = min(hi - 1, n - 1); i >= lo; --i) {
        int j = i + a[i];
        if (j >= n) {
            t[i] = -1;
            cnt[i] = 1;
            lst[i] = i;
        } else if (j >= hi) {
            t[i] = j;
            cnt[i] = 1;
            lst[i] = -1;
        } else {
            t[i] = t[j];
            cnt[i] = cnt[j] + 1;
            lst[i] = lst[j];
        }
    }
}

int main() {
    n = readInt(), m = readInt();
    REP(i, n) a[i] = readInt();
    for (int i = n; i < n + 600; ++i) a[i] = INF;
    N = n >> 9;
    if (n & 511) ++N;
    REP(i, N)
        calc(i);
    REP(query, m) {
        z = readInt();
        if (z == 0) {
            p = readInt() - 1, q = readInt();
            a[p] = q;
            calc(p >> 9);
        } else {
            p = readInt() - 1;
            int ans = 0, l = -1;
            while (p != -1) {
                ans += cnt[p];
                if (lst[p] != -1) l = lst[p];
                p = t[p];
            }
            writeInt(l + 1, ' ');
            writeInt(ans, '\n');
        }
    }
    if (wpos) cout.write(wbuf, wpos);
    return 0;
}