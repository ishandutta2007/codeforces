#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <cassert>
#include <cstdlib>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back

typedef long long ll;
typedef long double ld;

const ll INF = 1e9;
const ll lINF = 1e18;

#ifdef DEBUG
#define dout(x) cerr<<x;
#else
#define dout(x)
#endif

using namespace std;

int n, a[111111], q;
int tree[450000][60];

void unite(int * v1, int * v2, int * res) {
    for (int i = 0; i < 60; i++) {
        res[i] = v1[i] + v2[(v1[i] + i)%60];
    }
}

void build(int vl, int vr, int v) {
    if (vr<=vl) {
        return;
    } else if (vr == vl+1) {
        for (int i = 0; i < 60; i++) {
            tree[v][i] = 1;
        }
        for (int i = 0; i < 60; i+=a[vl]) {
            tree[v][i] = 2;
        }
    } else {
        int mid = vl + vr;
        mid/=2;
        build(vl, mid, v*2);
        build(mid, vr, v*2+1);
        unite(tree[v*2], tree[v*2+1], tree[v]);
    }
}

int get(int start, int l, int r, int vl, int vr, int v) {
    if (l>=vr || r<=vl) {
        return 0;
    }
    else if (vl >= l && vr <= r) {
        return tree[v][start];
    } else {
        int mid = vl+vr;
        mid/=2;
        int t1 = get(start, l, r, vl, mid, v*2);
        return t1 + get((start + t1)%60, l, r, mid, vr, v*2+1);
    }
}

void upd(int i, int na, int vl, int vr, int v) {
    if (vr<=vl) return;
    if (vr == vl+1) {
        for (int i = 0; i < 60; i++) {
            tree[v][i] = 1;
        }
        for (int i = 0; i < 60; i+=na) {
            tree[v][i] = 2;
        }
    } else {
        int mid = vl + vr;
        mid/=2;
        if (i < mid) upd(i, na, vl, mid, v*2);
        else upd(i, na, mid, vr, v*2+1);
        unite(tree[v*2], tree[v*2+1], tree[v]);
    }
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    build(0, n, 1);
    cin >> q;
    for (int i = 0; i < q; i++) {
        char c;
        int x, y;
        scanf(" %c%d%d", &c, &x, &y);
        if (c=='A') {
            printf("%d\n", get(0, x-1, y-1, 0, n, 1));
        } else {
            upd(x-1, y, 0, n, 1);
        }
    }
    return 0;
}