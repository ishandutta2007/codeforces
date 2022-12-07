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

int t[1 << 20], tp[1 << 20];
const int off = 1 << 19;
int n;

void init_st() {
    REP(i, 1 << 20)
        t[i] = tp[i] = -1;
}

void update_st(int v, int L, int R, int l, int r, int val) {
    if (l > r) return;
    t[v] = max(t[v], val);
    if (l == L && r == R) {
        if (l != r) tp[v] = max(tp[v], val);
        return;
    }
    int mid = (L + R) >> 1;
    update_st(v << 1, L, mid, l, min(r, mid), val);
    update_st((v << 1) | 1, mid + 1, R, max(l, mid + 1), r, val);
}

int query_st(int v, int L, int R, int l, int r) {
    if (l > r) return -1;
    if (l == L && r == R) return t[v];
    int mid = (L + R) >> 1;
    if (tp[v] != -1) {
        t[v << 1] = max(t[v << 1], tp[v]);
        t[(v << 1) | 1] = max(t[(v << 1) | 1], tp[v]);
        if (L != R - 1) {
            tp[v << 1] = max(tp[v << 1], tp[v]);
            tp[(v << 1) | 1] = max(tp[(v << 1) | 1], tp[v]);
        }
    }
    return max(query_st(v << 1, L, mid, l, min(r, mid)),
               query_st((v << 1) | 1, mid + 1, R, max(l, mid + 1), r));
}

struct Lady {
    int a, b, c;
};

Lady l[500000];
map<int, int> ma;
set<int> se;

bool cmp(const Lady &lhs, const Lady &rhs) {
    return lhs.a > rhs.a;
}

int ans = 0;

int main() {
    init_st();
    scanf("%d", &n);
    REP(i, n) scanf("%d", &l[i].a);
    REP(i, n) scanf("%d", &l[i].b);
    REP(i, n) scanf("%d", &l[i].c);
    REP(i, n) se.insert(l[i].b);
    int cnt = 0;
    foreach(e, se) ma[*e] = cnt++;
    REP(i, n) l[i].b = ma[l[i].b];
    se.clear(); ma.clear();
    REP(i, n) se.insert(l[i].c);
    cnt = 0;
    foreach(e, se) ma[*e] = cnt++;
    REP(i, n) l[i].c = ma[l[i].c];
    se.clear(); ma.clear();
    sort(l, l + n, cmp);
    for (int i = 1; i < n; ++i) {
        if (l[i - 1].a != l[i].a) {
            for (int j = i - 1; j >= 0 && l[j].a == l[i - 1].a; --j)
                update_st(1, 0, off - 1, 0, l[j].b, l[j].c);
        }
        if (query_st(1, 0, off - 1, l[i].b + 1, off - 1) > l[i].c)
            ++ans;
    }
    printf("%d\n", ans);
    return 0;
}