#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>


using namespace std;


int n;
long long t[600002], d[600002];
int tt[200001];


void push(int v) {
    t[v] += d[v];
    d[v * 2] += d[v] / 2;
    d[v * 2 + 1] += d[v] / 2;
    d[v] = 0;
}


void add(int l, int r, int vl, int vr, int v, int x) {
    if (vl > r || vr < l) {
        return;
    }
    if (l <= vl && vr <= r) {
        d[v] += (vr - vl + 1) * x;
        return;
    }
    push(v);
    add(l, r, vl, (vl + vr) / 2, v * 2, x);
    add(l, r, (vl + vr) / 2 + 1, vr, v * 2 + 1, x);
    t[v] = t[v * 2] + d[v * 2] + t[v * 2 + 1] + d[v * 2 + 1];
}


int get(int l, int r, int vl, int vr, int v) {
    if (vl > r || vr < l) {
        return 0;
    }
    if (l <= vl && vr <= r) {
        return t[v] + d[v];
    }
    push(v);
    return get(l, r, vl, (vl + vr) / 2, v * 2) + get(l, r, (vl + vr) / 2 + 1, vr, v * 2 + 1);
}


int main() {
    cin >> n;
    int k = 1;
    while (k < 200000) {
        k *= 2;
    }
    int m = 1;
    for (int i = 0; i < n; i++) {
        cin >> tt[i];
        if (tt[i] == 1) {
            int a, x;
            cin >> a >> x;
            add(1, a, 1, k, 1, x);
        }
        if (tt[i] == 2) {
            int x;
            m++;
            cin >> x;
            add(m, m, 1, k, 1, x);
        }
        if (tt[i] == 3) {
            add(m, m, 1, k, 1, -(get(m, m, 1, k, 1)));
            m--;
        }
        printf("%.10lf\n", double(t[1] + d[1]) / double(m));
    }
    return 0;
}