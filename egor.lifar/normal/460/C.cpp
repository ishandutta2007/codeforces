#include <iostream>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <cmath>
#include <map>
#include <string.h>
#include <vector>


using namespace std;


int n, m, w;
int a[100000];
long long d[400001], t[400001];
int s = 1;


void push(int v) {
    d[v] += t[v];
    t[v * 2] += t[v] / 2;
    t[v * 2 + 1] += t[v] / 2;
    t[v] = 0;
}


void add(int l, int r, long long vl, long long vr, int v, long long x) {
    if (vr < l || r < vl) {
        return;
    }
    if (l <= vl && vr <= r) {
        t[v] += x * (vr - vl + 1);
        return;
    }
    push(v);
    add(l, r, vl, (vl + vr) / 2, v * 2, x);
    add(l, r, (vl + vr) / 2 + 1, vr, v * 2 + 1, x);
}


void change(int i, long long x) {
    d[i] = x;
    t[i] = 0;
    while (i / 2 >= 1) {
        i /= 2;
        t[i] = 0;
        d[i] = d[i * 2] + d[i * 2 + 1];
    }
}



long long getsum(int l, int r, int vl, int vr, int v) {
    if (r < vl || vr < l) {
        return 0;
    }
    if (l <= vl && vr <= r) {
        return d[v] + t[v];
    }
    push(v);
    return getsum(l, r, vl, (vl + vr) / 2, v * 2) + getsum(l, r, (vl + vr) / 2 + 1, vr, v * 2 + 1);
}


bool get(long long k) {
    long long t1 = 0;
    for (int i = 0; i < n; i++) {
        change(i + s, a[i]);
    }
    for (int i = 0; i < n; i++) {
        long long ans = getsum(i + 1, i + 1, 1, s, 1);
        if (ans < k) {
            t1 += k - ans;
            add(i + 1, i + w, 1, s, 1, k - ans);
        }
    }
    if (t1 > m) {
        return false;
    }
    return true;
}


int main() {
    cin >> n >> m >> w;
    while (s < n) {
        s *= 2;
    }
    long long r = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        r = max(r, (long long)(a[i] + m));
    }
    long long l = 1;
    while (l != r) {
        long long k = (l + r + 1) / 2;
        if (get(k)) {
            l = k;
        } else {
            r = k - 1;
        }
    }
    cout << l << endl;
    return 0;
}