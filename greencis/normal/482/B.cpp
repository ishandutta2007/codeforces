#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int n,m;
int l[1000005],r[1000005],q[1000005];
int t[1000005],t2[1000005],a[1000005];

void push(int v) {
    if (t[v]) {
        t[v+v] |= t[v];
        t[v+v+1] |= t[v];
        t[v] = 0;
    }
}

void update(int v, int tl, int tr, int l, int r, int mask) {
    if (l > r) return;
    if (l == tl && r == tr) { t[v] |= mask; }
    else {
        push(v);
        int tm = (tl + tr) >> 1;
        update(v+v, tl, tm, l, min(r,tm), mask);
        update(v+v+1, tm+1, tr, max(l,tm+1), r, mask);
    }
}

int get(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr) return t[v];
    push(v);
    int tm = (tl + tr) >> 1;
    return get(v+v, tl, tm, l, min(r,tm)) | get(v+v+1, tm+1, tr, max(l,tm+1), r);
}

int get2(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0xFFFFFFFF;
    if (l == tl && r == tr) return t[v];
    int tm = (tl + tr) >> 1;
    return get2(v+v, tl, tm, l, min(r,tm)) & get2(v+v+1, tm+1, tr, max(l,tm+1), r);
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) >> 1;
        build(v+v, tl, tm);
        build(v+v+1, tm+1, tr);
        t[v] = t[v+v] & t[v+v+1];
    }
}

int main()
{
    for (int i = 0; i < 1000005; ++i)
        t2[i] = 0xFFFFFFFF;

    scanf("%d%d",&n,&m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d",&l[i],&r[i],&q[i]);
        update(1,0,n-1, l[i]-1, r[i]-1, q[i]);
    }

    for (int i = 0; i < n; ++i)
        a[i] = get(1,0,n-1,i,i);

    build(1,0,n-1);
    for (int i = 0; i < m; ++i) {
        if (get2(1,0,n-1,l[i]-1,r[i]-1) != q[i]) { puts("NO"); return 0; }
    }

    puts("YES");
    for (int i = 0; i < n; ++i) {
        printf("%d ",get(1,0,n-1,i,i));
    }

    return 0;
}