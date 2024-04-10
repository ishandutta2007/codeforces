#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <cmath>


using namespace std;



int n, m, k1, q;
int d[1000000][2];
int x1[200001], yy1[200001], x2[200001], y2[200001];


void change(int i, int t, int x) {
    d[i][t] = x;
    while (i / 2 > 0) {
        i /= 2;
        d[i][t] = min(d[i * 2][t], d[i * 2 + 1][t]);
    }
}



int rmq(int v, int t, int vl, int vr, int l, int r) {
    if (vl > r || vr < l) {
        return 1000000000;
    }
    if (l <= vl && vr <= r) {
        return d[v][t];
    }
    int vm = (vl + vr) / 2;
    return min(rmq(v * 2, t, vl, vm, l, r), rmq(v * 2 + 1, t, vm + 1, vr, l, r));
}


vector<int> v[200001], v1[200001];
vector<int> t[200001], t1[200001];
int good[200001];
int good1[200001];


int main() {
    cin >> n >> m >> k1 >> q;
    int ss = 1;
    while (ss < n || ss < m) {
        ss *= 2;
    }
    for (int i = 0; i < k1; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v1[y].push_back(x);
    }
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d %d", &x1[i], &yy1[i], &x2[i], &y2[i]);
        t[x2[i]].push_back(i);
        t1[y2[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (int)v[i].size(); j++) {
            change(ss + v[i][j] - 1, 1, i);
        }
        for (int j = 0; j < (int)t[i].size(); j++) {
            int k = t[i][j];
            int g = rmq(1, 1, 1, ss, yy1[k], y2[k]);
            if (g < x1[k]) {
                good[k] = true;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < (int)v1[i].size(); j++) {
            change(ss + v1[i][j] - 1, 0, i);
        }
        for (int j = 0; j < (int)t1[i].size(); j++) {
            int k = t1[i][j];
            int g = rmq(1, 0, 1, ss, x1[k], x2[k]);
            if (g < yy1[k]) {
                good1[k] = true;
            }
        }
    }
    for (int i = 0; i < q; i++) {
        if (!good[i] || !good1[i]) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}