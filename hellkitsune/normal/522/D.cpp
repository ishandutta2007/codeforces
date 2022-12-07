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

struct Node {
    int val;
    int l, r;
    Node(int val, int l = -1, int r = -1) : val(val), l(l), r(r) {}
    Node() {}
};

int n, m;
int a[500000], ri[500000];
map<int, int> ma;
int R = 1;
int rem[500000];

Node nodes[13000000];
int nc = 0;
int st[500000];

int buildSt(int l, int r) {
    if (l == r) {
        if (l < n && ri[l] < n) {
            nodes[nc] = Node(ri[l] - l);
        } else {
            nodes[nc] = Node(n);
        }
        return nc++;
    }
    int mid = (l + r) >> 1;
    int lNode = buildSt(l, mid);
    int rNode = buildSt(mid + 1, r);
    nodes[nc] = Node(min(nodes[lNode].val, nodes[rNode].val), lNode, rNode);
    return nc++;
}

int updateSt(int v, int l, int r, int pos) {
    if (l == r) {
        nodes[nc] = Node(n);
        return nc++;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) {
        int lNode = updateSt(nodes[v].l, l, mid, pos);
        int rNode = nodes[v].r;
        nodes[nc] = Node(min(nodes[lNode].val, nodes[rNode].val), lNode, rNode);
    } else {
        int lNode = nodes[v].l;
        int rNode = updateSt(nodes[v].r, mid + 1, r, pos);
        nodes[nc] = Node(min(nodes[lNode].val, nodes[rNode].val), lNode, rNode);
    }
    return nc++;
}

int querySt(int v, int L, int R, int l, int r) {
    if (l > r) return n;
    if (L == l && R == r) return nodes[v].val;
    int mid = (L + R) >> 1;
    return min(querySt(nodes[v].l, L, mid, l, min(r, mid)),
               querySt(nodes[v].r, mid + 1, R, max(l, mid + 1), r));
}

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) scanf("%d", a + i);
    for (int i = n - 1; i >= 0; --i) {
        auto it = ma.find(a[i]);
        if (it != ma.end()) {
            ri[i] = it->second;
        } else {
            ri[i] = n;
        }
        ma[a[i]] = i;
    }
    while (R < n) R *= 2;
    st[n - 1] = buildSt(0, R - 1);
    REP(i, n) rem[i] = -1;
    REP(i, n) if (ri[i] < n)
        rem[ri[i]] = i;
    for (int i = n - 2; i >= 0; --i) {
        st[i] = st[i + 1];
        if (rem[i + 1] != -1)
            st[i] = updateSt(st[i], 0, R - 1, rem[i + 1]);
    }
    REP(i, m) {
        int l, r;
        scanf("%d%d", &l, &r), --l, --r;
        int res = querySt(st[r], 0, R - 1, l, r);
        if (res >= n) res = -1;
        printf("%d\n", res);
    }
    return 0;
}