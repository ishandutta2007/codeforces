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

int n;
set<int> se;
map<int, int> ma;
int rev[200000];
int mac = 0;
int a[100000], b[100000];
int c[200000];
int fen[200000] = {};

void fenInc(int pos) {
    for (; pos < mac; pos |= pos + 1)
        ++fen[pos];
}

int fenGet(int pos) {
    int ret = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
        ret += fen[pos];
    return ret;
}

int cnt(int from, int to) {
    if (from > to) return 0;
    return to - from + 1 - (upper_bound(rev, rev + mac, to) - lower_bound(rev, rev + mac, from));
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d%d", a + i, b + i);
    REP(i, n) se.insert(a[i]), se.insert(b[i]);
    for (int x : se) ma[x] = mac, rev[mac++] = x;
    REP(i, n) a[i] = ma[a[i]], b[i] = ma[b[i]];
    REP(i, mac) c[i] = i;
    REP(i, n) swap(c[a[i]], c[b[i]]);
    LL ans = 0;
    for (int i = mac - 1; i >= 0; --i) {
        ans += fenGet(c[i] - 1);
        fenInc(c[i]);
    }
    REP(i, mac) if (c[i] != i)
        ans += cnt(min(rev[i], rev[c[i]]) + 1, max(rev[i], rev[c[i]]) - 1);
    cout << ans << endl;
    return 0;
}